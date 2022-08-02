#pragma once
#include <unordered_map>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include "WiFi.h"
#include "ESPAsyncWebServer.h"
#include "SPIFFS.h"
#include <Preferences.h>
#include <esp_task_wdt.h>

using namespace std;
class Configurator
{
public:
    static void Init(std::string title_); // Init The server
    static void Deinit();
    static std::string title;
    static std::string md5_pwd;
    static std::string GetNetworks();
    static Preferences *preferences;
    static std::string FIRMWARE_VERSION;

private:
    static AsyncWebServer *server;
    static void ReplaceAll(std::string &str, const std::string &from, const std::string &to);
    static std::string ReadDataPrefs(std::string key, std::string defaultval);
    static void WriteDataPrefs(std::string key, std::string data);
};