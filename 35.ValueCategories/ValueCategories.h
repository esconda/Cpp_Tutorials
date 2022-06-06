#ifndef VALUECATEGORIES_H
#define VALUECATEGORIES_H

#include <iostream>
#include <chrono>
#include <functional>
#include <memory>
//Author : Burak Dogancay

class ValueCategories
{
public:
    ValueCategories();
    ValueCategories(int val) = delete;
    ValueCategories(ValueCategories &&ruleOfFive) noexcept = delete;         //III. MOVE CONSTRUCTOR
    ValueCategories(const ValueCategories &ruleOfThree) = delete;            // II. COPY CONSTRUCTOR
    ValueCategories &operator=(const ValueCategories &ruleOfThree) = delete; // III. COPY ASSIGNMENT
    ~ValueCategories() = default; //Destructor

/*     An rvalue expression is any expression which can be implicitly moved from, regardless of whether it has identity.
More precisely, rvalue expressions may be used as the argument to a function that takes a parameter of type T &&
(where T is the type of expr). Only rvalue expressions may be given as arguments to such function parameters; if a
non-rvalue expression is used, then overload resolution will pick any function that does not use an rvalue reference
parameter. And if none exist, then you get an error. */

 void rValueExamples();
 void xValueExample();
 void prValueExample();
 void lValueExample();
 void glValueExample();

};

#endif