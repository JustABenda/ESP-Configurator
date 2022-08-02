#include "Configurator.hpp"

AsyncWebServer *Configurator::server;
std::string Configurator::title;
std::string Configurator::md5_pwd;
std::string Configurator::FIRMWARE_STRING = "v0.0.0";
Preferences *Configurator::preferences;
void Configurator::Init(string title_)
{
    Configurator::title = title_;
    IPAddress localIP(192, 168, 4, 22);
    IPAddress gateway(192, 168, 4, 9);
    IPAddress subnet(255, 255, 255, 0);
    WiFi.mode(WIFI_AP_STA);
    WiFi.disconnect();
    WiFi.softAPConfig(localIP, gateway, subnet);
    std::string ap_password = std::string("rootroot");
    WiFi.softAP((String("ESP32 ") + WiFi.macAddress()).c_str(), ap_password.c_str());
    if (!SPIFFS.begin())
    {
        Serial.println("Failed to mount device filesystem");
    }
    Configurator::server = new AsyncWebServer(80);
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
    Configurator::server->on("/login", HTTP_GET, [](AsyncWebServerRequest *request)
                             {
        if(request->hasParam("uname") && request->hasParam("pwd")){
            String _uname = request->getParam("uname")->value();
            String _pwd = request->getParam("pwd")->value();
            String _pwd_md5 = request->getParam("mdp")->value();
            char *key_ = (char*)(_uname.c_str());
            char *value_ = (char*)(_pwd.c_str());
            char *pwd_md5_ = (char*)(_pwd_md5.c_str());
            std::string uname;
            std::string pwd;
            std::string md5;
            uname = (std::string)key_;
            pwd = (std::string)value_;
            md5 = (std::string)pwd_md5_;  
            if(uname == (std::string)"user" && pwd == (std::string)"pwd") {request->send_P(200, "text/plain", "success");Configurator::md5_pwd = md5;}
            else request->send_P(200, "text/plain", "failure");
        }else request->send_P(200, "text/plain", "failure"); });
    Configurator::server->on("/connect", HTTP_GET, [](AsyncWebServerRequest *request)
                             {
        if(request->hasParam("ssid") && request->hasParam("pwd") && request->hasParam("mdp")){
            String _ssid = request->getParam("ssid")->value();
            String _pwd = request->getParam("pwd")->value();
            std::string md5 = (std::string)request->getParam("mdp")->value().c_str();
            char *ssid_ = (char*)(_ssid.c_str());
            char *value_ = (char*)(_pwd.c_str());
            std::string ssid;
            std::string pwd;
            ssid = (std::string)ssid_;
            pwd = (std::string)value_;
            WiFi.begin(ssid.c_str(), pwd.c_str());
            unsigned long startTime = millis();
            while(WiFi.status() != WL_CONNECTED && millis() - startTime < 2000) delay(100);
            if(WiFi.status() == WL_CONNECTED) request->send_P(200, "text/plain", "connected");
            else {request->send_P(200, "text/plain", "failure");Serial.println("Failed");}
        }else request->send_P(200, "text/plain", "failure"); });
    Configurator::server->on("/connected", HTTP_GET, [](AsyncWebServerRequest *request)
                             { request->send_P(200, "text/plain", WiFi.SSID().c_str()); });
    Configurator::server->on("/username", HTTP_GET, [](AsyncWebServerRequest *request)
                             { request->send_P(200, "text/plain", "user"); });
    Configurator::server->on("/disconnect", HTTP_GET, [](AsyncWebServerRequest *request)
                             {
        if(WiFi.status() == WL_CONNECTED) WiFi.disconnect();
        Serial.println("Disconnected"); });
    Configurator::server->on("/index", HTTP_GET, [](AsyncWebServerRequest *request)
                             {
        if(request->hasParam("mdp")){
            String _md5 = request->getParam("mdp")->value();
            char *md5_ = (char*)(_md5.c_str());
            std::string md5;
            md5 = (std::string)md5_;
            if(Configurator::md5_pwd == md5) request->send(SPIFFS, "/index.html", "text/html");
            else request->send(SPIFFS, "/login.html", "text/html");
        }else request->send(SPIFFS, "/login.html", "text/html"); });
    Configurator::server->on("/prefs", HTTP_GET, [](AsyncWebServerRequest *request)
                             {
        if(request->hasParam("mdp")){
            String _md5 = request->getParam("mdp")->value();
            char *md5_ = (char*)(_md5.c_str());
            std::string md5;
            md5 = (std::string)md5_;
            if(Configurator::md5_pwd == md5) request->send(SPIFFS, "/preferences.html", "text/html");
            else request->send(SPIFFS, "/login.html", "text/html");
        }else request->send(SPIFFS, "/login.html", "text/html"); });
    Configurator::server->on("/wifiscan", HTTP_GET, [](AsyncWebServerRequest *request)
                             {
        std::string result = Configurator::GetNetworks();
        request->send_P(200, "text/plain", result.c_str()); });
    Configurator::server->on("/update", HTTP_GET, [](AsyncWebServerRequest *request)
                             {
        if(request->hasParam("mdp") && request->hasParam("key") && request->hasParam("value")){
            std::string md5 = (std::string)request->getParam("mdp")->value().c_str();
            std::string key = (std::string)request->getParam("key")->value().c_str();
            std::string value = (std::string)request->getParam("value")->value().c_str();

            if(md5 == Configurator::md5_pwd){
                if(key == "username") Serial.println(value.c_str());
                if(key == "userpassword") Serial.println(value.c_str());
                if(key == "ap_password") Serial.println(value.c_str());
            }
        } });
    Configurator::server->on("/reset", HTTP_GET, [](AsyncWebServerRequest *request)
                             { Configurator::md5_pwd = ""; });
    Serial.print(WiFi.softAPIP());
    Configurator::server->begin();
}
std::string Configurator::GetNetworks()
{
    vector<std::string> ssids;
    int16_t n = -1;
    if (WiFi.status() != WL_NO_SSID_AVAIL)
    {
        n = WiFi.scanNetworks(true);
        do
        {
            n = WiFi.scanComplete();
            esp_task_wdt_reset();
        } while (n == -1);
        Serial.println(n);
        // esp_task_wdt_reset();
        if (n < 0)
            n = 0;
        // for(int i = 0; i < n; i++) ssids.push_back((std::string)((char*)(WiFi.SSID(i).c_str())));
        for (int i = 0; i < n; i++)
        {
            std::string name = "";
            name = (std::string)((char *)(WiFi.SSID(i).c_str()));
            if (name != "")
            {
                name = name + "<|RSSI|>";
                name = name + std::to_string((int)WiFi.RSSI(i));
                ssids.push_back(name);
            }
        }
    }
    std::string result = "";
    for (std::string ssid : ssids)
    {
        if (ssid != "")
            result = result + (std::string) "<|SPLITTER|>" + ssid;
    }
    Configurator::ReplaceAll(result, "<|SPLITTER|><|SPLITTER|>", "<|SPLITTER|>");
    if (n <= 0)
        result = "None";
    Serial.println(result.c_str());
    return result;
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
std::string Configurator::ReadDataPrefs(std::string key, std::string defaultval)
{
    Configurator::preferences->begin("configurator_preferences_", false);
    std::string result = (std::string)Configurator::preferences->getString(key.c_str(), String(defaultval.c_str())).c_str();
    Configurator::preferences->end();
    return result;
}
void Configurator::WriteDataPrefs(std::string key, std::string data)
{
    Configurator::preferences->begin("configurator_preferences_", false);
    Configurator::preferences->putString(key.c_str(), String(data.c_str()));
    Configurator::preferences->end();
}