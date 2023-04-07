//Author: Burak Doğançay
#include "CountingAlgorithm.h"

CountingAlgorithm::CountingAlgorithm()
{
}

void CountingAlgorithm::vectorInitializations(){
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


void CountingAlgorithm::countingAlgortihms(){
    //WE WILL CONSIDER
    //std::all_of, std::none_of, std::any_of
    //std::count, std::count_if

    std::vector<int> countingEvenVec{20,30,30,40,50,60};
    std::vector<int> countingOddVec{21,31,43,57,65};

    printOneLine("----COUNTING ALGORITHMS----");
    //Returns true if the predicate returns true for all elementsin the sequence is empty false otherwise
    if(std::all_of(countingEvenVec.begin(),countingEvenVec.end(),[](int i){return  i % 2 ==0;})){
        printOneLine("--------------Counting Even Vector------------------");
        printOneLine("All numbers are even");
    }
    //OUTPUT: All numbers are even
    //Complexity : O(n)

    //Returns true if the predicate returns false for all the elements in the same sequence or if the sequence is empty , false otherwise
    if(std::none_of(countingOddVec.begin(),countingOddVec.end(),[](int i){return  i % 2 ==0;})){
        printOneLine("--------------Counting Odd Vector------------------");
        printOneLine("All numbers are odd");
    }
    //OUTPUT: All numbers are odd
    //Complexity : O(n)

    //Returns true if the predicate returns true for at least one element in the sequence , false otherwise
    if(std::any_of(countingEvenVec.begin(),countingEvenVec.end(),[](int i){return  i % 2 ==0;})){
        printOneLine("--------------Counting Any Even Vector------------------");
        printOneLine("Some numbers are even");
    }
    //OUTPUT: Some numbers are even
    //Complexity : O(n)
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
     //OUTPUT: Some parameters are true
    //Complexity : O(n)
   //----------------------------------------------------------------------------------

    //Counts the nuber of elements matching a value or that cause a predicate return true
    //std::count example
    //complexity: o(n)+o(1)
    std::vector<int> countingVec{30,30,30,40,50,60};
    int countNum;
    int target = 30;
    countNum = std::count(countingVec.begin(),countingVec.end(),target);

    printOneLine("-------Counting Count Vector-----------");
    printTwoLine("How many target (30) items are available : ", countNum);
    //OUTPUT: How many target (30) items are available : 3
    //----------------------------------------------------------------------------------

    //std::count_if example
    std::vector<int> countingifVec{30,30,30,40,50,60};
    int countifNum;
    countifNum = std::count_if(countingifVec.begin(),countingifVec.end(),[](const auto &i){
        return i % 15 == 0;
    });

    printOneLine("-------Counting Count_if Vector-----------");
    printTwoLine("How many vector items are divided by 15: ", countifNum);
    //OUTPUT: How many vector items are divided by 15: 4
    //----------------------------------------------------------------------------------
}
