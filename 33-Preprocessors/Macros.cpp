#include "Macros.h"

Macros::Macros()
{
}

void Macros::macroFuncExample(){
    #define PI 3.14
    #define  BAD_AREA(r) PI * r * r

    double bad_area = BAD_AREA(20);
    std::cout<<"Bad area for macro function : "<<bad_area<<std::endl;
}

void Macros::macroFuncSecondEx(){
    #define TEXT "I \
                 AM \
                 BURAK \
                 DOGANCAY"
    std::cout<<"Macro Multiple Line Integration : "<<TEXT<<std::endl;

}

void Macros::complexFunctionMacros(){
    #define WRITETEXT(Str) std::string *tmp = new std::string(Str); std::cout<<" String is : "<< *tmp <<std::endl; delete tmp;
    WRITETEXT("String is defined by macros"); 
}

void Macros::moreComplexFunctionMacro(){
  /*  #define DO_STUFF(Type, Param, ReturnVar) do { \
                                                Type temp(some_setup_values); \
                                                ReturnVar = temp.process(Param); \
                                                } while (0)
    int x;
    DO_STUFF(MyClass, 41153.7, x); */
}

void Macros::variadicFunctionMacro(){
  /*   There are also variadic macros; similarly to variadic functions, these take a variable number of arguments, and then
expand them all in place of a special "Varargs" parameter, __VA_ARGS__ */
    #define VARIADIC(Param, ...) Param<<__VA_ARGS__<<std::endl

    VARIADIC(std::cout,"Variable Number: "<<20);
}

void Macros::preprocessorOperatorsFirstEx(){
  /*   # operator or stringizing operator is used to convert a Macro parameter to a string literal. It can only be used with
the Macros having arguments. */
    #define PRINT(x) std::cout<<#x<<std::endl
    PRINT(This line will be converted to string by preprocessor);
}

void Macros::preprocessorOperatorSecondEX(){
    /* ## operator or Token pasting operator is used to concatenate two parameters or tokens of a Macro. */
    #define ANOTHERPRINT(x) std::cout<<"variable : "<<variable##x<<std::endl
    int variableY=15;
    ANOTHERPRINT(Y);
}

void Macros::preprocessorErrorMessage(){
   /*  Compile errors can be generated using the preprocessor. This is useful for a number of reasons some of which
include, notifying a user if they are on an unsupported platform or an unsupported compiler. */
/* #ifndef __APPLE__ 
#error "Apple product is not suıpported on windows"
#endif */
}