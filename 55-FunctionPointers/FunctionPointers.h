// Author: Burak Doğançay
#ifndef FUNCTIONPOINTERS_H
#define FUNCTIONPOINTERS_H
#include <iostream>
#include <memory>
#include <algorithm>
#include <functional>
#include <map>
#define print(a) std::cout << a
#define printOneLine(a) std::cout << a << std::endl
#define printTwoLine(a,b) std::cout << a << b << std::endl
/* A function pointer is a variable that stores the address of a function that can later be called through that function pointer. 
This is useful because functions encapsulate behavior. For instance, every time you need a particular behavior such as drawing a line, 
instead of writing out a bunch of code, all you need to do is call the function. 
But sometimes you would like to choose different behaviors at different times in essentially the same piece of code. Read on for concrete examples. */
class FunctionPointers
{
public:
    FunctionPointers();
    FunctionPointers(int val) = delete;
    FunctionPointers(FunctionPointers &&ruleOfFive) noexcept = delete;         //III. MOVE CONSTRUCTOR
    FunctionPointers(const FunctionPointers &ruleOfThree) = delete;            // II. COPY CONSTRUCTOR
    FunctionPointers &operator=(const FunctionPointers &ruleOfThree) = delete; // III. COPY ASSIGNMENT
    ~FunctionPointers() =default;

    //C type functionPointer definition 
    typedef void (FunctionPointers::*func)(void);
    typedef std::function<void()> funcStd;
    typedef int (FunctionPointers::*funcParam)(int, int);
    typedef std::function<int(int,int)> funcParamStd;

    //Pass Function as a paremeter
    void callBackFunction(int pFirstVar, int pSecondVar, func func,FunctionPointers *givenClass);
    void callBackFunctionStd(int pFirstVar, int pSecondVar, funcStd func,FunctionPointers *givenClass);
    int callBackFunctionWithParams(int pFirstVar, int pSecondVar, funcParam func);
    int callBackFunctionWithParamsStd(int pFirstVar, int pSecondVar, funcParamStd func);
    void returnBiggestVariable();
    int multiplyProcess(int a,int b);

private:
    int firstVar;
    int secondVar;

};

#endif