//Author: Burak Doğançay
#ifndef UNDEFINEDBEHAVIOUR_H 
#define UNDEFINEDBEHAVIOUR_H
#include <iostream>
#include <memory>

//Undefined behaviour means that when a program encounters UB, it is allowed to do whatever it wants. This often means a crash,
//but it may simply do nothing, make demons fly out of your nose, or even appear to work properly!
class UndefinedBehaviour
{
public:
    UndefinedBehaviour();
    void readingOrWritingnullPointer();
    void unInitVariable();
    void accessOutOfBoundsIndex();
    void noVirtualDestructorDerivedObject();
    void invalidPointerArithmetic();
    int nonreturnTypeUB();

    inline int& getVar(){
        int x=42;
        return x;
    }
    void accessDanglingReference();

    void intDivisionByZero();
    void shiftingInvalidNumber();
    void incorrectPairingMemAlloc();
    void signedIntegerOverflow();
    void modifyConstObj();
    void returnFromFunction();
    void infTemplateRecursion();
    void overflowDuringConv();
    void modifyingStringLiteral();
    void accessWrongTypeObj();
    void destroyDestroyedObj();
    void floatingPointOverflow();
    void funCallMismatchPointerType();
};

#endif