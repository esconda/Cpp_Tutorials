#ifndef INLINEFUNCTIONS_H
#define INLINEFUNCTIONS_H

#include <iostream>
#include <cstring>
#include <functional>
//Author : Burak Dogancay
/* A function defined with the inline specifier is an inline function. An inline function can be multiply defined without
violating the One Definition Rule, and can therefore be defined in a header with external linkage. Declaring a
function inline hints to the compiler that the function should be inlined during code generation, but does not
provide a guarantee. */
class InlineFunctions 
{
public:
    InlineFunctions();
    InlineFunctions(int val) = delete;
    InlineFunctions(InlineFunctions &&ruleOfFive) noexcept = delete;         //III. MOVE CONSTRUCTOR
    InlineFunctions(const InlineFunctions &ruleOfThree) = delete;            // II. COPY CONSTRUCTOR
    InlineFunctions &operator=(const InlineFunctions &ruleOfThree) = delete; // III. COPY ASSIGNMENT
    ~InlineFunctions() = default;

    inline void nonMemberInlineFunc(int x, int y){
        std::cout<<"Inline funct definition : "<<x+y<<std::endl;
    }
};

#endif