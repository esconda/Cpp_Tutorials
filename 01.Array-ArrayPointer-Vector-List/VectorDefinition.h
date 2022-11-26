#ifndef VECTORDEFINITION_H
#define VECTORDEFINITION_H

#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <cstddef>
#include <utility>
#include <iterator>
#include <algorithm>
#include <numeric>

#define print(a) std::cout << a
#define printNewLine(a, b) std::cout << a << b << std::endl
#pragma pack(push, 1)

class VectorClassEx;
//INTERFACE ALL METHODS ARE VIRTUAL,ABSTRACTCLASS
//INHERITANCE
//Principal of abstarction , you should make all data members private and provide getter and setter methods
using std::string;
class VectorDefinition
{
public:
    VectorDefinition();
    VectorDefinition(const VectorDefinition &ruleOfThree);            // II. COPY CONSTRUCTOR
    VectorDefinition &operator=(const VectorDefinition &ruleOfThree); // III. COPY ASSIGNMENT
    ~VectorDefinition();                                        //Alaways make your destructor virtual.Making base class destructor virtual guarantees that the object of derived class is destructed properly
    //Manage All Vectors
    void vectorManagement();

    void vectorInitializations(); //done
    void vectorAllOperations();   //done
    void vectorIteratorOp(); //done
    void vectorTransferOpStruct();//done
    void vectorTransferOpArray();
    void vectorStructArray(); //done
    void vectorDynamicAllocation();//done
    void vectorClassAproach();
    void correctWayOfVector();
    void copyOpOfTheVector();

private:
    std::vector<string> mStringVal;
    std::vector<string> mStringVal2;
    std::vector<string> mStringVal3;
    std::vector<string> mStringVal4;
    std::vector<string> *mStringVectRef;
    std::vector<string> mStringVal5 = {"Boeing","Akinci","Tb2","Aksungur","Anka"};

    std::vector<int> mIntegerVal;
    std::vector<int> mIntegerVal2;
    std::vector<int> mIntegerVal3;
    std::vector<int> mIntegerVal4;
    std::vector<float> *mFloatVectorRef;

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
    std::vector<UavProperties> mStructVector;

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