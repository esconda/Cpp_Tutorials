// Author: Burak Doğançay
#include "DatabaseController.h"
DatabaseController::DatabaseController()
{

}

std::string DatabaseController::quoteString(const std::string & sqlstr){
    return std::string("'") + sqlstr + std::string("'");
}

std::string DatabaseController::quoteInt(const int& sqlInt){
    return std::to_string(sqlInt);
}
bool DatabaseController::openDatabase(const std::string &pFilePath, const std::string &pfileName){
    static int tCheckFile = 0;

    tCheckFile = sqlite3_open((pFilePath+pfileName).c_str(), &mDataBaseFile);

    if(tCheckFile){
        std::cout<<"Can not open database : "<<sqlite3_errcode(mDataBaseFile)<<std::endl;
        std::cout<<"Erro Message is"<<sqlite3_errmsg(mDataBaseFile)<<std::endl;
        return false;
    }
    else{
        std::cout<<"Database opened succesfully"<<std::endl;
        return true;
    }
}

void DatabaseController::insertDataToTableProcess(){
    static uavVars uavVariables;
    static int tCheckExecution = 0;
    static char* tMessageError = 0;

    uavVariables.mId= 10;
    uavVariables.mName = "Akıncı";
    uavVariables.mType = "Uav";
    uavVariables.mCompany = "Baykar";
    uavVariables.mInfo = "One of the best systems Baykar has developed";
    uavVariables.mUniqueId = 61;

    std::string sqlStatement = "INSERT INTO UavTable (Id, Name, Type, Company, Info, UniqueId) VALUES ("
    + quoteInt(uavVariables.mId) + ","
    + quoteString(uavVariables.mName) + ","
    + quoteString(uavVariables.mType) + ","
    + quoteString(uavVariables.mCompany) + ","
    + quoteString(uavVariables.mInfo) + ","
    + quoteInt(uavVariables.mUniqueId)
    + ");";

    tCheckExecution = sqlite3_exec(mDataBaseFile,sqlStatement.c_str(),NULL , 0,&tMessageError);

    if( tCheckExecution != SQLITE_OK ){
        std::cout<<"SQL error:"<<tMessageError<<std::endl;
        sqlite3_free(tMessageError);
    }
    else {
        std::cout<<"Records created successfully"<<std::endl;;
    }
    
    sqlite3_close(mDataBaseFile);
}



