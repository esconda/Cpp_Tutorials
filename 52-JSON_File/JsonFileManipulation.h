// Author: Burak Doğançay
#ifndef JSONFILEMANIPULATION_H
#define JSONFILEMANIPULATION_H
#include <iostream>
#include <bitset>
#include <memory>
#include "json/json.h"
#include <fstream>
#include <filesystem>
#include <map>
/* In the BitManipulation class, we will cover useful functions that are generally used in communication protocols and embedded systems.*/
class JsonFileManipulation 
{
public:
    JsonFileManipulation();
    JsonFileManipulation(JsonFileManipulation &&ruleOfFive) noexcept = delete;         //III. MOVE CONSTRUCTOR
    JsonFileManipulation(const JsonFileManipulation &ruleOfThree) = delete;            // II. COPY CONSTRUCTOR
    JsonFileManipulation &operator=(const JsonFileManipulation &ruleOfThree) = delete; // III. COPY ASSIGNMENT
    ~JsonFileManipulation() = default;

    struct JsonSettings{
        Json::Value root;
        Json::StreamWriterBuilder builder;
        std::unique_ptr<Json::StreamWriter> writer;
        std::ofstream outputFileStream;
    }jsonSettings;

    void initJsonFileSettings(const std::string &pFolderName, const std::string &pFileName);
    void createJsonFile();
    Json::Value createArray(std::string Type1, std::string Type2, std::string Type3);


};

#endif