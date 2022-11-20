//Author: Burak Doğançay
#include "SearchAlgorithms.h"

SearchAlgorithms::SearchAlgorithms()
{
}

void SearchAlgorithms::searchAlgorithms(){
 //WE WILL CONSIDER
    //std::adjacent_find, std::find, std::find_if,
    //std::find_first_of, std::find_if_not, std::find_end
    //std::search, std::search_n
    std::vector<int> searchVec{1,2,3,4,5,20,30,30,40,50,60};

    printOneLine("----SEARCH ALGORITHMS----");
    //std::adjacent_find
    //Finds the first instance of the two consecitive elements that are equal to the eachother or are equavalent to eachother as specified by a predicate 
    std::vector<int>::iterator adjacentIt = std::adjacent_find(searchVec.begin(), searchVec.end());

    printOneLine("-------Adjacent Find-----------");
    if(adjacentIt == searchVec.end()){
        std::cout<<"There is no adjacent equal variable"<<std::endl;
    }
    else{
        std::cout<<"There are adjacent equal number at : "<< std::distance(searchVec.begin(),adjacentIt)<<"  Variable Name : "<< *adjacentIt <<std::endl; 
    }
    //----------------------------------------------------------------------------------

    //std::find
    //Finds the first element that causes a predicate toreturn false
    int findVal = 5;
    std::vector<int>::iterator findIt = std::find(searchVec.begin(), searchVec.end(), findVal);

    printOneLine("-------Find-----------");
    if(findIt == searchVec.end()){
        std::cout<<"There is no value  : "<<findVal<< ""<<std::endl;
    }
    else{
        std::cout<<"There are adjacent equal number at : "<< std::distance(searchVec.begin(),findIt)<<"  Variable Name : "<< *findIt <<std::endl; 
    }
    //----------------------------------------------------------------------------------

    //std::find_if
    //Finds the first element that causes a predicate toreturn false
    int findIfVal = 5;
    std::vector<int>::iterator findIfIt = std::find_if(searchVec.begin(), searchVec.end(),[](const auto &i){
        return i % 2 == 0;
    });

    printOneLine("-------Find_If-----------");
    if(findIfIt == searchVec.end()){
        std::cout<<"There is no even value  : "<<findIfVal<< " in vector"<<std::endl;
    }
    else{
        std::cout<<"There is even number at : "<< std::distance(searchVec.begin(),findIfIt)<<"  Variable Name : "<< *findIfIt <<std::endl; 
    }
    //----------------------------------------------------------------------------------

    //std::find_first_of()
    //Like find but searches for one of several elements at the same time
    std::vector<int> firstVec{20,30,40,50};
    std::vector<int> secondVec{2,5,30,10};
    std::vector<int>::iterator findFirstOfIt = std::find_first_of(firstVec.begin(), firstVec.end(),secondVec.begin(),secondVec.end());

    printOneLine("-------Find_First_Of-----------");
    if(findIfIt == searchVec.end()){
        std::cout<<"There are no same elements at the same time : "<<std::endl;
    }
    else{
        std::cout<<"There are same elements at : "<< std::distance(firstVec.begin(),findFirstOfIt)<<"  Variable Name : "<< *findFirstOfIt <<std::endl; 
    }
    //----------------------------------------------------------------------------------

    //std::find_if_not()
    //Like find but searches for one of several elements at the same time
    std::vector<int> findIfNotVec{20,30,45,55};
  
    std::vector<int>::iterator findIfNotIt = std::find_if_not(findIfNotVec.begin(), findIfNotVec.end(),[](const auto &i ){
        return i%2 == 0;
    });

    printOneLine("-------Find_If_Not-----------");
    if(findIfNotIt == findIfNotVec.end()){
        std::cout<<"There are no odd element : "<<std::endl;
    }
    else{
        std::cout<<"There is an odd element at : "<< std::distance(findIfNotVec.begin(),findIfNotIt)<<"  Variable Name : "<< *findIfNotIt <<std::endl; 
    }
    //----------------------------------------------------------------------------------

    /* //std::find_end()
    //Finds the lost subsequence in sequence that matches another sequence or whose elements are equavalent 
    std::vector<int> findIfNotVec{20,30,45,55};
  
    std::vector<int>::iterator findIfNotIt = std::find_if_not(findIfNotVec.begin(), findIfNotVec.end(),[](const auto &i ){
        return i%2 == 0;
    });

    printOneLine("-------Find_If_Not-----------");
    if(findIfNotIt == findIfNotVec.end()){
        std::cout<<"There are no odd element : "<<std::endl;
    }
    else{
        std::cout<<"There is an odd element at : "<< std::distance(findIfNotVec.begin(),findIfNotIt)<<"  Variable Name : "<< *findIfNotIt <<std::endl; 
    }
    //---------------------------------------------------------------------------------- */
}