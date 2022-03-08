#include "typekeyword.h"

TypeKeyword::TypeKeyword(){
    
}

TypeKeyword::TypeKeyword(int val)
{

}

TypeKeyword::~TypeKeyword(){

}

TypeKeyword::TypeKeyword(const TypeKeyword &ruleOfThree){

}

TypeKeyword &TypeKeyword::operator=(const TypeKeyword &ruleOfThree)
{
    
    
}

void TypeKeyword::enumOperation(){
    Direction d = UP;

    std::cout<<"Enum type is identified and initial value is : "<< d<<std::endl;

}

void TypeKeyword::enumClassOperation(){
    //Format a = Format::TEXT;
    //std::cout<<a<<std::endl;
}

void TypeKeyword::structOperation(){
    somethingStruct structsomething;
    std::cout<<"Something struct variables : "<<structsomething.variable1[0]<< "  "<<structsomething.variable2<<std::endl;
}

void TypeKeyword::structOperation2(){
    std::cout<<"Something Struct 2 variables : "<< somethingStruct2.variable << " " << somethingStruct2.variable2 << std::endl;
}

void TypeKeyword::unionOperation(){
    Sigval sigVal;
    sigVal.sival_int = 50;

    std::cout<<"Union type values : " << sigVal.sival_int <<" " << reinterpret_cast<int>(sigVal.sival_ptr) << std::endl; //reinterpret cast is to convert function pointer to int type
}
