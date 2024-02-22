// Author: Burak Doğançay
#include "CStdioOperations.h"
#include <filesystem>

int main(int argc, char **argv)
{
   std::unique_ptr<CStdioOperations> cStdioOperations = std::make_unique<CStdioOperations>();
   std::string currentPath = std::filesystem::path(__FILE__).parent_path().string();
   //---------------------------------------------
   //OPERATION ON FILES
   /* cStdioOperations.get()->removeFunc(currentPath+"/RemoveFile.txt");
   cStdioOperations.get()->renameFunc(currentPath, currentPath+"/NewExampleFile.txt");
   cStdioOperations.get()->tmpFileFunc(); */
   //----------------------------

   //---------------------------------------------
   //FILE ACCESS
   //cStdioOperations.get()->fcloseFunc(currentPath + "/NewExampleFile.txt");
   //cStdioOperations.get()->fflushFunc(currentPath + "/NewExampleFile.txt");
   //cStdioOperations.get()->fopenFunc(currentPath + "/NewExampleFile.txt");
   cStdioOperations.get()->freopenFunc(currentPath + "/NewExampleFile.txt");
   //----------------------------

   //cStdioOperations.get()->fgetcFunc(currentPath + "/NewExampleFile.txt");
   //cStdioOperations.get()->fgetposFunc(currentPath + "/NewExampleFile.txt");
}