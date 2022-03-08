#ifndef UAVBODY_H
#define UAVBODY_H

#include "UAVBase.h"
//Author : Burak Dogancay
//INTERFACE ALL METHODS ARE VIRTUAL,ABSTRACTCLASS
//INHERITANCE
//Principal of abstarction , you should make all data members private and provide getter and setter methods
class UAVBody : public UAVBase
{
public:
    UAVBody();
    //By default, C++ will provide a default constructor, copy constructor, copy assignment operator (operator=) and a destructor.
    //More useful than the default specifier is the delete specifier, which can be used to disallow a function from being defined or called. One of the best uses of the delete specifier is to make a class uncopyable:
    //The delete specifier can also be used to make sure member functions with particular parameters aren’t called.
    ~UAVBody(); //Always make your destructor virtual.Making base class destructor virtual guarantees that the object of derived class is destructed properly
    UAVBody(const UAVBody& uavBody);// II. COPY CONSTRUCTOR  
    UAVBody& operator=(const UAVBody& uavBody);// III. COPY ASSIGNMENT

    //virtual void missionGeneration() ; //Cannot override final function
    virtual void flyOperations() override;
    virtual void malfunctionShow() override;
    void bodyAxisOrientation();
    void motorSituation();
    void servoController();
    void controlIMU();

public:
int def = 50;
    };

#endif