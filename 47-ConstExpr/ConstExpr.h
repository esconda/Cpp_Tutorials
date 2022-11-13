// Author: Burak Doğançay
#ifndef OVERLOADRESOLUTION_H
#define OVERLOADRESOLUTION_H
#include <iostream>
#include <memory>
#include <thread>
/* constexpr is a keyword that can be used to mark a variable's value as a constant expression, a function as
potentially usable in constant expressions, or (since C++17) an if statement as having only one of its branches
selected to be compiled */
class ConstExpr
{
public:
    ConstExpr();
    void constExpVariable();
    void staticIfStatement();
    void constExprFunction();

};

#endif