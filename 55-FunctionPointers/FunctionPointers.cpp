// Author: Burak Doğançay
#include "FunctionPointers.h"
FunctionPointers::FunctionPointers():
firstVar(0),
secondVar(0)
{
}

void FunctionPointers::callBackFunction(int pFirstVar, int pSecondVar, func func,FunctionPointers *givenClass){
    
    firstVar = pFirstVar;
    secondVar = pSecondVar;
    std::cout<<"First Variable is: "<<firstVar<<std::endl;
    std::cout<<"Second Variable is : "<<secondVar<<std::endl; 
    //given class parameter can be used in this aproach, or basically you can use "this" current instance of the class
    (this->*func)();
    //(givenClass->*f());
}

void FunctionPointers::callBackFunctionStd(int pFirstVar, int pSecondVar, funcStd func,FunctionPointers *givenClass){
    firstVar = pFirstVar;
    secondVar = pSecondVar;

    std::cout<<"First Variable is: "<<firstVar<<std::endl;
    std::cout<<"Second Variable is : "<<secondVar<<std::endl; 
    func(); // Function can be called using this current instance of the class
}

int FunctionPointers::callBackFunctionWithParams(int pFirstVar, int pSecondVar, funcParam func){
    return (this->*func)(pFirstVar,pSecondVar);
}

int FunctionPointers::callBackFunctionWithParamsStd(int pFirstVar, int pSecondVar, funcParamStd func){
    return func(pFirstVar,pSecondVar);
}

void FunctionPointers::returnBiggestVariable(){
    static int tVar;

    if(firstVar > secondVar)
        tVar=firstVar;
    else
        tVar=secondVar;
    
    std::cout<< "Biggest Variable is :"<< tVar << std::endl;
}

int FunctionPointers::multiplyProcess(int a,int b){
    static int tMul;
    tMul = a*b;
    std::cout<<"Multiply two Variables : "<<tMul<<std::endl;
    return tMul;
}

