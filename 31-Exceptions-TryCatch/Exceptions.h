#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H

#include <iostream>
#include <chrono>

/* 
A try/catch block is used to catch exceptions. The code in the try section is the code that may throw an exception,
and the code in the catch clause(s) handles the exception.
Check Exceptions detaily
 */
class Exceptions
{
public:
    Exceptions();
    Exceptions(int val) = delete;
    Exceptions(Exceptions &&ruleOfFive) noexcept = delete;         //III. MOVE CONSTRUCTOR
    Exceptions(const Exceptions &ruleOfThree) = delete;            // II. COPY CONSTRUCTOR
    Exceptions &operator=(const Exceptions &ruleOfThree) = delete; // III. COPY ASSIGNMENT
    ~Exceptions() = default;                                            //Destructor

    void catching_Exception();
    void multipleCatch();
    void generalExceptions();
};

#endif