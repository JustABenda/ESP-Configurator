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
#include <esp32fota.h>
#include "DatabaseHandler.hpp"

using namespace std;
class Configurator
{
public:
    enum APStatus {
        RUNNING = 0,
        EXPIRED = 1,
        OFF = 2,
        NONE = 3
    };
    static void Init(std::string title_, bool login_, std::string FOTA_URL_); // Init The server
    static void Deinit();
    static std::string title;
    static std::string md5_pwd;
    static std::string GetNetworks();
    static Preferences *preferences;
    static int FIRMWARE_VERSION;
    static bool login;
    static std::string STATUS;
    static APStatus getAPStatus();

private:
    static AsyncWebServer *server;
    static void ReplaceAll(std::string &str, const std::string &from, const std::string &to);
    static std::string ReadDataPrefs(std::string key, std::string defaultval);
    static std::string networks_string;
    static void WriteDataPrefs(std::string key, std::string data);
    static void WiFiEventHandlerFunc(WiFiEvent_t event);
    static bool WaitForClient();
    static bool scanning;
    static TaskHandle_t scanTaskHandler;
    static TaskHandle_t updateTaskHandler;
    static TaskHandle_t connectTaskHandler;
    static SemaphoreHandle_t scanSemaphoreHandle;
    static SemaphoreHandle_t sendScanSemaphoreHandle;
    static SemaphoreHandle_t updateSemaphoreHandle;
    static SemaphoreHandle_t connectSemaphoreHandle;
    static SemaphoreHandle_t connectedSemaphoreHandle;
    static void ScanTaskCode(void *vpParameters);
    static void UpdateFirmware(void *vpParameters);
    static void ConnectTaskCode(void *vpParameters);
    static bool NewestFirmware();
    static esp32FOTA *updateHandler;
    static std::string FOTA_URL;
    static std::string ssid_c;
    static std::string pass_c;
    static int connected_devices;
    static APStatus ap_status;
};