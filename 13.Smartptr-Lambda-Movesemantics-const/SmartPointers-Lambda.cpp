#include "SmartPointers-Lambda.h"


SmartPointers::SmartPointers() : mConstExampSh(nullptr),
                                 mConstExampUn(nullptr),
                                 mDoubleVar(0.6),
                                 x(6),
                                 y(7)

{
    //Define shared pointer
    mConstExampSh = std::make_shared<ConstExamples>();

    //Define unique pointer
    mConstExampUn = std::make_unique<ConstExamples>();
}

void SmartPointers::conditionalOperator()
{
    int tVal = 50;
    mConstExampSh->GetScore(true) = 'T';
    mConstExampUn->GetScore(false) = 'F';

    //Conditional Operator
    tVal > 25 ? std::cout << "Const Example Dynamic Allocation : " << mConstExampSh->GetScore(true) << std::endl : std::cout << "Value is less than 25" << std::endl; //conditional operator can be used like if/else i>2 ? "yes" : "no"
    tVal > 25 ? std::cout << "Const Example Dynamic Allocation : " << mConstExampUn->GetScore(false) << std::endl : std::cout << "Value is less than 25" << std::endl;
}

double SmartPointers::lambdaexample()
{
    const std::function<double()> lambdadouble = [=]() { //Capture all variables by value ,Lambda expression
        return mDoubleVar;
    };
    double tDoubleVar;
    tDoubleVar = lambdadouble();

    std::cout << "Double Varibale by lambda : " << tDoubleVar<< std::endl;
    return tDoubleVar;
}

double SmartPointers::lambdaexample2(int pParam)
{
    
    std::function<double(int&)> lambdadouble = [&](int &tParam) {
        return static_cast<double>(tParam);
    };
    std::cout <<"Double var by adress : "<<lambdadouble(pParam)<< std::endl;
    return lambdadouble(pParam);
}

void SmartPointers::lambdaexample3(){
    [=]()->int{
        std::cout<<"Lambda Sum Variables : "<<(this->x+y)<< std::endl;
        return operator()(this->x+y);
    };   
}

void SmartPointers::lambdaDef(int i){
    [&]{};          // OK: by-reference capture default
    [&, i]{};       // OK: by-reference capture, except i is captured by copy
    //[&, &i] {};     // Error: by-reference capture when by-reference is the default
    [&, this] {};   // OK, equivalent to [&]
    [&, this, i]{}; // OK, equivalent to [&, i]
}

void SmartPointers::lambdaDef2(int i){
    [=]{};          // OK: by-copy capture default
    [=, &i]{};      // OK: by-copy capture, except i is captured by reference
   // [=, *this]{};   // until C++17: Error: invalid syntax
                    // since c++17: OK: captures the enclosing S2 by copy
    [=, this] {};   // until C++20: Error: this when = is the default
                    // since C++20: OK, same as [=]
}

SmartPointers::~SmartPointers()
{
}