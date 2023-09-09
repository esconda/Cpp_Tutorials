#include "StructExample.h"
#include <iostream>

int main()
{
    
    
    std::unique_ptr<StructExample> structExmp = std::make_unique<StructExample>();

    structExmp.get()->myVariableProcess();

    //PACK CONCATANATION
    StructExample::PackConcenationProcess tconcatVariables;
    char pack1 = 0x01;
	char pack2 = 0x04;
    tconcatVariables.clearPackage(tconcatVariables.mSrcPack);
	tconcatVariables.addPackage(pack1);
	tconcatVariables.addPackage(pack2);
    std::cout << "First Pack : " << std::bitset<8>(tconcatVariables.mDstPack[0])<< std::endl;
	std::cout << "Second Pack : " << std::bitset<8>(tconcatVariables.mDstPack[1])<< std::endl;
	std::cout << "Conatanated Variable : " << tconcatVariables.concatVariable<<std::endl;
    std::cout << " "<< std::endl;
    //------------------------

    //Baykar uav ınfo
    std::cout<< "### BAYKAR UAV INFOS ###: "<<std::endl;
    std::cout<< "UAV NAME: "<<structExmp.get()->baykarUavInfo.name<<std::endl;
    std::cout<< "UAV TYPE: "<<structExmp.get()->baykarUavInfo.type<<std::endl;
    std::cout<< "UAV COMPANY: "<<structExmp.get()->baykarUavInfo.company<<std::endl;
    std::cout<< "########################: "<<std::endl;
    std::cout << " "<< std::endl;
    //---------------
   //enumExample.iterator_over_enum();
}