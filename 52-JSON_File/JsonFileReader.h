// Author: Burak Doğançay
#ifndef JSONFILEREADER_H
#define JSONFILEREADER_H
#include <iostream>
#include <bitset>
#include <memory>
#include "json/json.h"
#include <fstream>
#include <filesystem>
#include <map>
/* In the BitManipulation class, we will cover useful functions that are generally used in communication protocols and embedded systems.*/
class JsonFileReader 
{
public:
    JsonFileReader();
    JsonFileReader(JsonFileReader &&ruleOfFive) noexcept = delete;         //III. MOVE CONSTRUCTOR
    JsonFileReader(const JsonFileReader &ruleOfThree) = delete;            // II. COPY CONSTRUCTOR
    JsonFileReader &operator=(const JsonFileReader &ruleOfThree) = delete; // III. COPY ASSIGNMENT
    ~JsonFileReader() = default;

    struct JsonSettings{
        Json::Value root1;
        Json::Value root2;
        Json::CharReaderBuilder builder;
        std::ifstream inputFileStream;
        std::string fileName;
        JSONCPP_STRING errs;
    }jsonSettings;

    void initJsonFileSettings(const std::string &pFolderName, const std::string &pFileName);
    void parseJsonFile(Json::Value &root);
    void seperateParameters(Json::Value &root);
    
};

#endif