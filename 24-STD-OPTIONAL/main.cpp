#include "StdOptional.h"
#include <iostream>

int main()
{
    StdOptional stdOptional;
    
    std::cout<<"Adress of the constructor : "<<&stdOptional<< std::endl;
    stdOptional.optionalInitializing();
    stdOptional.stdOptionalProcess();
    stdOptional.stdOptionalStructExample();
    stdOptional.stdOptionalReturnVal();
    stdOptional.stdOptionalValueOr();
   
}