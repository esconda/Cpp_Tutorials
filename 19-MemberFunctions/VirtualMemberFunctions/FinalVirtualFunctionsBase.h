#ifndef FINALVIRTUALFUNCTIONSBASE_H
#define FINALVIRTUALFUNCTIONSBASE_H

#include <iostream>
#include <cstring>
#include <functional>
//Author : Burak Dogancay

class FinalVirtualFunctionsBase
{
public:
    FinalVirtualFunctionsBase();
    FinalVirtualFunctionsBase(int val) = delete;
    FinalVirtualFunctionsBase(FinalVirtualFunctionsBase &&ruleOfFive) noexcept = delete;         //III. MOVE CONSTRUCTOR
    FinalVirtualFunctionsBase(const FinalVirtualFunctionsBase &ruleOfThree) = delete;            // II. COPY CONSTRUCTOR
    FinalVirtualFunctionsBase &operator=(const FinalVirtualFunctionsBase &ruleOfThree) = delete; // III. COPY ASSIGNMENT
    virtual ~FinalVirtualFunctionsBase() = 0;

    void baseClassInformation();
    inline virtual void overridingFunc(){
        std::cout<<"Baseclass Overriding1";
    }
    inline virtual void overridingFunc2(){
        std::cout<<"BaseClass Overriding2";
    }


};

#endif