#include "Configurator.hpp"

// Initialize Static Variables
AsyncWebServer *Configurator::server;
esp32FOTA *Configurator::updateHandler;
std::string Configurator::title;
std::string Configurator::md5_pwd;
bool Configurator::login;
int Configurator::FIRMWARE_VERSION = 0;
Preferences *Configurator::preferences;
bool Configurator::scanning = false;
TaskHandle_t Configurator::scanTaskHandler;
TaskHandle_t Configurator::updateTaskHandler;
TaskHandle_t Configurator::connectTaskHandler;
SemaphoreHandle_t Configurator::scanSemaphoreHandle;
SemaphoreHandle_t Configurator::sendScanSemaphoreHandle;
SemaphoreHandle_t Configurator::updateSemaphoreHandle;
SemaphoreHandle_t Configurator::connectSemaphoreHandle;
SemaphoreHandle_t Configurator::connectedSemaphoreHandle;
std::string Configurator::STATUS = "IDLE";
std::string Configurator::networks_string = "";
std::string Configurator::FOTA_URL = "";
std::string Configurator::ssid_c = "";
std::string Configurator::pass_c = "";
void Configurator::Init(string title_, bool login_, std::string FOTA_URL_) // Runs AsyncWebServer and handles communication
{
    Configurator::scanSemaphoreHandle = xSemaphoreCreateBinary();
    Configurator::sendScanSemaphoreHandle = xSemaphoreCreateBinary();
    Configurator::updateSemaphoreHandle = xSemaphoreCreateBinary();
    Configurator::connectSemaphoreHandle = xSemaphoreCreateBinary();
    Configurator::connectedSemaphoreHandle = xSemaphoreCreateBinary();
    if (Configurator::scanSemaphoreHandle == NULL)
        Serial.println("Failed to create scan Semaphore");
    if (Configurator::sendScanSemaphoreHandle == NULL)
        Serial.println("Failed to create send Semaphore");
    if (Configurator::updateSemaphoreHandle == NULL)
        Serial.println("Failed to create update Semaphore");
    if (Configurator::connectSemaphoreHandle == NULL)
        Serial.println("Failed to create connect Semaphore");
    if (Configurator::connectedSemaphoreHandle == NULL)
        Serial.println("Failed to create connected Semaphore");
    xSemaphoreTake(Configurator::scanSemaphoreHandle, 0);
    xSemaphoreTake(Configurator::sendScanSemaphoreHandle, 0);
    xSemaphoreTake(Configurator::updateSemaphoreHandle, 0);
    xSemaphoreTake(Configurator::connectSemaphoreHandle, 0);
    xSemaphoreTake(Configurator::connectedSemaphoreHandle, 0);
    Configurator::FOTA_URL = FOTA_URL_;
    Configurator::md5_pwd = login_ ? "" : "null";
    Configurator::login = login_;
    Configurator::preferences = new Preferences(); // Flash Data
    Configurator::title = title_;
    IPAddress localIP(192, 168, 4, 22); // Configuring ip that can be accessed on AP mode
    IPAddress gateway(192, 168, 4, 9);
    IPAddress subnet(255, 255, 255, 0);
    WiFi.mode(WIFI_AP_STA);
    WiFi.disconnect();
    WiFi.softAPConfig(localIP, gateway, subnet);                                                                                 // Configure AP
    WiFi.softAP((String("ESP32 ") + WiFi.macAddress()).c_str(), Configurator::ReadDataPrefs("ap_password", "rootroot").c_str()); // Starts AP
    if (!SPIFFS.begin())                                                                                                         // WebServer files
    {
        Serial.println("Failed to mount device filesystem"); // Failed
    }
    xTaskCreate(&Configurator::ScanTaskCode, "scan_task", 2048, NULL, 1, &Configurator::scanTaskHandler);
    xTaskCreate(&Configurator::UpdateFirmware, "update_task", 3072, NULL, 1, &Configurator::updateTaskHandler);
    xTaskCreate(&Configurator::ConnectTaskCode, "connect_task", 3072, NULL, 1, &Configurator::connectTaskHandler);
    Configurator::updateHandler = new esp32FOTA("esp32-fota-http", Configurator::FIRMWARE_VERSION);
    Configurator::updateHandler->checkURL = Configurator::FOTA_URL.c_str();
    Configurator::server = new AsyncWebServer(80); // Server Constructor
    // Requests
    Configurator::server->on("/", HTTP_GET, [](AsyncWebServerRequest *request)
                             { 
                                if(Configurator::login) request->send(SPIFFS, "/login.html", "text/html");
                                else request->send(SPIFFS, "/index.html", "text/html"); });
    Configurator::server->on("/title", HTTP_GET, [](AsyncWebServerRequest *request)
                             { request->send_P(200, "text/plain", Configurator::title.c_str()); });
    Configurator::server->on("/style.css", HTTP_GET, [](AsyncWebServerRequest *request)
                             { request->send(SPIFFS, "/style.css", "text/css"); });
    Configurator::server->on("/script.js", HTTP_GET, [](AsyncWebServerRequest *request)
                             { request->send(SPIFFS, "/script.js", "text/js"); });
    Configurator::server->on("/imgs/favicon.png", HTTP_GET, [](AsyncWebServerRequest *request)
                             { request->send(SPIFFS, "/imgs/favicon.png", "image/png"); });
    Configurator::server->on("/imgs/lock.svg", HTTP_GET, [](AsyncWebServerRequest *request)
                             { request->send(SPIFFS, "/imgs/lock.svg", "image/svg"); });
    Configurator::server->on("/imgs/unlock.svg", HTTP_GET, [](AsyncWebServerRequest *request)
                             { request->send(SPIFFS, "/imgs/unlock.svg", "image/svg"); });
    Configurator::server->on("/imgs/signal0.svg", HTTP_GET, [](AsyncWebServerRequest *request)
                             { request->send(SPIFFS, "/imgs/signal0.svg", "image/svg"); });
    Configurator::server->on("/imgs/signal1.svg", HTTP_GET, [](AsyncWebServerRequest *request)
                             { request->send(SPIFFS, "/imgs/signal1.svg", "image/svg"); });
    Configurator::server->on("/imgs/signal2.svg", HTTP_GET, [](AsyncWebServerRequest *request)
                             { request->send(SPIFFS, "/imgs/signal2.svg", "image/svg"); });
    Configurator::server->on("/imgs/signal3.svg", HTTP_GET, [](AsyncWebServerRequest *request)
                             { request->send(SPIFFS, "/imgs/signal3.svg", "image/svg"); });
    Configurator::server->on("/imgs/signal4.svg", HTTP_GET, [](AsyncWebServerRequest *request)
                             { request->send(SPIFFS, "/imgs/signal4.svg", "image/svg"); });
    Configurator::server->on("/login", HTTP_GET, [](AsyncWebServerRequest *request) // Handles Login
                             {
        if(request->hasParam("uname") && request->hasParam("pwd")){
            std::string uname = (std::string)request->getParam("uname")->value().c_str();
            std::string pwd = (std::string)request->getParam("pwd")->value().c_str();
            std::string md5 = (std::string)request->getParam("mdp")->value().c_str();
            if (uname == Configurator::ReadDataPrefs("username", "admin") && pwd == Configurator::ReadDataPrefs("password", "admin"))
            {request->send_P(200, "text/plain", "success");Configurator::md5_pwd = md5;}
            else request->send_P(200, "text/plain", "failure");
        }else request->send_P(200, "text/plain", "failure"); });
    Configurator::server->on("/connect", HTTP_GET, [](AsyncWebServerRequest *request)
                             {
        if(Configurator::login && request->hasParam("mdp")){                        
            if(request->hasParam("ssid") && request->hasParam("pwd")){
                std::string ssid = (std::string)request->getParam("ssid")->value().c_str();
                std::string pwd = (std::string)request->getParam("pwd")->value().c_str();
                std::string md5 = (std::string)request->getParam("mdp")->value().c_str();
                Configurator::ssid_c = ssid;
                Configurator::pass_c = pwd;
                WiFi.begin(ssid.c_str(), pwd.c_str());
                unsigned long startTime = millis();
                while(WiFi.status() != WL_CONNECTED && millis() - startTime < 5000)
                {
                    esp_task_wdt_reset();
                    delay(50);
                }
                if(WiFi.status() == WL_CONNECTED)
                {
                    request->send_P(200, "text/plain", "connected");
                }
                else {request->send_P(200, "text/plain", "failure");Serial.println("Failed");}
            }else request->send_P(200, "text/plain", "failure");
        }
        else if(!Configurator::login){
            if(request->hasParam("ssid") && request->hasParam("pwd")){
                std::string ssid = (std::string)request->getParam("ssid")->value().c_str();
                std::string pwd = (std::string)request->getParam("pwd")->value().c_str();
                Configurator::ssid_c = ssid;
                Configurator::pass_c = pwd;
                xSemaphoreGive(Configurator::connectSemaphoreHandle);
                while (!xSemaphoreTake(Configurator::connectedSemaphoreHandle, 0))
                {
                    esp_task_wdt_reset();
                    delay(100);
                }
                if(WiFi.status() == WL_CONNECTED) request->send_P(200, "text/plain", "connected");
                else request->send_P(200, "text/plain", "failure");
            }else request->send_P(200, "text/plain", "failure"); 
        } });
    Configurator::server->on("/loginreq", HTTP_GET, [](AsyncWebServerRequest *request)
                             { request->send_P(200, "text/plain", Configurator::login ? "true" : "false"); });
    Configurator::server->on("/connected", HTTP_GET, [](AsyncWebServerRequest *request)
                             { request->send_P(200, "text/plain", WiFi.SSID().c_str()); });
    Configurator::server->on("/firmware_version", HTTP_GET, [](AsyncWebServerRequest *request)
                             { request->send_P(200, "text/plain", std::to_string(Configurator::FIRMWARE_VERSION).c_str()); });
    Configurator::server->on("/username", HTTP_GET, [](AsyncWebServerRequest *request)
                             { request->send_P(200, "text/plain", Configurator::ReadDataPrefs("username", "admin").c_str()); });
    Configurator::server->on("/updating", HTTP_GET, [](AsyncWebServerRequest *request)
                             { request->send_P(200, "text/plain", Configurator::STATUS == "UPDATING" ? "true" : Configurator::STATUS == "REBOOTING" ? "rebooting"
                                                                                                            : Configurator::STATUS == "A_REBOOT"    ? "a_reboot"
                                                                                                                                                    : "false"); });
    Configurator::server->on("/search", HTTP_GET, [](AsyncWebServerRequest *request)
                             { Serial.println(Configurator::scanning);request->send_P(200, "text/plain", Configurator::scanning ? "scanning" : "not"); });
    Configurator::server->on("/disconnect", HTTP_GET, [](AsyncWebServerRequest *request)
                             {
        if(WiFi.status() == WL_CONNECTED) WiFi.disconnect(); });
    Configurator::server->on("/index", HTTP_GET, [](AsyncWebServerRequest *request)
                             {
        if(!Configurator::login){
            request->send(SPIFFS, "/index.html", "text/html");
        }
        else if(request->hasParam("mdp") && Configurator::login){
            std::string md5 = (std::string)request->getParam("mdp")->value().c_str();
            if(Configurator::md5_pwd == md5) request->send(SPIFFS, "/index.html", "text/html");
            else request->send(SPIFFS, "/login.html", "text/html");
        }else request->send(SPIFFS, "/login.html", "text/html"); });
    Configurator::server->on("/prefs", HTTP_GET, [](AsyncWebServerRequest *request)
                             {
        if(!Configurator::login){
            request->send(SPIFFS, "/preferences.html", "text/html");
        }
        else if(request->hasParam("mdp") && Configurator::login){
            std::string md5 = (std::string)request->getParam("mdp")->value().c_str();
            if(Configurator::md5_pwd == md5) request->send(SPIFFS, "/preferences.html", "text/html");
            else request->send(SPIFFS, "/login.html", "text/html");
        }else request->send(SPIFFS, "/login.html", "text/html"); });
    Configurator::server->on("/wifiscan", HTTP_GET, [](AsyncWebServerRequest *request)
                             { request->send_P(200, "text/plain", Configurator::GetNetworks().c_str()); });
    Configurator::server->on("/update_firmware", HTTP_GET, [](AsyncWebServerRequest *request)
                             { 
                                //TO-DO
                                int update = 1;
                                if(WiFi.status() != WL_CONNECTED) update = -1;
                                else if(Configurator::NewestFirmware()) update = 0;
                                else xSemaphoreGive(Configurator::updateSemaphoreHandle);
                                request->send_P(200, "text/plain", update == 1 ? "update" : update == 0 ? "e_installed" : update == -1 ? "e_wifi" : "nan"); });
    Configurator::server->on("/update", HTTP_GET, [](AsyncWebServerRequest *request)
                             {
        if(request->hasParam("mdp") && request->hasParam("key") && request->hasParam("value")){
            std::string md5 = (std::string)request->getParam("mdp")->value().c_str();
            std::string key = (std::string)request->getParam("key")->value().c_str();
            std::string value = (std::string)request->getParam("value")->value().c_str();

            if(md5 == Configurator::md5_pwd){
                if(key == "username" && Configurator::login) Configurator::WriteDataPrefs("username", value);
                if(key == "userpassword" && Configurator::login) Configurator::WriteDataPrefs("password", value);
                if(key == "ap_password") Configurator::WriteDataPrefs("ap_password", value);
                if(key == "reload" && Configurator::login) Configurator::md5_pwd = "";
            }
        } });
    Configurator::server->on("/reset", HTTP_GET, [](AsyncWebServerRequest *request)
                             { Configurator::md5_pwd = ""; });
    Configurator::server->on("/connectedBar", HTTP_GET, [](AsyncWebServerRequest *request)
                             { 
        std::string name = "";
        name = (std::string)((char *)(WiFi.SSID().c_str()));
        if (name != "") name = name + "<|RSSI|>" + std::to_string((int)WiFi.RSSI());
        request->send_P(200, "text/plain", name.c_str()); });
    Configurator::server->begin(); // Start Server
}
std::string Configurator::GetNetworks()
{
    xSemaphoreGive(Configurator::scanSemaphoreHandle);
    while (!xSemaphoreTake(Configurator::sendScanSemaphoreHandle, 0))
    {
        esp_task_wdt_reset();
        delay(100);
    }
    return Configurator::networks_string; // Returns none or parsed string
}
void Configurator::ReplaceAll(std::string &str, const std::string &from, const std::string &to)
{
    if (from.empty())
        return;
    size_t start_pos = 0;
    while ((start_pos = str.find(from, start_pos)) != std::string::npos)
    {
        str.replace(start_pos, from.length(), to);
        start_pos += to.length(); // In case 'to' contains 'from', like replacing 'x' with 'yx'
    }
}
std::string Configurator::ReadDataPrefs(std::string key, std::string defaultval) // Reads Data from flash
{
    Configurator::preferences->begin("credentials_", false);
    std::string result = (std::string)Configurator::preferences->getString(key.c_str(), String(defaultval.c_str())).c_str();
    Configurator::preferences->end();
    return result;
}
void Configurator::WriteDataPrefs(std::string key, std::string data) // Writes Data to a flash
{
    Configurator::preferences->begin("credentials_", false);
    Configurator::preferences->putString(key.c_str(), String(data.c_str()));
    Configurator::preferences->end();
}
void Configurator::Deinit()
{
    Configurator::server->end();
    WiFi.disconnect();
    WiFi.softAPdisconnect(true);
    Configurator::md5_pwd = "";
    vTaskDelete(Configurator::scanTaskHandler);
    vTaskDelete(Configurator::updateTaskHandler);
}
void Configurator::ScanTaskCode(void *vpPrarameter)
{
    while (true)
    {
        if (xSemaphoreTake(Configurator::scanSemaphoreHandle, 0))
        {
            vector<std::string> ssids;
            int16_t n = -1;

            if (WiFi.status() != WL_NO_SSID_AVAIL)
            {
                Configurator::scanning = true;
                n = 0;
                do
                {
                    n = WiFi.scanNetworks(true);
                    do
                    {
                        n = WiFi.scanComplete(); // Returns number of networks
                        delay(50);
                    } while (n == -1);
                } while (n == -2);
                n = n < 0 ? 0 : n;          // Fixes n to 0 if n is lower than 0
                for (int i = 0; i < n; i++) // Formatting to SSID Array like network<|RSSI|>signal
                {
                    std::string name = "";
                    name = (std::string)((char *)(WiFi.SSID(i).c_str()));
                    if (name != "")
                        ssids.push_back(name + "<|RSSI|>" + std::to_string((int)WiFi.RSSI(i)));
                }
            }
            Configurator::scanning = false;
            std::string result = "";
            for (std::string ssid : ssids) // Formatting to String like <|SPLITTER|>network<|RSSI|>signal...
            {
                if (ssid != "")
                    result = result + (std::string) "<|SPLITTER|>" + ssid;
            }
            Configurator::ReplaceAll(result, "<|SPLITTER|><|SPLITTER|>", "<|SPLITTER|>"); // Fixes empty networks
            Configurator::networks_string = n <= 0 ? "" : result;
            xSemaphoreGive(Configurator::sendScanSemaphoreHandle);
        }
        // vTaskDelay(1000 / portTICK_PERIOD_MS);
    }
}
void Configurator::UpdateFirmware(void *vpParameters)
{
    while (true)
    {
        if (xSemaphoreTake(Configurator::updateSemaphoreHandle, 0))
        {
            Configurator::STATUS = "UPDATING";
            disableCore0WDT();
            disableCore1WDT();
            Configurator::updateHandler->execOTA();
            Serial.println("Updating");
        }
        delay(50);
    }
}
void Configurator::ConnectTaskCode(void *vpParameters)
{
    while (true)
    {
        if (xSemaphoreTake(Configurator::connectSemaphoreHandle, 0))
        {
            WiFi.begin(Configurator::ssid_c.c_str(), Configurator::pass_c.c_str());
            unsigned long startTime = millis();
            while (WiFi.status() != WL_CONNECTED && millis() - startTime < 5000)
            {
                esp_task_wdt_reset();
                delay(50);
            }
            xSemaphoreGive(Configurator::connectedSemaphoreHandle);
        }
        delay(50);
    }
}
bool Configurator::NewestFirmware()
{
    return !Configurator::updateHandler->execHTTPcheck();
}