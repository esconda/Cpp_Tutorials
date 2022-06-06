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
/* - Prefer enumerations over macros
- Use enumerations to represent sets of related named constants
- Prefer class enums over “plain” enums
- Define operations on enumerations for safe and simple use
- Avoid unnamed enumerations
- Specify the underlying type of an enumeration only when necessary
    *The default is the easiest to read and write. int is the default integer type. int is compatible with C enums.
- Specify enumerator values only when necessary 
*/
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