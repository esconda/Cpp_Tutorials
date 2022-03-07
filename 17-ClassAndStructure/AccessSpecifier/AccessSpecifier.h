#ifndef ACCESSSPECIFIER_H
#define ACCESSSPECIFIER_H

#include <iostream>
#include <cstring>
#include <functional>

//ClassBasics1 is equal to ClassBasics
/* public Everyone has access
protected Only the class itself, derived classes and friends have access
private Only the class itself and friends have access */

//Access specifiers are mostly used to limit access to internal fields and methods, and force the programmer to use a
//specific interface, for example to force use of getters and setters instead of referencing a variable directly:

//Using protected is useful for allowing certain functionality of the type to be only accessible to the derived classes,
class AccessSpecifier
{
public:
    AccessSpecifier();
    AccessSpecifier(int val);
    AccessSpecifier(const AccessSpecifier &ruleOfThree); // II. COPY CONSTRUCTOR
    AccessSpecifier &operator=(const AccessSpecifier &ruleOfThree);            // III. COPY ASSIGNMENT
    ~AccessSpecifier();

    void accessPrivateVal();
    void accessProtectedVal();

    const int c = 10;

private:
    const int a = 5;
    const int b = 6;
    
protected:
    const int d = 20;
    const int e = 30;    
};

#endif