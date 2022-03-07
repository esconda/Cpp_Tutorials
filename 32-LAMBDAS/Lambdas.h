#ifndef LAMBDAS_H
#define LAMBDAS_H

#include <iostream>
#include <chrono>
#include <functional>
#include <memory>
/* 
A lambda expression provides a concise way to create simple function objects. A lambda expression is a prvalue
whose result object is called closure object, which behaves like a function object
 In such cases, lambda
expressions are generally preferred because they allow defining the function objects inline
 */
class Lambdas
{
public:
    Lambdas();
    Lambdas(int val) = delete;
    Lambdas(Lambdas &&ruleOfFive) noexcept = delete;         //III. MOVE CONSTRUCTOR
    Lambdas(const Lambdas &ruleOfThree) = delete;            // II. COPY CONSTRUCTOR
    Lambdas &operator=(const Lambdas &ruleOfThree) = delete; // III. COPY ASSIGNMENT
    ~Lambdas() = default;           //Destructor

    struct LambdaStruct{
        LambdaStruct(){
            lambdaVariable = 0;
        }
        int lambdaVariable;
    }lambdaStruct;
    
    void lambdaDef(int i);
    void lambdaDef2(int i);
    void captureList();
    void parameterList();         
    void callingLambda();      
    void specifiyingReturnType();
    void captureByValue(); 
    void captureByValueSecond();
    void recursiveLambdas();
    void defaultCapture();   
    void classLambdaEx();     
    void captureByReference();
    void genericLambdas();
    void generilizedCapture();



};

#endif