#include "UnorderedMap.h"
UnorderedMap::UnorderedMap()
{
}

void UnorderedMap::unorderedMapExample(){
std::unordered_map<std::string, int> first;
first["One"] = 1;
first["two"] = 2;
first["three"] = 3;

std::pair <std::string,int> bar = std::make_pair("Four", 4); //make a pair of same type
first.insert(bar); //can also use insert to feed the values

for (auto &mapVariable : first){

    std::cout<<"Unordered Map Variables : "<<mapVariable.first<<" : "<<mapVariable.second<<std::endl;
}



}