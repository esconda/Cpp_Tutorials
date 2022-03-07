#ifndef TYPETRAITS_H
#define TYPETRAITS_H
#include <iostream>
#include <type_traits>

//Author : Burak Dogancay

/* SFINAE
 C++ C++ language Templates 
"Substitution Failure Is Not An Error"

This rule applies during overload resolution of function templates: 
When substituting the explicitly specified or deduced type for the template parameter fails, 
the specialization is discarded from the overload set instead of causing a compile error.
This feature is used in template metaprogramming. */
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

    //STANDARD TYPE TRAITS
    void staticAssert();
    void enableif();
    void isPointer();

    //TYPE RELATION
    void is_same();
    void is_same_Alternative();
    
};
#endif