#include "ReturnMultiVal.h"
#include <iostream>

int main()
{
    ReturnMultiVal returnMultiVal;

    //---------------Tuple base returning-------------------
    int add, sub, mult, div;
    std::tie(add, sub, mult, div) = returnMultiVal.tupleReturning(20, 30, 45); //If one of the returned values is not needed, auto [add, sub, mul, div] = returnMultiVal.tupleReturning(20,30,45);
    std::cout << "Tuple Addition : " << add << std::endl;
    std::cout << "Tuple Substraction : " << sub << std::endl;
    std::cout << "Tuple Multiplication : " << mult << std::endl;
    std::cout << "Tuple Division :" << div << std::endl;
    
    //-------------------------------------------------------
    //Map-StructuredBindings
     returnMultiVal.mapBaseReturning();
     //Map StructuredBindings another methode
     std::map<std::string,bool> mapVar{returnMultiVal.pairBaseMapReturning("Var1",true),returnMultiVal.pairBaseMapReturning("Var1",false)};
     mapVar.insert(returnMultiVal.pairBaseMapReturning("Var3",true));
     std::cout<<"Map Returning Var1 : "<<std::boolalpha<<mapVar["Var1"]<<std::endl;
     std::cout<<"Map Returning Var2 : "<<std::boolalpha<<mapVar["Var2"]<<std::endl;
     std::cout<<"Map Returning Var3 : "<<std::boolalpha<<mapVar["Var3"]<<std::endl;

    //---------------Struct base returning-------------------
    ReturnMultiVal::mathOp tstructOp = returnMultiVal.structBaseReturning(50,30,40);
    std::cout << "Struct Addition : " << tstructOp.add << std::endl;
    std::cout << "Struct Substraction : " << tstructOp.sub << std::endl;
    std::cout << "Struct Multiplication : " << tstructOp.mul<< std::endl;
    std::cout << "Struct Division :" << tstructOp.div << std::endl;

    //Another methode
    auto[strAdd,strSub,strMul,strDiv] = returnMultiVal.structBaseReturning(50,30,40);
    std::cout << "Struct1 Addition : " << strAdd << std::endl;
    std::cout << "Struct1 Substraction : " << strSub << std::endl;
    std::cout << "Struct1 Multiplication : " << strMul<< std::endl;
    std::cout << "Struct1 Division :" << strDiv << std::endl;
    //----------------------------------------------------------

    //------------------Pair base returning---------------------
    std::pair<int,int> pairBase = returnMultiVal.pairBaseReturning(30,20);
    std::pair<int,int> *pairBasePtr = &pairBase;
    std::cout<<"Pair Base funct : "<< pairBase.first<<" "<<pairBase.second<<std::endl;
    std::cout<<"Ptr Pair Base funct : "<< pairBasePtr->first<<" "<<pairBasePtr->second<<std::endl;
    //---------------------------------------------------------- 

    //------------------Array base returning---------------------
    std::array<int,4> arrayBase = returnMultiVal.arrayBaseReturning(50,30);
    std::cout<<"Array Base add,mul,sub,div : "<<arrayBase.at(0)<<" "<<arrayBase.at(1)<<" "<<arrayBase.at(2)<<" "<<arrayBase.at(3)<<std::endl;
    //------------------------------------------------------------

       //------------------Vector base returning---------------------
    std::vector<int> vectorBase = returnMultiVal.vectorBaseReturning(50,30);
    std::cout<<"Vector Base add,mul,sub,div : "<<vectorBase.at(0)<<" "<<vectorBase.at(1)<<" "<<vectorBase.at(2)<<" "<<vectorBase.at(3)<<std::endl;
    //------------------------------------------------------------
}