#include "VirtualMemberFunctions/FinalVirtualFunctionsDerived.h"
#include "InlineFunctions/InlineFunctions.h"

#include <iostream>
#include "VirtualMemberFunctions/FinalVirtualFunctionsDerived.cpp"
#include "InlineFunctions/InlineFunctions.cpp"
int main()
{
    FinalVirtualFunctionsDerived funcDerived;
    InlineFunctions inlineFunctions;
    //Virtual Member Functions
    funcDerived.baseClassInformation();
    funcDerived.overridingFunc();
    funcDerived.overridingFunc2();

    //Inline Functions
    inlineFunctions.nonMemberInlineFunc(5,20);
}