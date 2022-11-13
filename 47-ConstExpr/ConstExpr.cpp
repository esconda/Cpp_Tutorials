// Author: Burak Doğançay
#include "ConstExpr.h"

ConstExpr::ConstExpr()
{
}

void ConstExpr::constExpVariable(){
    /* A variable declared constexpr is implicitly const and its value may be used as a constant expression.
    constexpr should not be defined inside of class , beacuse it will be created at compile time
    Comparison with #define
    A constexpr is type-safe replacement for #define based compile-time expressions. With constexpr the compiletime evaluated expression is replaced with the result. For example: */
    constexpr int constExprVar = 10 + 2;
    std::cout <<"Cont expressioın variable is : "<< constExprVar;

    //However, the compiler would have to do more work. Also, it creates a problem if not used correctly with define

    /* A const variable is a variable which needs memory for its storage. A constexpr does not. A constexpr produces
    compile time constant, which cannot be changed. You may argue that const may also not be changed. But
    consider: */

    const int arrSize1 = 50;
    const int arrSize2 = abs(10);
    int arr_one[arrSize1];
    int arr_two[arrSize2];

    /* With most compilers the second statement will fail (may work with GCC, for example). The size of any array, as you
    might know, has to be a constant expression (i.e. results in compile-time value). The second variable size2 is
    assigned some value that is decided at runtime (even though you know it is 10, for the compiler it is not compiletime).

    This means that a const may or may not be a true compile-time constant. You cannot guarantee or enforce that a
    particular const value is absolutely compile-time. You may use #define but it has its own pitfalls. */


    constexpr int arrSizeX = 100;
    int myArr[arrSizeX];


    /* A constexpr expression must evaluate to a compile-time value. Thus, you cannot use:
    Version ≥ C++11 */
    constexpr int size = abs(10);
    //Unless the function (abs) is itself returning a constexpr.
    

    /* All basic types can be initialized with constexpr.
    Version ≥ C++11 */ 
    constexpr bool FailFatal = true;
    constexpr float PI2 = 3.14f;
    constexpr char* site= "StackOverflow";


   /*  Interestingly, and conveniently, you may also use auto:
    Version ≥ C++11 */
    constexpr auto domain = ".COM"; // const char * const domain = ".COM"
    constexpr auto PI = 3.14; // constexpr double
}

void ConstExpr::staticIfStatement(){

    /* if constexpr is distinct from #ifdef. #ifdef conditionally compiles code, but only based on conditions that can be
    evaluated at preprocessing time. For example, #ifdef could not be used to conditionally compile code depending
    on the value of a template parameter. On the other hand, if constexpr cannot be used to discard syntactically
    invalid code, while #ifdef can. */
    if constexpr(false) {
        foobar; // error; foobar has not been declared
        std::vector<int> v("hello, world"); // error; no matching constructor
    }

}

void ConstExpr::constExprFunction(){

    /* A function that is declared constexpr is implicitly inline and calls to such a function potentially yield constant
        expressions. For example, the following function, if called with constant expression arguments, yields a constant
        expression too: 
        
        */

       //Version ≥ C++11
    constexpr int Sum(int a, int b)
    {
        return a + b;
    }

    /* Thus, the result of the function call may be used as an array bound or a template argument, or to initialize a
    constexpr variable: */


    constexpr int S = Sum(10,20);
    int Array[S];
    int Array2[Sum(20,30)]; // 50 array size, compile time

    /* Note that if you remove constexpr from function's return type specification, assignment to S will not work, as S is a
    constexpr variable, and must be assigned a compile-time const. Similarly, size of array will also not be a constantexpression, if function Sum is not constexpr. */

    //Interesting thing about constexpr functions is that you may also use it like ordinary functions:
    int a = 20;
    auto sum = Sum(a, abs(-20));

    /* Sum will not be a constexpr function now, it will be compiled as an ordinary function, taking variable (non-constant)
    arguments, and returning non-constant value. You need not to write two functions. */

    //It also means that if you try to assign such call to a non-const variable, it won't compile:
    int ab = 20;
    constexpr auto sum = Sum(ab, abs(-20));

    /* The reason is simple: constexpr must only be assigned a compile-time constant. However, the above function call
    makes Sum a non-constexpr (R-value is non-const, but L-value is declaring itself to be constexpr). */

    //The constexpr function must also return a compile-time constant. Following will not compile:
    constexpr int Sum(int a, int b)
    {
        int a1 = a; // ERROR
        return a + b;
    }

    //Because a1 is a non-constexpr variable, and prohibits the function from being a true constexpr function. Making it
    //onstexpr and assigning it a will also not work - since value of a (incoming parameter) is still not yet known:
    constexpr int Sum(int a, int b)
    {
        constexpr int a1 = a; // ERROR
        return a1;
    }

    //Furthermore, following will also not compile:
    constexpr int Sum(int a, int b)
    {
        return abs(a) + b; // or abs(a) + abs(b)
    }
    //Since abs(a) is not a constant expression (even abs(10) will not work, since abs is not returning a constexpr int !
    
}