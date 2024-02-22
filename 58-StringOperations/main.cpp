// Author: Burak Doğançay
#include "StringOperations.h"
#include <filesystem>

int main(int argc, char **argv)
{
   std::unique_ptr<StringOperations> stringOp = std::make_unique<StringOperations>();
   //---------------------------------------------
   stringOp.get()->basicCharPointerStrEx();
   //----------------------------
}