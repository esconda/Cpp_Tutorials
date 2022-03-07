#include "TypeTraits.h"

TypeTraits::TypeTraits()
{
}

void TypeTraits::isContstant(){
    //This will evaluate as true when type is constant.
    /* Trait class that identifies whether T is a const-qualified type.
    It inherits from integral_constant as being either true_type or false_type, depending on whether T is const. */
    const int variable = 50;
    int variable2 = 100;
    std::cout <<" Is Const Varible : "<< std::is_const<decltype(variable)>::value<< std::endl; // Prints true.
    std::cout <<" Is Const Varible : "<< std::is_const<decltype(variable2)>::value<< std::endl; // Prints false.
}

void TypeTraits::isSigned(){
    //This will evaluate as true when the type is volatile
    int variable;
    unsigned int variable2;
    std::cout <<" Is Signed Varible : "<<std::is_signed<decltype(variable)>::value<< std::endl; // Prints true.
    std::cout <<" Is Signed Varible : "<< std::is_signed<decltype(variable2)>::value<< std::endl; // Prints false.

}

void TypeTraits::isUnsigned(){
    unsigned int variable;
    int variable2;
    std::cout <<" Is UnSigned Variable : "<<std::is_unsigned<decltype(variable)>::value<< std::endl; // Prints true.
    std::cout <<" Is UnSigned Variable : "<< std::is_unsigned<decltype(variable2)>::value<< std::endl; // Prints false.
}

void TypeTraits::isVolatile(){
    volatile int variable;
    int variable2;
    std::cout <<" Is Volatile Variable : "<<std::is_volatile<decltype(variable)>::value<< std::endl; // Prints true.
    std::cout <<" Is Volatile Variable : "<< std::is_volatile<decltype(variable2)>::value<< std::endl; // Prints false.
}

