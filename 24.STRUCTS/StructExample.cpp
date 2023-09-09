#include "StructExample.h"
typedef StructExample::PackConcenationProcess StructExamplePack;
StructExample::StructExample()
{
}

void StructExample::myVariableProcess(){
	MyVarStruct myVarStruct;
	int sumVars = 0;
	int extractVars = 0;

	sumVars = myVarStruct.myVariable1 + myVarStruct.myVariable2 + myVarStruct.myVariable3;
	extractVars = myVarStruct.myVariable1 - myVarStruct.myVariable2 - myVarStruct.myVariable3;

	std::cout<<"------ MY VARIABLE STRUCT EXAMPLE------"<<std::endl;
	std::cout<<"Sum of The Variables : "<<sumVars<<std::endl;
	std::cout<<"Extraction of the variables : "<< extractVars << std::endl;
	std::cout<<"----------------------------------------"<<std::endl; 
	std::cout << " "<< std::endl;
	}

void StructExamplePack::addPackage(char pDataPack) {

	if (pDataPack != NULL && pDataPack != '\0') {
		this->mSrcPack.push_back(pDataPack);
	}
	this->concatToVecPacks(this->mSrcPack, this->mSrcPack.size());
}

void StructExamplePack::concatToVecPacks(std::vector<char> &pRawDataPack,int pPackSize) {

	if (!pRawDataPack.empty()) {
		this->clearPackage(this->mDstPack);
		for (char& tData : pRawDataPack) {
			this->mDstPack.push_back(tData);
		}

		this->concatToIntVar();
	}
}

void StructExamplePack::concatToIntVar(){

	for (char& tData : this->mDstPack) {
		this->concatVariable = ((concatVariable << 8) + tData) & 0xFFFF;
		
	}
}

void StructExamplePack::clearPackage(std::vector<char>& pRawDataPack) {
	if (!pRawDataPack.empty()) {
		pRawDataPack.clear();
	}
	
}