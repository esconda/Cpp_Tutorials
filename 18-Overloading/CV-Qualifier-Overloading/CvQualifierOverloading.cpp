#include "FunctionOverloading.h"

FunctionOverloading::FunctionOverloading()
{
}

void FunctionOverloading::print(const std::string &pStr){
    std::cout<<"String Val is : "<<pStr<<std::endl;
}

void FunctionOverloading::print(int pVal){
    std::cout<<"Integere Val is : "<<pVal<<std::endl;
}

void FunctionOverloading::print(double pVal){
    std::cout<<"Double Val is :"<<pVal<<std::endl;
}

