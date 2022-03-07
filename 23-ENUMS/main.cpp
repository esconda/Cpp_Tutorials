#include "EnumExample.h"
#include <iostream>

int main()
{
    EnumExample enumExample;
    
    EnumExample::UavTypesClass uav = EnumExample::UavTypesClass::akinci;
    enumExample.enumClassProcess(static_cast<int>(uav));//if we dont use static cast we get conversion type error
    enumExample.enumClassProcess(static_cast<int>(EnumExample::UavTypesClass::aksungur));//Alternative way of
    enumExample.enumClassProcess(EnumExample::UavTypesNormal::tb2);//compiler does not give any error as enum class type.Therefore you should use enum class to see type errors
   
   //enumExample.iterator_over_enum();
}