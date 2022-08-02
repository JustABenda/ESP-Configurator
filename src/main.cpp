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
#include "EventSource.hpp"
void setup()
{
  Serial.begin(115200);
  Serial.println();
  Configurator::FIRMWARE_VERSION = "v0.0.1";
  Configurator::Init("ESP Configurator"); // Configurator::Deinit(); to turn off
}
void onLogin(bool success)
{
  Serial.println(success);
}
void onConnect(std::string ssid)
{
  Serial.println(ssid.c_str());
}
void onDisconnect()
{
  Serial.println("Disconnected");
}
void onUpdate(std::string command)
{
  Serial.println(command.c_str());
}

void loop()
{
  delay(1000);
}