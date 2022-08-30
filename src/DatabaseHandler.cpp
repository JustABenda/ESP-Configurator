#include "DatabaseHandler.hpp"

sqlite3 *DatabaseHandler::database;
sqlite3_stmt *DatabaseHandler::resource;
const char *DatabaseHandler::tail;

void DatabaseHandler::Init(){
    sqlite3_initialize();
    int rc = sqlite3_open("/spiffs/sqlite.db", &DatabaseHandler::database);
    if(rc) Serial.println("Unable to open database file");
}
void DatabaseHandler::Execute(std::string command){

}
void DatabaseHandler::Log(){
    
}
std::string DatabaseHandler::SELECT_ALL(){
    std::string exec_string = "SELECT * FROM 'device_data'";
    int rc = sqlite3_prepare_v2(DatabaseHandler::database, exec_string.c_str(), 1000, &DatabaseHandler::resource, &DatabaseHandler::tail);
    if(rc != SQLITE_OK){Serial.println("Failed executing command");return "";}
    while (sqlite3_step(DatabaseHandler::resource) == SQLITE_ROW)
    {
        std::string response = "";
        response += ((const char *)sqlite3_column_text(DatabaseHandler::resource, 0));
        response += "; ";
        response += ((const char *)sqlite3_column_text(DatabaseHandler::resource, 1));
        response += "; ";
        response += ((const char *)sqlite3_column_text(DatabaseHandler::resource, 2));
        response += "; ";
        response += ((const char *)sqlite3_column_text(DatabaseHandler::resource, 3));
        Serial.println(response.c_str());
    }
    sqlite3_finalize(DatabaseHandler::resource);
    return "";
}
std::string DatabaseHandler::getLogs(std::string from_date, std::string to_date){
    std::string exec_string = "SELECT * FROM 'device_data' WHERE datetime BETWEEN '" + from_date + "' AND '" + to_date + "'";
    int rc = sqlite3_prepare_v2(DatabaseHandler::database, exec_string.c_str(), 1000, &DatabaseHandler::resource, &DatabaseHandler::tail);
    if(rc != SQLITE_OK){Serial.println("Failed executing command");return "";}
    std::string result = "";
    while (sqlite3_step(DatabaseHandler::resource) == SQLITE_ROW)
    {
        std::string response = "";
        response += ((const char *)sqlite3_column_text(DatabaseHandler::resource, 0));
        response += "|";
        response += ((const char *)sqlite3_column_text(DatabaseHandler::resource, 1));
        response += "|";
        response += ((const char *)sqlite3_column_text(DatabaseHandler::resource, 2));
        response += "|";
        response += ((const char *)sqlite3_column_text(DatabaseHandler::resource, 3));
        result += response + "@";
    }
    sqlite3_finalize(DatabaseHandler::resource);
    return result;
}