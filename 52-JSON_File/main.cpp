// Author: Burak Doğançay
#include "JsonFileWriter.h"
#include "JsonFileReader.h"

#include <filesystem>

int main(int argc, char **argv)
{
   std::unique_ptr<JsonFileWriter> firstJsonFileWriter = std::make_unique<JsonFileWriter>();
   std::unique_ptr<JsonFileWriter> secondJsonFileWriter = std::make_unique<JsonFileWriter>();

   std::unique_ptr<JsonFileReader> jsonFileReader= std::make_unique<JsonFileReader>();

  firstJsonFileWriter.get()->initJsonFileSettings(std::filesystem::current_path().string(),"/52-JSON_File/test1.json");
  firstJsonFileWriter.get()->createJsonFile();

  secondJsonFileWriter.get()->initJsonFileSettings(std::filesystem::current_path().string(),"/52-JSON_File/test2.json");
  secondJsonFileWriter.get()->createJsonFile();

  jsonFileReader.get()->initJsonFileSettings(std::filesystem::current_path().string(),"/52-JSON_File/test1.json");
  jsonFileReader.get()->parseJsonFile(jsonFileReader->jsonSettings.root1);

  jsonFileReader.get()->initJsonFileSettings(std::filesystem::current_path().string(),"/52-JSON_File/test2.json");
  jsonFileReader.get()->parseJsonFile(jsonFileReader->jsonSettings.root2);


}
