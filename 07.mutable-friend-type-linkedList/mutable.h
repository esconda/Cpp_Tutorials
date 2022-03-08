#ifndef MUTABLE_H
#define MUTABLE_H

#include <iostream>
#include <functional>
//Author : Burak Dogancay
class MutableClass
{
public:
    MutableClass();
    MutableClass(const MutableClass &ruleOfThree);            // II. COPY CONSTRUCTOR
    MutableClass &operator=(const MutableClass &ruleOfThree); // III. COPY ASSIGNMENT
    ~MutableClass();       

    void mutableLambdas();
    double getPi() const;
                        
private:
    mutable bool pi_calculated = false;
    mutable bool pi = 0;
};
#endif