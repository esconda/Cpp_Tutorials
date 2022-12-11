// Author: Burak Doğançay
#include "FunctionPointers.h"
#include <filesystem>

int main(int argc, char **argv)
{
   std::unique_ptr<FunctionPointers> functionPointers = std::make_unique<FunctionPointers>();
   functionPointers.get()->callBackFunction(20,30,&FunctionPointers::returnBiggestVariable,functionPointers.get());
   functionPointers.get()->callBackFunctionStd(20,30,std::bind(&FunctionPointers::returnBiggestVariable, functionPointers.get()),functionPointers.get());
   functionPointers.get()->callBackFunctionWithParams(20,30,&FunctionPointers::multiplyProcess);
   functionPointers.get()->callBackFunctionWithParamsStd(20,30,std::bind(FunctionPointers::multiplyProcess, functionPointers.get(), std::placeholders::_1,std::placeholders::_2));
}
