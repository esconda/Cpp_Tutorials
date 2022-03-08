#include "UAVBody.h"


UAVBody::UAVBody() {
    //void UAVBody::missionGeneration() {
    
}

UAVBody::UAVBody(const UAVBody& uavBody){// II. COPY CONSTRUCTOR

}
UAVBody &UAVBody::operator=(const UAVBody& uavBody){// III. COPY ASSIGNMENT

}   

UAVBody::~UAVBody() {
    //void UAVBody::missionGeneration() {
    
}

void UAVBody::flyOperations()  {
    std::cout<<"Fly Operations is processed"<<std::endl;
}

void UAVBody::malfunctionShow()  {
    std::cout<<"Malfunctions are showed"<<std::endl;
}

void UAVBody::bodyAxisOrientation() {
    
}

void UAVBody::motorSituation() {
    
}

void UAVBody::servoController() {
    
}

void UAVBody::controlIMU() {
    
}