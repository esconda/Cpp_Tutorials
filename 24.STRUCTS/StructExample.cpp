#include "StructExample.h"
typedef StructExample::PackConcenationProcess StructExamplePack;
StructExample::StructExample()
{
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