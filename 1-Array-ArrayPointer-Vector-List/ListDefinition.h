#ifndef LISTDEFINITION_H
#define LISTDEFINITION_H

#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <cstddef>
#include <utility>
#include <iterator>
#include <algorithm>
#include <numeric>
#include <list>

#define print(a) std::cout << a
#define printNewLine(a, b) std::cout << a << b << std::endl
#pragma pack(push, 1)
//Author : Burak Dogancay
//INTERFACE ALL METHODS ARE VIRTUAL,ABSTRACTCLASS
//INHERITANCE
//Principal of abstarction , you should make all data members private and provide getter and setter methods
using std::string;
class ListDefinition
{
public:
    ListDefinition();
    ListDefinition(const ListDefinition &ruleOfThree);            // II. COPY CONSTRUCTOR
    ListDefinition &operator=(const ListDefinition &ruleOfThree); // III. COPY ASSIGNMENT
    ~ListDefinition();                                       
    //Manage All Vectors
    void listManagement();

    void listInitializations(); //done
    void listAllOperations();   //done
    void listIteratorOp(); //done
    void listTransferOpStruct();//done
    void listTransferOpArray();
    void listStructArray(); //done
    void listDynamicAllocation();//done

private:
    std::list<string> mStringVal;
    std::list<string> mStringVal2;
    std::list<string> mStringVal3;
    std::list<string> mStringVal4;
    std::list<string> *mStringVectRef;
    std::list<string> mStringVal5 = {"Boeing","Akinci","Tb2","Aksungur","Anka"};

    std::list<int> mIntegerVal;
    std::list<int> mIntegerVal2;
    std::list<int> mIntegerVal3;
    std::list<int> mIntegerVal4;
    std::list<float> *mFloatVectorRef;

private:
//FIRST PHASE    
typedef struct UAVProperties
    {
        UAVProperties()
        {
            electronicSys = "Electronic_Systems";
            servoSys = "Servo_Motors";
            IMUSys = "Imu_Systems";
            motorSys = "Motor_Systems";
        }
        string electronicSys;
        string servoSys;
        string IMUSys;
        string motorSys;
    } UavProperties;  
    std::list<UavProperties> mStructVector;

typedef struct UAVProperties2
    {
        
        char electronicSys[19] = "Electronic_Systems";
        char servoSys[13] = "Servo_Motors";
        char IMUSys[12]="Imu_Systems";
        char motorSys[14]="Motor_Systems";
    } UavProperties2;  

protected:
    int count;
};
#pragma pack(pop)
#endif