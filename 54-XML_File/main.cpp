// Author: Burak Doğançay
#include "XmlController.h"
#include <filesystem>

int main(int argc, char **argv)
{
   std::unique_ptr<XmlController> xmlController = std::make_unique<XmlController>();
  

  xmlController.get()->init();
  xmlController.get()->openXmlFile(std::filesystem::current_path().string(),"/54-XML_File/test.xml");
  xmlController.get()->uavElementsProcess();


}