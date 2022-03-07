#include "UAVBodyElectronicSystems.h"


UAVBodyElectronicSystems::UAVBodyElectronicSystems() {
    
}
UAVBodyElectronicSystems::UAVBodyElectronicSystems(const UAVBodyElectronicSystems& uavBodyElectronicSystems){// II. COPY CONSTRUCTOR

}
UAVBodyElectronicSystems &UAVBodyElectronicSystems::operator=(const UAVBodyElectronicSystems& uavBodyElectronicSystems){// III. COPY ASSIGNMENT

}   

UAVBodyElectronicSystems::~UAVBodyElectronicSystems() {
    //void UAVBody::missionGeneration() {
    
}

void UAVBodyElectronicSystems::mainmicroContrIOS() {
    std::cout<<"Micro Control IOS"<<std::endl;
}

void UAVBodyElectronicSystems::mainmicroContrCOM() {
    std::cout<<"Micro Control Communication"<<std::endl;
}

void UAVBodyElectronicSystems::mainmicroContrIMU() {
    std::cout<<"Micro Control IMU"<<std::endl;
    
}

void UAVBodyElectronicSystems::servomicroContr() {
    std::cout<<"Micro Control ServoMicroControlle"<<std::endl;
    
}

void UAVBodyElectronicSystems::showallelectronicSystems(){
    //FROM BODY BASE
    flyOperations();
    malfunctionShow();

    //FOR THIS CLASS
    mainmicroContrIOS();
    mainmicroContrCOM();
    mainmicroContrIMU();
    servomicroContr();
}
