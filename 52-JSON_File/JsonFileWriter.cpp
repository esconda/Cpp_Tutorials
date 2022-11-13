// Author: Burak Doğançay
#include "JsonFileWriter.h"


JsonFileWriter::JsonFileWriter()
{

}

void JsonFileWriter::initJsonFileSettings(const std::string &pFolderName, const std::string &pFileName){
     jsonSettings.outputFileStream.open(pFolderName+pFileName,std::ofstream::out | std::ofstream::trunc);
     jsonSettings.outputFileStream<<"";
     jsonSettings.writer = std::unique_ptr<Json::StreamWriter>(jsonSettings.builder.newStreamWriter());
}

Json::Value JsonFileWriter::createArray(int Type1, std::string Type2, std::string Type3){
    Json::Value elements;
    elements["ID"] = Type1;
    elements["Type"] = Type2;
    elements["Name"] = Type3;
    return elements;
}

void JsonFileWriter::createJsonFile(){

  //Json Elements
  jsonSettings.root["Vehicle Types"] = "UAV";
  jsonSettings.root["Company Name"] = "Bayraktar, Tai";
  jsonSettings.root["Army Use Area"] = "Air Forces";

  //Creating array type json variable
  jsonSettings.root["Definition"][0] = createArray(1, "UAV", "TB2");
  jsonSettings.root["Definition"][1] = createArray(2, "UAV", "AKINCI");
  jsonSettings.root["Definition"][2] = createArray(3, "UAV", "AKSUNGUR");
  jsonSettings.root["Definition"][3] = createArray(4, "UAV", "AKINCI");
  
  //Print all variables
 /*  for(auto &item: jsonSettings.root.getMemberNames()){
    std::cout<<item.c_str()<<std::endl; 
    if(!item.compare("Type")){
      std::cout<<"Type is available in Json"<<std::endl;
    }
  } */

  //Write Json Variables to Json File
  jsonSettings.writer.get()->write(jsonSettings.root, &jsonSettings.outputFileStream);
  jsonSettings.outputFileStream.close();
}
