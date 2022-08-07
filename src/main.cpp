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

int onLogin(std::string value);
int onConnect(std::string value);
int onDisconnect(std::string value);
int onUpdate(std::string value);

void setup()
{
  Serial.begin(115200);
  Serial.println();
  Configurator::FIRMWARE_VERSION = "v0.0.1";
  Configurator::LoginFunction = &onLogin;
  Configurator::DisconnectFunction = &onDisconnect;
  Configurator::ConnectFunction = &onConnect;
  Configurator::Init("ESP Configurator", false); // Configurator::Deinit(); to turn off
}
int onLogin(std::string value)
{
  Serial.println(value.c_str());
  return 0;
}
int onConnect(std::string ssid)
{
  Serial.println(ssid.c_str());
  return 0;
}
int onDisconnect(std::string arg /*NULL*/)
{
  Serial.println("Disconnected");
  return 0;
}
int onUpdate(std::string command)
{
  Serial.println(command.c_str());
  return 0;
}

void loop()
{
}