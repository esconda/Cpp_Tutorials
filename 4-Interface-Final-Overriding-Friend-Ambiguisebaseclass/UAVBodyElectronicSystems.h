#ifndef UAVBODYELECTRONICSYSTEMS_H
#define UAVBODYELECTRONICSYSTEMS_H

#include "UAVBody.h"
//INTERFACE ALL METHODS ARE VIRTUAL,ABSTRACTCLASS
//INHERITANCE
//Principal of abstarction , you should make all data members private and provide getter and setter methods
class UAVBodyElectronicSystems : public UAVBody
{
public:
    UAVBodyElectronicSystems();
    //By default, C++ will provide a default constructor, copy constructor, copy assignment operator (operator=) and a destructor.
    //More useful than the default specifier is the delete specifier, which can be used to disallow a function from being defined or called. One of the best uses of the delete specifier is to make a class uncopyable:
    //The delete specifier can also be used to make sure member functions with particular parameters aren’t called.
    ~UAVBodyElectronicSystems(); //Always make your destructor virtual.Making base class destructor virtual guarantees that the object of derived class is destructed properly
    UAVBodyElectronicSystems(const UAVBodyElectronicSystems& uavBody);// II. COPY CONSTRUCTOR  
    UAVBodyElectronicSystems& operator=(const UAVBodyElectronicSystems& uavBody);// III. COPY ASSIGNMENT
    
    void showallelectronicSystems();

private:
    void mainmicroContrIOS();
    void mainmicroContrCOM();
    void mainmicroContrIMU();
    void servomicroContr();
};
#endif