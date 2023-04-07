#ifndef STRUCTEXAMPLE_H
#define STRUCTEXAMPLE_H

#include <iostream>
#include <cstring>
#include <functional>
#include <map>
#include <vector>
#include <memory>
#include <bitset>
//Author : Burak Dogancay

class StructExample
{
public:
    StructExample();
    StructExample(int val) = delete;
    StructExample(StructExample &&ruleOfFive) noexcept = delete;         //III. MOVE CONSTRUCTOR
    StructExample(const StructExample &ruleOfThree) = delete;            // II. COPY CONSTRUCTOR
    StructExample &operator=(const StructExample &ruleOfThree) = delete; // III. COPY ASSIGNMENT
    ~StructExample() = default;

    
    
    typedef struct PackConcenationProcess {
		PackConcenationProcess() {
			concatVariable = 0;
		}
		int concatVariable;
		std::vector<char> mSrcPack;
		std::vector<char> mDstPack;
		void addPackage(char pDataPack);
		void concatToVecPacks(std::vector<char> &pRawDataPack,int pPackSize);
		void concatToIntVar();
		void clearPackage(std::vector<char>& pRawDataPack);
	}PackConcenationProcess;
    
   
};

#endif