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
	std::cout << "Conatanated Variable : " << tconcatVariables.concatVariable;
    //------------------------
   
   //enumExample.iterator_over_enum();
}