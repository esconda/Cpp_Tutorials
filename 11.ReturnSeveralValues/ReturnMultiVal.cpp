#include "ReturnMultiVal.h"

ReturnMultiVal::ReturnMultiVal()
{
}

ReturnMultiVal::ReturnMultiVal(int val)
{
}

ReturnMultiVal::~ReturnMultiVal()
{
}

ReturnMultiVal::ReturnMultiVal(const ReturnMultiVal &ruleOfThree)
{
}

ReturnMultiVal &ReturnMultiVal::operator=(const ReturnMultiVal &ruleOfThree)
{
}


std::tuple<int,int,int,int> ReturnMultiVal::tupleReturning(int val1, int val2, int val3){
    int addition = val1 + val2+ val3;
    int multiplication = val1 * val2 * val3;
    int subtraction = val1 - val2 - val3;
    int division = val1 / val2 / val3;

    return std::make_tuple(addition, multiplication ,subtraction, division);
}

void ReturnMultiVal::mapBaseReturning(){
     std::map<std::string,bool> m;
     m.insert({"STA",true});
     m.insert({"STAOmtas",true});
    for (auto const &[val1, success] : m)
    {
        if (success)
        {
            std::cout << "The value for " << val1<< " is " << success << std::endl;
        }
    }
}

ReturnMultiVal::mathOp ReturnMultiVal::structBaseReturning(int val1,int val2, int val3){
    
    int addition = val1 + val2+ val3;
    int multiplication = val1 * val2 * val3;
    int subtraction = val1 - val2 - val3;
    int division = val1 / val2 / val3;

   /*  return ReturnMultiVal::mathOp(addition,multiplication,subtraction,division) */ // It is for c++11
    return {addition,multiplication,subtraction,division}; //It is for c++17
}

std::pair<int,int> ReturnMultiVal::pairBaseReturning(int val1,int val2){
    int add = val1 + val2;
    int mul = val1 * val2;
    return std::make_pair(add,mul);
}

std::pair<std::string,bool> ReturnMultiVal::pairBaseMapReturning(std::string val1,bool val2){
    std::string key = val1;
    bool value = val2;
    return std::make_pair(key,value);
}


std::array<int,4> ReturnMultiVal::arrayBaseReturning(int val1, int val2){
    int addition = val1 + val2;
    int multiplication = val1 * val2;
    int subtraction = val1 - val2;
    int division = val1 / val2;

    return {addition,multiplication,subtraction,division};
}

std::vector<int> ReturnMultiVal::vectorBaseReturning(int val1, int val2){
    int addition = val1 + val2;
    int multiplication = val1 * val2;
    int subtraction = val1 - val2;
    int division = val1 / val2;

    return {addition,multiplication,subtraction,division};
}