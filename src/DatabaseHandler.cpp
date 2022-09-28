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
    char *errorMSG = 0;
    int rc = sqlite3_exec(DatabaseHandler::database, command.c_str(), DatabaseHandler::callback, (void*)DatabaseHandler::data, &errorMSG);
    if(rc != SQLITE_OK){Serial.print("Failed executing command: ");Serial.println(errorMSG);return;}
}
void DatabaseHandler::Log(std::string time_from, std::string time_to, double kwh_s, double kwh_e, double kwh_sum){
    std::string cmd = "INSERT INTO 'device' ('datetime_start', 'datetime_end',  'kwh_start', 'kwh_end', 'kwh_consumed') VALUES ('" + time_from + "', '" + time_to + "', '" + to_string(kwh_s) + "', '" + to_string(kwh_e) + "', '" + to_string(kwh_sum) + "')";
    DatabaseHandler::Execute(cmd);
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
    std::string exec_string = "SELECT rowid, * from device WHERE datetime_start BETWEEN '" + from_date + "' AND '" + to_date + "'";
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
        std::string power = to_string(sqlite3_column_double(DatabaseHandler::resource, 3));
        power = Utilities::tokenize(power, '.')[0] + "." + Utilities::tokenize(power, '.')[1][0] + Utilities::tokenize(power, '.')[1][1];
        response += (power).c_str();
        response += "|";
        power = to_string(sqlite3_column_double(DatabaseHandler::resource, 4));
        power = Utilities::tokenize(power, '.')[0] + "." + Utilities::tokenize(power, '.')[1][0] + Utilities::tokenize(power, '.')[1][1];
        response += (power).c_str();
        response += "|";
        power = to_string(sqlite3_column_double(DatabaseHandler::resource, 5));
        power = Utilities::tokenize(power, '.')[0] + "." + Utilities::tokenize(power, '.')[1][0] + Utilities::tokenize(power, '.')[1][1];
        response += (power).c_str();
        result += response + "@";
    }
    sqlite3_finalize(DatabaseHandler::resource);
    Serial.println(result.c_str());
    return result;
}
const char* DatabaseHandler::data = "Callback function called";
int DatabaseHandler::callback(void *data, int argc, char **argv, char **azColName){
   int i;
   Serial.printf("%s: ", (const char*)data);
   for (i = 0; i<argc; i++){
       Serial.printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
   }
   Serial.printf("\n");
   return 0;
}
