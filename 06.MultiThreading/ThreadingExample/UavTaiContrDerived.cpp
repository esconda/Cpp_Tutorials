#include "UavTaiContrDerived.h"
UavTaiContrDerived::UavTaiContrDerived() 
{

}

UavTaiContrDerived::~UavTaiContrDerived()
{
    
}

void UavTaiContrDerived::tickUpdate(){
    showUavInfos();
}

void UavTaiContrDerived::someOtherFunctions(){
    taiInfo();
}

void UavTaiContrDerived::showUavInfos(){
    std::cout<<"Tai-Tusas"<<std::endl;
    std::cout<<"Aksungur"<<std::endl;
    std::cout<<"One of the best Uav"<<std::endl;
    std::cout<<"year of production : 2021"<<std::endl;
    std::cout<<"-----------------------------------"<<std::endl;
}

void UavTaiContrDerived::taiInfo(){
    static int incremet;
    incremet++;
    std::cout<<"----------Information :"<<incremet<<"-----"<<std::endl;
    std::cout<<"Tai : One of the best Defense Industry Company"<<std::endl;
}
