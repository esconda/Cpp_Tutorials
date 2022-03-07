#include "ClassBasics/ClassBasics.h"
#include "FinalClassAndStructs/FinalClassAndStructs.h"
#include "AccessSpecifier/AccessSpecifier.h"
#include <iostream>
#include "ClassBasics/ClassBasics.cpp"
#include "FinalClassAndStructs/FinalClassAndStructs.cpp"
#include "AccessSpecifier/AccessSpecifier.cpp"
int main()
{
    ClassBasics classBasics;
    ClassBasics1 classBasics1;
    AccessSpecifier accessSpecifier;

    //Enter data of the classBasics
    classBasics.x = 20;
    classBasics.y = 30;
    classBasics.z = 50;

    //Enter data of the classBasics1
    classBasics1.x = 60;
    classBasics1.y = 80;
    classBasics1.z = 100;

    //print all values
    std::cout << "Class Basics Data : "
              << " " << classBasics.x << " " << classBasics.y << " " << classBasics.z << std::endl;
    std::cout << "Class Basics1 Data : "
              << " " << classBasics1.x << " " << classBasics1.y << " " << classBasics.z << std::endl;
    //------------------------------------------------------------

    //Access Specifier
    std::cout<<"Public Value : "<<accessSpecifier.c<<std::endl;
    accessSpecifier.accessPrivateVal();
    accessSpecifier.accessProtectedVal();
    //------------------------------------------------------------
}