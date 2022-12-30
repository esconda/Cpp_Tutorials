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

   
    bool openDatabase(const std::string &pFilePath, const std::string &pfileName);
    void insertDataToTableProcess();
    void selectAndGetDataTableProcess();


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

    sqlite3 *mDataBaseFile;
    std::vector<uavVars*> mUavDataCollection;

    std::string quoteString(const std::string & sqlstr);
    std::string quoteInt(const int& sqlInt);
    template <typename Type>
    Type bindValues(const Type& pVar);
    template <typename Type,typename... Rest>
    Type bindValues(const Type &pFirst,const Rest& ...pRestOfVars);
    template <typename Type,typename... Rest>
    std::string sqlQueryVars(const Type &pMainArg,const Rest& ...pRestOfVars);
    void executeSqlQuery(const std::string &pQueryMessage, sqlite3 *pDataBaseFile);
};

#endif