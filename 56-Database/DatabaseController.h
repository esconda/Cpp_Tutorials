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
/* A function pointer is a variable that stores the address of a function that can later be called through that function pointer. 
This is useful because functions encapsulate behavior. For instance, every time you need a particular behavior such as drawing a line, 
instead of writing out a bunch of code, all you need to do is call the function. 
But sometimes you would like to choose different behaviors at different times in essentially the same piece of code.*/
class DatabaseController
{
public:
    DatabaseController();
    DatabaseController(int val) = delete;
    DatabaseController(DatabaseController &&ruleOfFive) noexcept = delete;         //III. MOVE CONSTRUCTOR
    DatabaseController(const DatabaseController &ruleOfThree) = delete;            // II. COPY CONSTRUCTOR
    DatabaseController &operator=(const DatabaseController &ruleOfThree) = delete; // III. COPY ASSIGNMENT
    ~DatabaseController() =default;

    std::string quoteString(const std::string & sqlstr);
    std::string quoteInt(const int& sqlInt);
    bool openDatabase(const std::string &pFilePath, const std::string &pfileName);
    void insertDataToTableProcess();

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
};

#endif