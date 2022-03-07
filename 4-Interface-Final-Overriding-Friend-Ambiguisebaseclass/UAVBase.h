#ifndef UAVBASE_H
#define UAVBASE_H

#include <iostream>
#include <vector>
#include <cstring>
#include <cstddef>
#include <utility>
//Author : Burak Dogancay
//INTERFACE ALL METHODS ARE VIRTUAL,ABSTRACTCLASS
//INHERITANCE
//Principal of abstarction , you should make all data members private and provide getter and setter methods
class UAVBase
{
public:
  
    virtual ~UAVBase(){}//Always make your destructor virtual.Making base class destructor virtual guarantees that the object of derived class is destructed properly

    //virtual void missionGeneration() final  ; //preventing overriding method 
    virtual void flyOperations() = 0; // or use "= default"
    virtual void malfunctionShow() = 0;

    };
    static_assert(sizeof(UAVBase) > 1, "No pointer to vtable");

#endif