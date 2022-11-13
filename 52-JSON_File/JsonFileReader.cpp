// Author: Burak Doğançay
#include "JsonFileReader.h"

JsonFileReader::JsonFileReader()
{
}

void JsonFileReader::initJsonFileSettings(const std::string &pFolderName, const std::string &pFileName)
{
     jsonSettings.inputFileStream.open(pFolderName + pFileName, std::ifstream::in);
     jsonSettings.builder["collectComments"] = true;
     jsonSettings.fileName = pFileName;
}

void JsonFileReader::parseJsonFile(Json::Value &root)
{

     if (!Json::parseFromStream(jsonSettings.builder, jsonSettings.inputFileStream, &root, &jsonSettings.errs))
     {
          std::cout << jsonSettings.errs << std::endl;
          return;
     }
     // std::cout << root << std::endl;
     this->seperateParameters(root);
     jsonSettings.inputFileStream.close();
}

void JsonFileReader::seperateParameters(Json::Value &root)
{
     static std::string useArea = "";
     static std::string companyName = "";
     static std::string vehicleTypes = "";

     // Definition Variables Subelements
     std::vector<int> id;
     std::vector<std::string> name;
     std::vector<std::string> type;

     id.reserve(10);
     name.reserve(10);
     type.reserve(10);

     /*  for(auto &item: root.getMemberNames()){
        std::cout<<"Item : "<< item.c_str()<<std::endl;
      } */

     useArea = root[root.getMemberNames().at(0)].asString();      // or root["Army Use Area"].asString();
     companyName = root[root.getMemberNames().at(1)].asString();  // or root["Company Name"].asString();
     vehicleTypes = root[root.getMemberNames().at(3)].asString(); // or root["Vehicle Types"].asString();

     for (Json::Value &definitionItem : root["Definition"])
     {
          id.emplace_back(definitionItem[definitionItem.getMemberNames().at(0)].asInt());
          name.emplace_back(definitionItem[definitionItem.getMemberNames().at(1)].asString());
          type.emplace_back(definitionItem[definitionItem.getMemberNames().at(2)].asString());
     }

     // PRINT SEPERATED VARIABLES
     std::cout<<"  "<<std::endl;
     std::cout<<"File Name is : "<<jsonSettings.fileName<<std::endl;
     std::cout<< "Army Use Area : " << useArea << std::endl;
     std::cout << "Company Name : " << companyName << std::endl;
     std::cout << "Vehicle Types : " << vehicleTypes << std::endl;

     for (auto &item : id)
     {
          std::cout << "Definition Id : " << item << std::endl;
     }
     std::cout<<"  "<<std::endl;
     for (auto &item : name)
     {
          std::cout << "Definition Name : " << item << std::endl;
     }
     std::cout<<"  "<<std::endl;
     for (auto &item : type)
     {
          std::cout << "Definition Type : " << item << std::endl;
     }
     std::cout<<"  "<<std::endl;
}
