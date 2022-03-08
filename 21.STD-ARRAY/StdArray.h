#ifndef STDARRAY_H
#define STDARRAY_H

#include <iostream>
#include <cstring>
#include <functional>
#include <array>
//Author : Burak Dogancay
/* A function defined with the inline specifier is an inline function. An inline function can be multiply defined without
violating the One Definition Rule, and can therefore be defined in a header with external linkage. Declaring a
function inline hints to the compiler that the function should be inlined during code generation, but does not
provide a guarantee. */
class StdArray
{
public:
    StdArray();
    StdArray(int val) = delete;
    StdArray(StdArray &&ruleOfFive) noexcept = delete;         //III. MOVE CONSTRUCTOR
    StdArray(const StdArray &ruleOfThree) = delete;            // II. COPY CONSTRUCTOR
    StdArray &operator=(const StdArray &ruleOfThree) = delete; // III. COPY ASSIGNMENT
    ~StdArray() = default;

    void ArrayInitialization();
    void ArrayInitStruct();
    void ElementAccess();
    void IteratingThroughArray();
    void ChangingAllElements();
};

#endif