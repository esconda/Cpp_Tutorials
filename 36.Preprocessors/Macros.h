#ifndef MACROS_H 
#define MACROS_H
#include <iostream>
#include "IncludeGuards.h"
#define GuardClass mGuards 
//Author : Burak Dogancay
/* Macros are categorized into two main groups: object-like macros and function-like macros. Macros are treated as a
token substitution early in the compilation process */
class Macros
{
public:
    Macros();
    Macros(int val) = delete;
    Macros(Macros &&ruleOfFive) noexcept = delete;         //III. MOVE CONSTRUCTOR
    Macros(const Macros &ruleOfThree) = delete;            // II. COPY CONSTRUCTOR
    Macros &operator=(const Macros &ruleOfThree) = delete; // III. COPY ASSIGNMENT
    ~Macros() = default; //Destructor

   void macroFuncExample();
   void macroFuncSecondEx();
   void complexFunctionMacros();
   void moreComplexFunctionMacro();
   void variadicFunctionMacro();
   void preprocessorOperatorsFirstEx();
   void preprocessorOperatorSecondEX();
   void preprocessorOpVarDefine();
   void preprocessorErrorMessage();
   void variableMacro();


private:
   std::unique_ptr<IncludeGuards> mGuards;
};

#endif