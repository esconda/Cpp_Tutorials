#ifndef FUNCTIONOVERLOADING_H
#define FUNCTIONOVERLOADING_H

#include <iostream>
#include <cstring>
#include <functional>

//ClassBasics1 is equal to ClassBasics
/* public Everyone has access
protected Only the class itself, derived classes and friends have access
private Only the class itself and friends have access */

//Access specifiers are mostly used to limit access to internal fields and methods, and force the programmer to use a
//specific interface, for example to force use of getters and setters instead of referencing a variable directly:

//Using protected is useful for allowing certain functionality of the type to be only accessible to the derived classes,
class FunctionOverloading
{
public:
    FunctionOverloading();
    FunctionOverloading(int val) = delete;
    FunctionOverloading(FunctionOverloading &&ruleOfFive) noexcept = delete;         //III. MOVE CONSTRUCTOR
    FunctionOverloading(const FunctionOverloading &ruleOfThree) = delete;            // II. COPY CONSTRUCTOR
    FunctionOverloading &operator=(const FunctionOverloading &ruleOfThree) = delete; // III. COPY ASSIGNMENT
    ~FunctionOverloading() = default;

    //-----------Function Overloading-------------
    void print(const std::string &pStr);
    void print(int pVal);
    void print(double pVal);
    //Note that you cannot overload a function based on its return type. For example:
    /* // WRONG CODE
std::string getValue()
{
return "hello";
}
int getValue()
{
return 0;
}
int x = getValue(); */
};

#endif