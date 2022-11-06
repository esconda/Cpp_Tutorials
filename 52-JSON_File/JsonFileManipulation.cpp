// Author: Burak Doğançay
#include "JsonFileManipulation.h"


JsonFileManipulation::JsonFileManipulation()
{

}

void JsonFileManipulation::initJsonFileSettings(const std::string &pFolderName, const std::string &pFileName){
     jsonSettings.outputFileStream.open(pFolderName+pFileName,std::ofstream::out | std::ofstream::trunc);
     jsonSettings.outputFileStream<<"";
     jsonSettings.writer = std::unique_ptr<Json::StreamWriter>(jsonSettings.builder.newStreamWriter());
}

Json::Value JsonFileManipulation::createArray(std::string Type1, std::string Type2, std::string Type3){
    Json::Value elements;
    elements["1"] = "UAV";
    elements["2"] = "Unmanned Aertial Vehicle";
    elements["3"] = "Plane";
    return elements;
}

void JsonFileManipulation::createJsonFile(){

  //Json Elements
  jsonSettings.root["Unmanned Vehicle Name"] = "Tb2";
  jsonSettings.root["Height"] = 100;
  jsonSettings.root["Width"] = 100;

  //Creating array type json variable
  jsonSettings.root["Type"][0] = createArray("UAV", "Unmanned Aertial Vehicle","Plane");
  jsonSettings.root["Type"][1] = createArray("UAV", "Unmanned Aertial Vehicle","Plane");
  jsonSettings.root["Type"][2] = createArray("UAV", "Unmanned Aertial Vehicle","Plane");
  
  //Print all variables
  for(auto &item: jsonSettings.root.getMemberNames()){
    std::cout<<item.c_str()<<std::endl; 
    if(!item.compare("Type")){
      std::cout<<"Type is available in Json"<<std::endl;
    }
  }

  //Write Json Variables to Json File
  jsonSettings.writer.get()->write(jsonSettings.root, &jsonSettings.outputFileStream);
  jsonSettings.outputFileStream.close();
}
