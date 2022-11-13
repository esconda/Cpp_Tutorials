// Author: Burak Doğançay
#ifndef JSONFILEWRITER_H
#define JSONFILEWRITER_H
#include <iostream>
#include <bitset>
#include <memory>
#include "json/json.h"
#include <fstream>
#include <filesystem>
#include <map>
/* In the BitManipulation class, we will cover useful functions that are generally used in communication protocols and embedded systems.*/
class JsonFileWriter 
{
public:
    JsonFileWriter();
    JsonFileWriter(JsonFileWriter &&ruleOfFive) noexcept = delete;         //III. MOVE CONSTRUCTOR
    JsonFileWriter(const JsonFileWriter &ruleOfThree) = delete;            // II. COPY CONSTRUCTOR
    JsonFileWriter &operator=(const JsonFileWriter &ruleOfThree) = delete; // III. COPY ASSIGNMENT
    ~JsonFileWriter() = default;

    struct JsonSettings{
        Json::Value root;
        Json::StreamWriterBuilder builder;
        std::unique_ptr<Json::StreamWriter> writer;
        std::ofstream outputFileStream;
    }jsonSettings;

    void initJsonFileSettings(const std::string &pFolderName, const std::string &pFileName);
    void createJsonFile();
    Json::Value createArray(int Type1, std::string Type2, std::string Type3);
};

#endif