#include "UavBaykarContrDerived.h"
UavBaykarContrDerived::UavBaykarContrDerived() 
{

}

UavBaykarContrDerived::~UavBaykarContrDerived()
{
    
}

void UavBaykarContrDerived::tickUpdate(){
    showUavInfos();
}

void UavBaykarContrDerived::someOtherFunctions(){
    bayKarInfo();
}

void UavBaykarContrDerived::showUavInfos(){
    std::cout<<"Baykar Makina"<<std::endl;
    std::cout<<"Kizil Elma"<<std::endl;
    std::cout<<"One of the best Uav"<<std::endl;
    std::cout<<"year of production : 2023"<<std::endl;
    std::cout<<"-----------------------------------"<<std::endl;
}

void UavBaykarContrDerived::bayKarInfo(){
    static int incremet;
    incremet++;
    std::cout<<"----------Information :"<<incremet<<"-----"<<std::endl;
    std::cout<<"Baykar : One of the best Defense Industry Company"<<std::endl;
}
