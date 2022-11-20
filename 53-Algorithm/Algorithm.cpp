//Author: Burak Doğançay
#include "Algorithm.h"

Algorithm::Algorithm()
{
}

void Algorithm::vectorInitializations(){
    //INITIALIZING METHODES
    std::vector<int> vector1(5,10);// Initialize vector and add items 10 for 5 times

    //Initialize vectors with pushback, push values one by one
    std::vector<int> vector2;
    vector2.push_back(20);
    vector2.push_back(30);
    vector2.push_back(40);

    //Initializing like arrays
    std::vector<int> vector3{1,2,3,4,5,6};
    std::vector<int> vector4 = {10,11,12,13,14};
    std::vector<int> vector5 = std::vector<int>{20,30,40,50};
    

    //Initializing with dynamic allocation
    std::vector<int> *vector6 = new std::vector<int>(5,10);

    vector1.reserve(10);
    vector2.reserve(5);
    vector3.reserve(10);
    vector4.reserve(20);
    vector5.reserve(10);
    vector6->reserve(10);
    std::cout<<"-----------VECTOR INITIALIZATION-------------"<<std::endl;
    std::cout<<"-----------VECTOR1-------------"<<std::endl;
    for(int &item: vector1){
        std::cout<<"Vector1 Item"<< item <<std::endl;
    }
    std::cout<<"-----------VECTOR2-------------"<<std::endl;
    for(int &item: vector2){
        std::cout<<"Vector2 Item"<< item <<std::endl;
    }
    std::cout<<"-----------VECTOR3-------------"<<std::endl;
    for(int &item: vector3){
        std::cout<<"Vector3 Item"<< item <<std::endl;
    }
    std::cout<<"-----------VECTOR4-------------"<<std::endl;
    for(int &item: vector4){
        std::cout<<"Vector4 Item"<< item <<std::endl;
    }
    std::cout<<"-----------VECTOR5-------------"<<std::endl;
     for(int &item: vector5){
        std::cout<<"Vector5 Item"<< item <<std::endl;
    }
     std::cout<<"-----------VECTOR6-------------"<<std::endl;
     for(int &item: *vector6){
        std::cout<<"Vector6 Item"<< item <<std::endl;
    }
    std::cout<<"--------------------------------------------"<<std::endl;
}


void Algorithm::countingAlgortihms(){
    //WE WILL CONSIDER
    //std::all_of, std::none_of, std::any_of
    //std::count, std::count_if

    std::vector<int> countingEvenVec{20,30,30,40,50,60};
    std::vector<int> countingOddVec{21,31,43,57,65};

    //Returns true if the predicate returns true for all elementsin the sequence is empty false otherwise
    if(std::all_of(countingEvenVec.begin(),countingEvenVec.end(),[](int i){return  i % 2 ==0;})){
        printOneLine("--------------Counting Even Vector------------------");
        printOneLine("All numbers are even");
    }

    //Returns true if the predicate returns false for all the elements in the same sequence or if the sequence is empty , false otherwise
    if(std::none_of(countingOddVec.begin(),countingOddVec.end(),[](int i){return  i % 2 ==0;})){
        printOneLine("--------------Counting Odd Vector------------------");
        printOneLine("All numbers are odd");
    }

    //Returns true if the predicate returns true for at least one element in the sequence , false otherwise
    if(std::any_of(countingEvenVec.begin(),countingEvenVec.end(),[](int i){return  i % 2 ==0;})){
        printOneLine("--------------Counting Any Even Vector------------------");
        printOneLine("Some numbers are even");
    }
    //----------------------------------------------------------------------------------

    //Hash Map example of any of
    std::map<int,bool> countingMap{std::make_pair(1,false),
                               std::make_pair(2,true),
                               std::make_pair(3,false)};
    if(std::any_of(countingMap.begin(),countingMap.end(),[](const auto &i){
        return i.second;
    })){
        printOneLine("--------------Counting Any Even Map------------------");
        printOneLine("Some parameters are true");
    }
   //----------------------------------------------------------------------------------

    //Counts the nuber of elements matching a value or that cause a predicate return true
    //std::count example
    std::vector<int> countingVec{30,30,30,40,50,60};
    int countNum;
    int target = 30;
    countNum = std::count(countingVec.begin(),countingVec.end(),target);

    printOneLine("-------Counting Count Vector-----------");
    printTwoLine("How many target (30) items are available : ", countNum);
    //----------------------------------------------------------------------------------

    //std::count_if example
    std::vector<int> countingifVec{30,30,30,40,50,60};
    int countifNum;
    countifNum = std::count_if(countingifVec.begin(),countingifVec.end(),[](const auto &i){
        return i % 15 == 0;
    });

    printOneLine("-------Counting Count_if Vector-----------");
    printTwoLine("How many vector items are divided by 15: ", countifNum);
    //----------------------------------------------------------------------------------

}

void Algorithm::searchAlgorithms(){
 //WE WILL CONSIDER
    //std::adjacent_find, std::find, std::find_if,
    //std::find_first_of, std::find_if_not, std::find_end
    //std::search, std::search_n
    std::vector<int> searchVec{1,2,3,4,5,20,30,30,40,50,60};

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
}