#include "TypeTraits.h"

TypeTraits::TypeTraits()
{
}

void TypeTraits::isContstant()
{
    // This will evaluate as true when type is constant.
    /* Trait class that identifies whether T is a const-qualified type.
    It inherits from integral_constant as being either true_type or false_type, depending on whether T is const. */
    const int variable = 50;
    int variable2 = 100;
    std::cout << " Is Const Varible : " << std::is_const<decltype(variable)>::value << std::endl;  // Prints true.
    std::cout << " Is Const Varible : " << std::is_const<decltype(variable2)>::value << std::endl; // Prints false.
}

void TypeTraits::isSigned()
{
    // This will evaluate as true when the type is volatile
    int variable;
    unsigned int variable2;
    std::cout << " Is Signed Varible : " << std::is_signed<decltype(variable)>::value << std::endl;  // Prints true.
    std::cout << " Is Signed Varible : " << std::is_signed<decltype(variable2)>::value << std::endl; // Prints false.
}

void TypeTraits::isUnsigned()
{
    unsigned int variable;
    int variable2;
    std::cout << " Is UnSigned Variable : " << std::is_unsigned<decltype(variable)>::value << std::endl;  // Prints true.
    std::cout << " Is UnSigned Variable : " << std::is_unsigned<decltype(variable2)>::value << std::endl; // Prints false.
}

void TypeTraits::isVolatile()
{
    volatile int variable;
    int variable2;
    std::cout << " Is Volatile Variable : " << std::is_volatile<decltype(variable)>::value << std::endl;  // Prints true.
    std::cout << " Is Volatile Variable : " << std::is_volatile<decltype(variable2)>::value << std::endl; // Prints false.
}
// standard type traıts
void TypeTraits::isPointer()
{
    unsigned int *variable;
    unsigned int variable2;
    static_assert(std::is_pointer<decltype(variable)>::value, "Variable must be pointer");
    // static_assert(std::is_pointer<decltype(variable2)>::value,"Variable must be pointer");
}

// Type relations
void TypeTraits::is_same()
{
    // Prints true on most x86 and x86_64 compilers.
    std::cout << "int, int32 is same ? : " << std::is_same<int, int32_t>::value << "\n";
    // Prints false on all compilers.
    std::cout << "float, int is same ? : " << std::is_same<float, int>::value << "\n";
    // Prints false on all compilers.
    std::cout << "unsigned int, int is same ? : " << std::is_same<unsigned int, int>::value << "\n";
}
void TypeTraits::is_same_Alternative()
{
    struct foo
    {
        int member;
        // Other variables
    };
    struct bar
    {
        char member;
    };
    std::cout << "foo and bar is same ? : " << std::is_same<bar, foo>::value << "\n";
}

// CLASSIC TYPE TRAITS
void TypeTraits::isIntegral()
{
    std::cout << "Is int Integral : " << std::is_integral<int>::value << "\n";     // Prints true.
    std::cout << "Is char Integral : " << std::is_integral<char>::value << "\n";   // Prints true.
    std::cout << "Is float Integral : " << std::is_integral<float>::value << "\n"; // Prints false
}

void TypeTraits::isFloatingPoint()
{
    std::cout << "Is float floating : " << std::is_floating_point<float>::value << "\n";   // Prints true.
    std::cout << "Is double floating : " << std::is_floating_point<double>::value << "\n"; // Prints true.
    std::cout << "Is char floating : " << std::is_floating_point<char>::value << "\n";     // Prints false.
}

void TypeTraits::isEnum()
{
    enum UAV
    {
        TB2,
        TB3,
        Anka
    };
    enum class Advanced_UAV
    {
        Akinci,
        Aksungur,
        MQ-1_Predator
    };
    std::cout <<"Is Enum" std::is_enum<UAV>::value << "\n";     // Prints true.
    std::cout <<"Is Enum" std::is_enum<Advanced_UAV>::value << "\n"; // Prints true.
    std::cout <<"Is int Enum" std::is_enum<int>::value << "\n";       // Prints false
}
