#include <Arduino.h>
#include <unordered_map>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include "WiFi.h"
#include "ESPAsyncWebServer.h"
#include "SPIFFS.h"
#include "Configurator.hpp"

#define CONFIG_ASYNC_TCP_USE_WDT 0

void setup()
{
  Serial.begin(115200);
  Serial.println();
  if (!SPIFFS.begin())                                                                                                         // WebServer files
  {
      Serial.println("Failed to mount device filesystem"); // Failed
  }
  DatabaseHandler::Init();
  Configurator::FIRMWARE_VERSION = 100;
  Configurator::Init("ESP Configurator", false, "http://jakubuvmed.cz/SMART_Wallbox/firmwareWB.json"); // Configurator::Deinit(); to turn off
}
void loop()
{
  vTaskSuspend(NULL);
}