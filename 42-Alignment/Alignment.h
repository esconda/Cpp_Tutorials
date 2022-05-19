//Author: Burak Doğançay
#ifndef ALIGNMENT_H 
#define ALIGNMENT_H
#include <iostream>
#include <memory>
//All types in C++ have an alignment. This is a restriction on the memory address that objects of that type can be
//created within. A memory address is valid for an object's creation if dividing that address by the object's alignment
//is a whole number.
class Alignment
{
public:
    Alignment();
    void alignmentControl();
    void checkAlignment();
};

#endif