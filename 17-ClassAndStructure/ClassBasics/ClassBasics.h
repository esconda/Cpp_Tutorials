#ifndef CLASSBASICS_H
#define CLASSBASICS_H

#include <iostream>
#include <cstring>
#include <functional>
//Author : Burak Dogancay
struct ClassBasics1
{
    /* data */
    int x;
    int y;
    int z;
};

//ClassBasics1 is equal to ClassBasics
class ClassBasics
{
public:
    ClassBasics();
    ClassBasics(int val);
    ClassBasics(const ClassBasics &ruleOfThree);            // II. COPY CONSTRUCTOR
    ClassBasics &operator=(const ClassBasics &ruleOfThree); // III. COPY ASSIGNMENT
    ~ClassBasics();

    int x;
    int y;
    int z;

};
#endif