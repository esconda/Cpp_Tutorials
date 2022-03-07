#ifndef CASTING_H
#define CASTING_H
#include <iostream>
#include "math.h"

class Casting
{
public:
    Casting();
    Casting(int val) = delete;
    Casting(Casting &&ruleOfFive) noexcept = delete;         //III. MOVE CONSTRUCTOR
    Casting(const Casting &ruleOfThree) = delete;            // II. COPY CONSTRUCTOR
    Casting &operator=(const Casting &ruleOfThree) = delete; // III. COPY ASSIGNMENT
    ~Casting() = default; //Destructor

    void constCastEx();
    void staticCastEx();
    void dynamicCastEx();
    void reinterpretCastEx();
    void enumConversion();
    void voidPointertoTpointer();
    
};
#endif