#include "WhatisNameSpace/NameSpaceExample.h"

#include <iostream>
#include "WhatisNameSpace/NameSpaceExample.cpp"

using namespace NameBased::NameDerived;// USİNG DİRECTİVE FOR NAMESPACES
int main()
{
   NameBased::NameDerived::NameSpaceExample nameSpaceExample;
   NameSpaceExample *nameSpaceExamplePtr = &nameSpaceExample; 
   nameSpaceExample.printNamespace();
   nameSpaceExamplePtr->printNamespace();
   nameSpaceExamplePtr->printNamespace();
}