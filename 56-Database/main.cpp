// Author: Burak Doğançay
#include "DatabaseController.h"
#include <filesystem>

int main(int argc, char **argv)
{
   std::unique_ptr<DatabaseController> databaseController = std::make_unique<DatabaseController>();
   //Database Process Functions
   databaseController.get()->setClassInstance(databaseController.get());
   databaseController.get()->openDatabase(std::filesystem::current_path().string(),"/56-Database/Test.db");
   databaseController.get()->insertDataToTableProcess();
   databaseController.get()->selectAndGetDataTableProcess();
   databaseController.get()->infoForSqlData();
   databaseController.get()->closeDatabase(databaseController.get()->mDataBaseFile);
   //----------------------------
}