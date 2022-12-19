// Author: Burak Doğançay
#include "DatabaseController.h"
#include <filesystem>

int main(int argc, char **argv)
{
   std::unique_ptr<DatabaseController> databaseController = std::make_unique<DatabaseController>();
   databaseController.get()->openDatabase(std::filesystem::current_path().string(),"/56-Database/Test.db");
   //databaseController.get()->insertDataToTableProcess();
}