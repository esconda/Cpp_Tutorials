#ifndef STDFUNCTION_H
#define STDFUNCTION_H

#include <iostream>
#include <cstring>
#include <functional>
//Author : Burak Dogancay

class StdFunction
{
public:
    StdFunction();
    StdFunction(int val) = delete;
    ~StdFunction() = default;// I DESTRUCTOR
     StdFunction(const StdFunction &ruleOfThree) = default;            // II. COPY CONSTRUCTOR
    StdFunction(StdFunction &&ruleOfFive) noexcept;       //III. MOVE CONSTRUCTOR
    StdFunction& operator=(const StdFunction &ruleOfThree) ; // IV COPY ASSIGNMENT
    StdFunction& operator=(StdFunction&& ruleOfFive) noexcept=default; // V. MOVE ASSIGNMENT

    
    void simpleFunction(int pI, const std::string& pString);
    void simpleCallIntFunct(const std::string& a);
    void simpleCallVoidFunct();

 

};

#endif