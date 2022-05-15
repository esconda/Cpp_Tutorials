#include "TypeDeduction.h"

TypeDeduction::TypeDeduction()
{
}

void TypeDeduction::autoTypeDeduction(){
    int* var ; 
    const int* constVar;
    const int* const constTopVar = constVar;

   // We have three different pointers, all of type int. They are getting more and more constified. The question is what’s the type that is deduced by auto? All are pointers, 
    //that’s for sure. But what happens with the const? auto removes all top-level qualifier. Hence, even the const disappears. Does it? Here is the output C++ Insights gives:
    auto avar = var; // Auto is int*
    auto aconstVar= constVar; //auto is const int *
    auto aconstTopVar = constTopVar; // auto is const int *

    //Yes, the top-level const is removed. A constant pointer does not matter, so this const is discarded, but the constness of the memory behind it sticks. 
    //Hence, this const is preserved. Which is why acip looks exactly like acicp. This makes sense right.
}

void TypeDeduction::dclTypeAuto(){
    int* var ; 
    const int* constVar;
    const int* const constTopVar = constVar;

    //We can see, that acicp does carry the second const which is lost when we just use auto.
    decltype(auto) avar = var; // Auto is int*
    decltype(auto) aconstVar= constVar; //auto is const int *
    decltype(auto) aconstTopVar = constTopVar; // auto is const int *

    
}

void TypeDeduction::anotherAutoTypeDedeuction(){
    auto x = 27; // (x is neither a pointer nor a reference), x's type is int
    const auto cx = x; // (cx is neither a pointer nor a reference), cs's type is const int
    const auto& rx = x; // (rx is a non-universal reference), rx's type is a reference to a const int

    auto&& uref1 = x; // x is int and lvalue, so uref1's type is int&
    auto&& uref2 = cx; // cx is const int and lvalue, so uref2's type is const int &
    auto&& uref3 = 27; // 27 is an int and rvalue, so uref3's type is int&&
    //auto x5 = { 1, 2.0 }; // error! can't deduce T for std::initializer_list<t>

    int* p = new int(42);
    auto y = *p; // x has type int
    decltype(auto) z = *p; // y is a reference to *p
}
template<typename T>
void TypeDeduction::f(T& param){
    std::cout<<"Parameter Values:"<<param<<std::endl;
}

void TypeDeduction::templateTypeDeduction(){
    int x = 27; // x is an int
    const int cx = x; // cx is a const int
    const int& rx = x; // rx is a reference to x as a const int

    f(x); // T is int, param's type is int&
    f(cx); // T is const int, param's type is const int&
    f(rx); // T is const int, param's type is const int&
}