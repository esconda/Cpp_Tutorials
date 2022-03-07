#include "FinalVirtualFunctionsDerived.h"

FinalVirtualFunctionsDerived::FinalVirtualFunctionsDerived()
{

}

FinalVirtualFunctionsBase::~FinalVirtualFunctionsBase(){

}
void FinalVirtualFunctionsDerived::overridingFunc(){
    std::cout<<"Derived Class Overriding Function 1"<<std::endl;
}

void FinalVirtualFunctionsDerived::overridingFunc2(){
    std::cout<<"Derived Class Overriding Function 2"<<std::endl;
}


