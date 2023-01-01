// Author: Burak Doğançay
#include "DatabaseController.h"

static int dataCallbackFunc(void *data, int dataSize, char **attribute, char **dataColName){
    for(int i = 0; i<dataSize; i++){
      std::cout<<dataColName[i]<<"="<<attribute[i]<<std::endl;
   }
   return 0;
}

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
    uavVariables.mId= 5;
    uavVariables.mName = "Anka";
    uavVariables.mType = "Uav";
    uavVariables.mCompany = "Tai";
    uavVariables.mInfo = "One of the best air vehicle that Tai has developed";
    uavVariables.mUniqueId = 06;

    std::string tSqlStatement  =  this->sqlQueryVars("INSERT INTO UavTable (Id, Name, Type, Company, Info, UniqueId) VALUES ",
                                                    quoteInt(uavVariables.mId),quoteString(uavVariables.mName),quoteString(uavVariables.mType),
                                                    quoteString(uavVariables.mCompany),quoteString(uavVariables.mInfo),quoteInt(uavVariables.mUniqueId));
    this->executeSqlQuery(tSqlStatement,mDataBaseFile,NULL);
    std::cout<<"---------SQL OPERATIONS IS----------"<<std::endl;
    std::cout<<tSqlStatement<<std::endl;
    
}

void DatabaseController::selectAndGetDataTableProcess(){

    std::string tSqlStatement = this->sqlQueryVars("SELECT * FROM UavTable",NULL);
    this->executeSqlQuery(tSqlStatement,mDataBaseFile,&dataCallbackFunc);
    std::cout<<"---------SQL OPERATIONS IS----------"<<std::endl;
    std::cout<<tSqlStatement<<std::endl;
}

template <typename Type>
Type DatabaseController::bindValues(const Type &var){
    return var;
}
template <typename Type,typename... Rest>
Type DatabaseController::bindValues(const Type &pFirst,const Rest& ...pRestOfVars){
    static std::string tSqlStatement;
    tSqlStatement = pFirst + "," + bindValues(pRestOfVars...);
    return tSqlStatement;
}
template <typename Type,typename... Rest>
std::string DatabaseController::sqlQueryVars(const Type &pMainArg,const Rest& ...pRestOfVars){
    static std::string tSqlStatement;
    if((sizeof...(pRestOfVars))>1)
        tSqlStatement = std::string("(").c_str() + bindValues(pRestOfVars...) + std::string(");");
    else 
        tSqlStatement= "";
    tSqlStatement = pMainArg + tSqlStatement;
    return tSqlStatement;
}

void DatabaseController::executeSqlQuery(const std::string &pQueryMessage, sqlite3 *pDataBaseFile, int (*callback)(void *, int, char**,char**)){
    static int tCheckExecution = 0;
    static char* tMessageError = 0;

     tCheckExecution = sqlite3_exec(pDataBaseFile,pQueryMessage.c_str(),callback, 0,&tMessageError);

    if( tCheckExecution != SQLITE_OK ){
        std::cout<<"SQL error:"<<tMessageError<<std::endl;
        sqlite3_free(tMessageError);
    }
    else {
        std::cout<<"Records created successfully"<<std::endl;;
    }
    
    sqlite3_close(pDataBaseFile); 
}

