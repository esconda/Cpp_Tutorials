#include <iostream>
#include <memory>
#include "ConstExamples.h"
#include <functional>
class SmartPointers
{
public:
    SmartPointers();
    ~SmartPointers();
    void conditionalOperator();
    double lambdaexample();
    double lambdaexample2(int pParam);

    //Another lambda example
    int x,y;
    int operator()(int);
    void lambdaexample3();

    //Lambda Definitions
    void lambdaDef(int i);
    void lambdaDef2(int i);

    //SmartPointers
    //Smart pointers are used to avoid memory leaks which is occured in dunamic memory allocation
    std::shared_ptr<ConstExamples> mConstExampSh;
    std::unique_ptr<ConstExamples> mConstExampUn;
private:
    double mDoubleVar;
};