#ifndef POINTERBASICS_H
#define POINTERBASICS_H

#include <iostream>
#include <functional>


//Enum and struct also keyword"
class PointerBasics
{
public:
    PointerBasics();
    PointerBasics(int val);
    PointerBasics(const PointerBasics &ruleOfThree);            // II. COPY CONSTRUCTOR
    PointerBasics &operator=(const PointerBasics &ruleOfThree); // III. COPY ASSIGNMENT
    ~PointerBasics();

    void print();
    void pointerOperations();
    void creatingPointerVariable();

  
   
};
#endif