#ifndef TYPETRAITS_H
#define TYPETRAITS_H
#include <iostream>
#include <type_traits>

class TypeTraits
{
public:
    TypeTraits();
    TypeTraits(int val) = delete;
    TypeTraits(TypeTraits &&ruleOfFive) noexcept = delete;         //III. MOVE CONSTRUCTOR
    TypeTraits(const TypeTraits &ruleOfThree) = delete;            // II. COPY CONSTRUCTOR
    TypeTraits &operator=(const TypeTraits &ruleOfThree) = delete; // III. COPY ASSIGNMENT
    ~TypeTraits() = default; //Destructor

    //TYPE PROPERTIES
    void isContstant();
    void isVolatile();
    void isSigned();
    void isUnsigned();

    
    
};
#endif