#pragma once
#include <unordered_map>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include "WiFi.h"
#include "SPIFFS.h"
#include <Preferences.h>
#include <sqlite3.h>

using namespace std;
class DatabaseHandler
{
public:
    static void Init();
    static void Execute(std::string command);
    static void Log();
    static std::string SELECT_ALL();
    static std::string getLogs(std::string from_date, std::string to_date);
private:
    static sqlite3 *database;
    static sqlite3_stmt *resource;
    static const char *tail;
};