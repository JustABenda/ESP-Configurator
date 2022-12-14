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
#include "Utils.hpp"

using namespace std;
class DatabaseHandler
{
public:
    static void Init();
    static void Execute(std::string command);
    static void Log(std::string time_from, std::string time_to, double kwh_s, double kwh_e, double kwh_sum);
    static std::string SELECT_ALL();
    static std::string getLogs(std::string from_date, std::string to_date);
private:
    static sqlite3 *database;
    static sqlite3_stmt *resource;
    static const char *tail;
    static int callback(void *data, int argc, char **argv, char **azColName);
    static const char* data;
};