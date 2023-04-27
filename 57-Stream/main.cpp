// Author: Burak Doğançay
#include "StreamController.h"
#include <filesystem>

int main(int argc, char **argv)
{
   std::unique_ptr<StreamController> streamController = std::make_unique<StreamController>();

   //streamController.get()->ifStreamExample();
   //streamController.get()->osStreamExample();
   streamController.get()->isStreamExample();

   //----------------------------
}