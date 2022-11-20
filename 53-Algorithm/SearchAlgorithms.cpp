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

    //std::find_end()
    //Finds the lost subsequence in sequence that matches another sequence or whose elements are equavalent as specified by a predicate
    std::vector<int> findEndFirstVec{20,30,45,55,100,50,60,40};
    std::vector<int> findEndSecondVec{20,30,45,55};
  
    std::vector<int>::iterator findEndIt = std::find_end(findEndFirstVec.begin(), findEndFirstVec.end(),findEndSecondVec.begin(),findEndSecondVec.end());

    printOneLine("-------Find_End-----------");
    if(findEndIt == findEndFirstVec.end()){
        std::cout<<"There is no sequence : "<<std::endl;
    }
    else{
        std::cout<<"There is a sequence  : "<< std::distance(findEndFirstVec.begin(),findEndIt)<<"  Variable Name : "<< *findEndIt <<std::endl; 
    }
    //---------------------------------------------------------------------------------- 

    //std::search()
    //Used to find out the presence of a subsequence satisfying a condition
    std::vector<int> searchFirstVec{20,30,45,55,100,50,60,40};
    std::vector<int> searchSecondVec{100,50,60,40};;
  
    std::vector<int>::iterator searchIt = std::search(searchFirstVec.begin(), searchFirstVec.end(),searchSecondVec.begin(),searchSecondVec.end()); //also you can add conditional precidate

    printOneLine("-------Search-----------");
    if(searchIt == searchFirstVec.end()){
        std::cout<<"There is no sequence : "<<std::endl;
    }
    else{
        std::cout<<"There is a sequence start at  : "<< std::distance(searchFirstVec.begin(),searchIt)<<"  Variable Name : "<< *searchIt <<std::endl; 
    }
    //---------------------------------------------------------------------------------- 

    //std::search_n()
    //Used to find out the presence of a subsequence satisfying a condition
    std::vector<int> search_nFirstVec{20,30,45,55,100,30,30,30};
    int search_nVal = 30;
  
    std::vector<int>::iterator search_nIt = std::search_n(search_nFirstVec.begin(), search_nFirstVec.end(),3,search_nVal); //also you can add conditional precidate

    printOneLine("-------Search_n-----------");
    if(search_nIt == search_nFirstVec.end()){
        std::cout<<"There is no items that are available 3 times in vector : "<<std::endl;
    }
    else{
        std::cout<<"There is an items 3 times in vector at index  : "<< std::distance(search_nFirstVec.begin(),search_nIt)<<"  Variable Name : "<< *search_nIt <<std::endl; 
    }
    printOneLine("--------Default Algoritm result--------");
    int var =  manualAlgorithm(search_nFirstVec.begin(),search_nFirstVec.end(),30);
    int var2 =  manualAlgorithm(search_nFirstVec.begin(),search_nFirstVec.end(),100);
    int var3 =  manualAlgorithm(search_nFirstVec.begin(),search_nFirstVec.end(),55);
    printTwoLine("The var available at index of vector : ", var);
    printTwoLine("The var available at index of vector : ", var2);
    printTwoLine("The var available at index of vector : ", var3);
    //---------------------------------------------------------------------------------- 
}

int SearchAlgorithms::manualAlgorithm(std::vector<int>::iterator begin, std::vector<int>::iterator end,const int &pVar){
    int var;
    for(auto i = begin; i!=end; i++){
        var = (*i == pVar) ? std::distance(begin,i) : -1;
        if(var >= 0){
            break;
        }
    }
    return var;
}