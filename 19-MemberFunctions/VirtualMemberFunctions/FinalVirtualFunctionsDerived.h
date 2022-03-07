#ifndef FINALVIRTUALFUNCTIONSDERIVED_H
#define FINALVIRTUALFUNCTIONSDERIVED_H

#include <iostream>
#include <cstring>
#include <functional>
#include "FinalVirtualFunctionsBase.h"
#include "FinalVirtualFunctionsBase.cpp"

/* We can also specify that a virtual function is pure virtual(abstract), by appending = 0 to the declaration.Classes with one or more pure virtual functions are 
considered to be abstract, and cannot be instantiated; only derived
classes which define, or inherit definitions for, all pure virtual functions can be instantiated. 

*If we want to create a class that can't itself be instantiated, but doesn't prevent its derived classes from being
instantiated, we can declare the destructor as pure virtual. Being the destructor, it must be defined anyways,
if we want to be able to deallocate the instance. And as the destructor is most likely already virtual to prevent
memory leaks during polymorphic use, we won't incur an unnecessary performance hit from declaring
another function virtual. This can be useful when making interfaces.
*/
class FinalVirtualFunctionsDerived : public FinalVirtualFunctionsBase
{
public:
    FinalVirtualFunctionsDerived();
    FinalVirtualFunctionsDerived(int val) = delete;
    FinalVirtualFunctionsDerived(FinalVirtualFunctionsDerived &&ruleOfFive) noexcept = delete;         //III. MOVE CONSTRUCTOR
    FinalVirtualFunctionsDerived(const FinalVirtualFunctionsDerived &ruleOfThree) = delete;            // II. COPY CONSTRUCTOR
    FinalVirtualFunctionsDerived &operator=(const FinalVirtualFunctionsDerived &ruleOfThree) = delete; // III. COPY ASSIGNMENT
    ~FinalVirtualFunctionsDerived() = default;

    virtual void overridingFunc() override;
    virtual void overridingFunc2() override;
};

#endif