#include "Configurator.hpp"
// Initialize Static Variables
AsyncWebServer *Configurator::server;
std::string Configurator::title;
std::string Configurator::md5_pwd;
std::string Configurator::FIRMWARE_VERSION = "v0.0.0";
Preferences *Configurator::preferences;
void Configurator::Init(string title_) // Runs AsyncWebServer and handles communication
{
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
    Configurator::server = new AsyncWebServer(80); // Server Constructor
    // Requests
    Configurator::server->on("/", HTTP_GET, [](AsyncWebServerRequest *request)
                             { request->send(SPIFFS, "/login.html", "text/html"); });
    Configurator::server->on("/title", HTTP_GET, [](AsyncWebServerRequest *request)
                             { request->send_P(200, "text/plain", Configurator::title.c_str()); });
    Configurator::server->on("/style.css", HTTP_GET, [](AsyncWebServerRequest *request)
                             { request->send(SPIFFS, "/style.css", "text/css"); });
    Configurator::server->on("/script.js", HTTP_GET, [](AsyncWebServerRequest *request)
                             { request->send(SPIFFS, "/script.js", "text/js"); });
    Configurator::server->on("/imgs/favicon.png", HTTP_GET, [](AsyncWebServerRequest *request)
                             { request->send(SPIFFS, "/imgs/favicon.png", "image/png"); });
    Configurator::server->on("/imgs/lock.png", HTTP_GET, [](AsyncWebServerRequest *request)
                             { request->send(SPIFFS, "/imgs/lock.png", "image/png"); });
    Configurator::server->on("/imgs/unlock.png", HTTP_GET, [](AsyncWebServerRequest *request)
                             { request->send(SPIFFS, "/imgs/unlock.png", "image/png"); });
    Configurator::server->on("/imgs/signal0.png", HTTP_GET, [](AsyncWebServerRequest *request)
                             { request->send(SPIFFS, "/imgs/signal0.png", "image/png"); });
    Configurator::server->on("/imgs/signal1.png", HTTP_GET, [](AsyncWebServerRequest *request)
                             { request->send(SPIFFS, "/imgs/signal1.png", "image/png"); });
    Configurator::server->on("/imgs/signal2.png", HTTP_GET, [](AsyncWebServerRequest *request)
                             { request->send(SPIFFS, "/imgs/signal2.png", "image/png"); });
    Configurator::server->on("/imgs/signal3.png", HTTP_GET, [](AsyncWebServerRequest *request)
                             { request->send(SPIFFS, "/imgs/signal3.png", "image/png"); });
    Configurator::server->on("/imgs/signal4.png", HTTP_GET, [](AsyncWebServerRequest *request)
                             { request->send(SPIFFS, "/imgs/signal4.png", "image/png"); });
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
        if(request->hasParam("ssid") && request->hasParam("pwd") && request->hasParam("mdp")){
            std::string ssid = (std::string)request->getParam("ssid")->value().c_str();
            std::string pwd = (std::string)request->getParam("pwd")->value().c_str();
            std::string md5 = (std::string)request->getParam("mdp")->value().c_str();
            WiFi.begin(ssid.c_str(), pwd.c_str());
            unsigned long startTime = millis();
            while(WiFi.status() != WL_CONNECTED && millis() - startTime < 2000) delay(100);
            if(WiFi.status() == WL_CONNECTED) request->send_P(200, "text/plain", "connected");
            else {request->send_P(200, "text/plain", "failure");Serial.println("Failed");}
        }else request->send_P(200, "text/plain", "failure"); });
    Configurator::server->on("/connected", HTTP_GET, [](AsyncWebServerRequest *request)
                             { request->send_P(200, "text/plain", WiFi.SSID().c_str()); });
    Configurator::server->on("/firmware_version", HTTP_GET, [](AsyncWebServerRequest *request)
                             { request->send_P(200, "text/plain", Configurator::FIRMWARE_VERSION.c_str()); });
    Configurator::server->on("/username", HTTP_GET, [](AsyncWebServerRequest *request)
                             { request->send_P(200, "text/plain", Configurator::ReadDataPrefs("username", "admin").c_str()); });
    Configurator::server->on("/disconnect", HTTP_GET, [](AsyncWebServerRequest *request)
                             {
        if(WiFi.status() == WL_CONNECTED) WiFi.disconnect();
        Serial.println("Disconnected"); });
    Configurator::server->on("/index", HTTP_GET, [](AsyncWebServerRequest *request)
                             {
        if(request->hasParam("mdp")){
            std::string md5 = (std::string)request->getParam("mdp")->value().c_str();
            if(Configurator::md5_pwd == md5) request->send(SPIFFS, "/index.html", "text/html");
            else request->send(SPIFFS, "/login.html", "text/html");
        }else request->send(SPIFFS, "/login.html", "text/html"); });
    Configurator::server->on("/prefs", HTTP_GET, [](AsyncWebServerRequest *request)
                             {
        if(request->hasParam("mdp")){
            std::string md5 = (std::string)request->getParam("mdp")->value().c_str();
            if(Configurator::md5_pwd == md5) request->send(SPIFFS, "/preferences.html", "text/html");
            else request->send(SPIFFS, "/login.html", "text/html");
        }else request->send(SPIFFS, "/login.html", "text/html"); });
    Configurator::server->on("/wifiscan", HTTP_GET, [](AsyncWebServerRequest *request)
                             { request->send_P(200, "text/plain", Configurator::GetNetworks().c_str()); });
    Configurator::server->on("/update", HTTP_GET, [](AsyncWebServerRequest *request)
                             {
        if(request->hasParam("mdp") && request->hasParam("key") && request->hasParam("value")){
            std::string md5 = (std::string)request->getParam("mdp")->value().c_str();
            std::string key = (std::string)request->getParam("key")->value().c_str();
            std::string value = (std::string)request->getParam("value")->value().c_str();

            if(md5 == Configurator::md5_pwd){
                if(key == "username") Configurator::WriteDataPrefs("username", value);
                if(key == "userpassword") Configurator::WriteDataPrefs("password", value);
                if(key == "ap_password") Configurator::WriteDataPrefs("ap_password", value);
                if(key == "reload") Configurator::md5_pwd = "";
            }
        } });
    Configurator::server->on("/reset", HTTP_GET, [](AsyncWebServerRequest *request)
                             { Configurator::md5_pwd = ""; });
    Configurator::server->begin(); // Start Server
}
std::string Configurator::GetNetworks()
{
    esp_task_wdt_reset();
    vector<std::string> ssids;
    int16_t n = -1;
    if (WiFi.status() != WL_NO_SSID_AVAIL)
    {
        n = 0;
        do
        {
            n = WiFi.scanNetworks(true);
            do
            {
                n = WiFi.scanComplete(); // Returns number of networks
                esp_task_wdt_reset();    // Resets watchdog timer so program won' t break
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
    std::string result = "";
    for (std::string ssid : ssids) // Formatting to String like <|SPLITTER|>network<|RSSI|>signal...
    {
        if (ssid != "")
            result = result + (std::string) "<|SPLITTER|>" + ssid;
    }
    Configurator::ReplaceAll(result, "<|SPLITTER|><|SPLITTER|>", "<|SPLITTER|>"); // Fixes empty networks
    return n <= 0 ? "None" : result;                                              // Returns none or parsed string
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