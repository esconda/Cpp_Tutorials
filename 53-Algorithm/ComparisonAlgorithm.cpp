//Author: Burak Doğançay
#include "ComparisonAlgorithm.h"

ComparisonAlgorithm::ComparisonAlgorithm()
{
}

void ComparisonAlgorithm::comparisonFunc(){
    //WE WILL CONSIDER
    //std::equal , std::mismatch, std::lexicographical_compose()

    printOneLine("----COMPARISON ALGORITHMS----");

    //std::Equal
    //Determine if the sequance are equal by checking if parallel elements are equal or watch a predicate
    std::vector<int> equalVecFirst{1,2,3,4,5,20,30,30,40,50,60};
    std::vector<int> equalVecSecond{1,2,3,4,5,20,25};
    bool var = std::equal(equalVecFirst.begin(), equalVecFirst.begin()+7,equalVecSecond.begin());

    printOneLine("-------std::Equal-----------");
    if(var){
        std::cout<<"There is equality"<<std::endl;
    }
    else{
        std::cout<<"There is no equality"<<std::endl; 
    }
    //----------------------------------------------------------------------------------

    //std::mismatch
    //Returns the first element in each sequence that does not match the element in the same locations
    std::vector<int> mismatchVecFirst{1,2,3,4,5,20};
    std::vector<int> mismatchVecSecond{1,2,3,4,5,20,25};
    std::pair< std::vector<int>::iterator,std::vector<int>::iterator>  mismatchIt = std::mismatch(mismatchVecFirst.begin(), mismatchVecFirst.end(),mismatchVecSecond.begin());

   printOneLine("-------std::mismatch-----------");
   if(mismatchIt.first != mismatchVecFirst.end()){
        std::cout<<"There is no sequence : "<<std::endl;
    }
    else{
         std::cout<<"There is a sequence for first vector :"<< std::distance(mismatchVecFirst.begin(),mismatchIt.first) << "  Variable Name : " << *mismatchIt.first <<std::endl; 
         std::cout<<"There is a sequence for second vector : "<< std::distance(mismatchVecSecond.begin(),mismatchIt.second) <<"  Variable Name : " << *mismatchIt.second <<std::endl; 
    }
    //----------------------------------------------------------------------------------

   /*   //std::lexicographical_compare
    //Checks if the first range [first1, last1) is lexicographically less than the second range [first2, last2).
    std::vector<int> mismatchVecFirst{1,2,3,4,5,20};
    std::vector<int> mismatchVecSecond{1,2,3,4,5,20,25};
    std::pair< std::vector<int>::iterator,std::vector<int>::iterator>  mismatchIt = std::mismatch(mismatchVecFirst.begin(), mismatchVecFirst.end(),mismatchVecSecond.begin());

   printOneLine("-------std::mismatch-----------");
   if(mismatchIt.first != mismatchVecFirst.end()){
        std::cout<<"There is no sequence : "<<std::endl;
    }
    else{
         std::cout<<"There is a sequence for first vector :"<< std::distance(mismatchVecFirst.begin(),mismatchIt.first) << "  Variable Name : " << *mismatchIt.first <<std::endl; 
         std::cout<<"There is a sequence for second vector : "<< std::distance(mismatchVecSecond.begin(),mismatchIt.second) <<"  Variable Name : " << *mismatchIt.second <<std::endl; 
    }
    //---------------------------------------------------------------------------------- */

  

}