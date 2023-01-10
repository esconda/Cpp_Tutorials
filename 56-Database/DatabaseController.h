// Author: Burak Doğançay
#ifndef DATABASECONTROLLER_H
#define DATABASECONTROLLER_H
#include <iostream>
#include <memory>
#include <algorithm>
#include <functional>
#include "sqlite3.h"
#include <map>
#define print(a) std::cout << a
#define printOneLine(a) std::cout << a << std::endl
#define printTwoLine(a,b) std::cout << a << b << std::endl

/*Sqlite3 Database Controller class to manage given database*/
class DatabaseController
{
public:
    DatabaseController();
    DatabaseController(int val) = delete;
    DatabaseController(DatabaseController &&ruleOfFive) noexcept = delete;         //III. MOVE CONSTRUCTOR
    DatabaseController(const DatabaseController &ruleOfThree) = delete;            // II. COPY CONSTRUCTOR
    DatabaseController &operator=(const DatabaseController &ruleOfThree) = delete; // III. COPY ASSIGNMENT
    ~DatabaseController() =default;

    void setClassInstance(DatabaseController* instance);
    static DatabaseController *getClassInstance();
    bool openDatabase(const std::string &pFilePath, const std::string &pfileName);
    void closeDatabase(sqlite3 *pDataBaseFile);
    void insertDataToTableProcess();
    void selectAndGetDataTableProcess();
    void processSqlData();
    void infoForSqlData();
    
    sqlite3 *mDataBaseFile;
    struct SqlData{
        int dataSize;
        char **attribute;
        char **dataColName;
    }sqlData;

private:
    typedef struct UavVars{
        UavVars(){
            mId = 0;
            mName = "";
            mType = "";
            mCompany = "";
            mInfo = "";
            mUniqueId = 0;
        }
        int mId;
        std::string mName;
        std::string mType;
        std::string mCompany;
        std::string mInfo;
        int mUniqueId;
    }uavVars;
    
    std::vector<uavVars*> mUavDataCollection;
    std::vector<UavVars> mSqlDataVector;
    static inline DatabaseController *mclassInstance;

    std::string quoteString(const std::string & sqlstr);
    std::string quoteInt(const int& sqlInt);
    template <typename Type>
    Type bindValues(const Type& pVar);
    template <typename Type,typename... Rest>
    Type bindValues(const Type &pFirst,const Rest& ...pRestOfVars);
    template <typename Type,typename... Rest>
    std::string sqlQueryVars(const Type &pMainArg,const Rest& ...pRestOfVars);
    void executeSqlQuery(const std::string &pQueryMessage, sqlite3 *pDataBaseFile, int (*callback)(void *, int, char**,char**));
    
};

#endif