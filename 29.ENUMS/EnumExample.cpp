#include "EnumExample.h"

EnumExample::EnumExample()
{
}

void EnumExample::enumClassProcess(int enumType){

    std::cout<<"enum type is : "<< enumType<<std::endl;

}

void EnumExample::iterator_over_enum(){
    //iterator over enum in for loop
 /*    for(UavTypesNormal en = UavTypesNormal::tb2; en!=UavTypesNormal::aksungur;++en){
        std::cout<<"Enum Variables:"<<en<<std::endl;
    } */
}