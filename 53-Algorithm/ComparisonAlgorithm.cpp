//Author: Burak Doğançay
#include "ComparisonAlgorithm.h"

ComparisonAlgorithm::ComparisonAlgorithm()
{
}

void ComparisonAlgorithm::comparisonFunc(){
    //WE WILL CONSIDER
    //std::equal , std::mismatch, std::lexicographical_compose()
    std::vector<int> searchVec{1,2,3,4,5,20,30,30,40,50,60};

    printOneLine("----COMPARISON ALGORITHMS----");
    //std::adjacent_find
    //Finds the first instance of the two consecitive elements that are equal to the eachother or are equavalent to eachother as specified by a predicate 
    std::vector<int>::iterator adjacentIt = std::adjacent_find(searchVec.begin(), searchVec.end());

    printOneLine("-------std::Equal-----------");
    if(adjacentIt == searchVec.end()){
        std::cout<<"There is no adjacent equal variable"<<std::endl;
    }
    else{
        std::cout<<"There are adjacent equal number at : "<< std::distance(searchVec.begin(),adjacentIt)<<"  Variable Name : "<< *adjacentIt <<std::endl; 
    }
    //----------------------------------------------------------------------------------

  

}