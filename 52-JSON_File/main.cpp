// Author: Burak Doğançay
#include "JsonFileManipulation.h"

#include <filesystem>

int main(int argc, char **argv)
{
   std::unique_ptr<JsonFileManipulation> jsonFileManager = std::make_unique<JsonFileManipulation>();

  jsonFileManager.get()->initJsonFileSettings(std::filesystem::current_path().string(),"/51-JSON_File/test.json");
  jsonFileManager.get()->createJsonFile();

}
