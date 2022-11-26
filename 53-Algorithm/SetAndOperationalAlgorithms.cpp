//Author: Burak Doğançay
#include "SetAndOperationalAlgorithms.h"

SetAndOperationalAlgorithms::SetAndOperationalAlgorithms()
{
}

void SetAndOperationalAlgorithms::setAlgorithm(){
   //WE WILL CONSIDER
   //std::inplace_merge, std::Merge,
    //std::includes ,std::set_union, std::set_intersection, std::set_difference, set_symetric_differenced

    printOneLine("----SET ALGORITHMS----");
    printOneLine("-----------inplace_merge-----------");
    //std::inplace_merge
    //merges 
    std::vector<int> mergeVec{1,2,3,4,5,6,7,8,9,10};
    std::inplace_merge(mergeVec.begin(), mergeVec.end()-(mergeVec.size()/2),mergeVec.end());// use it with sort
    for (auto &n: mergeVec){
        print(n);
    }
    printOneLine("");
    //----------------------------------------------------------------------------------

    printOneLine("-----------Merge-----------");
    //std::merge
    //merges two sorted vector by copying them to the new vector
    std::vector<int> mergeFirstVec{1,2,3,4,5,6,7,8,9,10};
    std::vector<int> mergeSecondVec{12,13,15,16,20};
    std::vector<int> mergeDstVector;
    std::merge(mergeFirstVec.begin(), mergeFirstVec.end(),mergeSecondVec.begin(),mergeSecondVec.end(),std::back_inserter(mergeDstVector));// use it with sort
    for (auto &n: mergeDstVector){
        print(n);
    }
    printOneLine("");
    //----------------------------------------------------------------------------------

    printOneLine("-----------Includes-----------");
    //std::includes
    //Determines if every element from one sorted sequence is another sorted sequence
    std::vector<int> includesFirstVec{2,4,6,8,20,12};
    std::vector<int> includesSecondVec{4,6,8,30};
    std::vector<int> includesThirdVec{8,20,12};
    std::vector<int> includesForthVec{6,8,20};
    std::vector<int> includesFifthVec{5,6,7,8};

    printTwoLine("First Compare : ", std::includes(includesFirstVec.begin(),includesFirstVec.end(),includesSecondVec.begin(),includesSecondVec.end()));
    printTwoLine("Second Compare : ", std::includes(includesFirstVec.begin(),includesFirstVec.end(),includesThirdVec.begin(),includesThirdVec.end()));
    printTwoLine("Third Compare : ", std::includes(includesFirstVec.begin(),includesFirstVec.end(),includesThirdVec.begin(),includesThirdVec.end()));
    printTwoLine("Forth Compare : ", std::includes(includesFirstVec.begin(),includesFirstVec.end(),includesForthVec.begin(),includesForthVec.end()));
    printTwoLine("Fifth Compare : ", std::includes(includesFirstVec.begin(),includesFirstVec.end(),includesFifthVec.begin(),includesFifthVec.end()));
    //----------------------------------------------------------------------------------

    printOneLine("-----------set_union-----------");
    //std::set_union
    //Constructs a sorted union beginning at d_first consisting of the set of elements present in one or both sorted ranges [first1, last1) and [first2, last2).
    //If some element is found m times in [first1, last1) and n times in [first2, last2), then all m elements will be copied from [first1, last1) to d_first, preserving order
    //Set union does not merge the same items of first sequence
    std::vector<int> setUnionFirstVec{1,2,3,4,5,6,7,8,9,10};
    std::vector<int> setUnionSecondVec{1,2,3,4,25,24,34};
    std::vector<int> setUnionDstVector;
    std::set_union(setUnionFirstVec.begin(), setUnionFirstVec.end(),setUnionSecondVec.begin(),setUnionSecondVec.end(),std::back_inserter(setUnionDstVector));// use it with sort
    for (auto &n: setUnionDstVector){
        print(n);
    }
    printOneLine("");
    //----------------------------------------------------------------------------------

    printOneLine("-----------set_intersection-----------");
    //std::set_intersection
    //Set_intersection merges same item of two vectors to new vectors
    std::vector<int> setIntersectionFirstVec{1,2,3,4,5,6,7,8,9,10};
    std::vector<int> setIntersectionSecondVec{1,2,3,4,25,24,34};
    std::vector<int> setIntersectionDstVector;
    std::set_intersection(setIntersectionFirstVec.begin(), setIntersectionFirstVec.end(),setIntersectionSecondVec.begin(),setIntersectionSecondVec.end(),std::back_inserter(setIntersectionDstVector));// use it with sort
    for (auto &n: setIntersectionDstVector){
        print(n);
    }
    printOneLine("");
    //----------------------------------------------------------------------------------

    printOneLine("-----------set_difference-----------");
    //std::set_difference
    //Set_difference gets different item of two vectors and merge first vector to destination vector
    std::vector<int> setDifferenceFirstVec{1,2,3,4,5,6,7,8,9,10};
    std::vector<int> setDifferenceSecondVec{1,2,3,4,25,24,34,45,65,76};
    std::vector<int> setDifferenceDstVector;
    std::set_difference(setDifferenceFirstVec.begin(), setDifferenceFirstVec.end(),setDifferenceSecondVec.begin(),setDifferenceSecondVec.end(),std::back_inserter(setDifferenceDstVector));// use it with sort
    for (auto &n: setDifferenceDstVector){
        print(n);
    }
    printOneLine("");
    //----------------------------------------------------------------------------------

     printOneLine("-----------set_symetric_difference-----------");
    //std::set_difference
    //Computes symmetric difference of two sorted ranges: the elements that are found in either of the ranges, 
    //but not in both of them are copied to the range beginning at d_first. The resulting range is also sorted.
    std::vector<int> setSymDifferenceFirstVec{1,2,3,4,5,6,7,8,9,10};
    std::vector<int> setSymDifferenceSecondVec{1,2,3,4,25,24,34};
    std::vector<int> setSymDifferenceDstVector;
    std::set_symmetric_difference(setSymDifferenceFirstVec.begin(), setSymDifferenceFirstVec.end(),setSymDifferenceSecondVec.begin(),setSymDifferenceSecondVec.end(),std::back_inserter(setSymDifferenceDstVector));// use it with sort
    for (auto &n: setSymDifferenceDstVector){
        print(n);
    }
    printOneLine("");
    //----------------------------------------------------------------------------------
}

void SetAndOperationalAlgorithms::operationalAlgorithm(){
    //WE WILL CONSIDER
    //for_each, for_each_n
    printOneLine("----OPERATIONAL ALGOITHMS----");
    
    //std::for_each()
    printOneLine("-----------for_each-----------");
    std::vector<int> forEachVec{1,2,3,4,5,6,7,8,9,10};
    std::for_each(forEachVec.begin(), forEachVec.end(), [](int &n){n++;});// use it with sort
    for (auto &n: forEachVec){
        print(n);
    }
    printOneLine("");
    //----------------------------------------------------------------------------------
    
    //first	-	the beginning of the range to apply the function to
    //std::for_each_n()
    //n	-	the number of elements to apply the function to
    printOneLine("-----------for_each-----------");
    std::vector<int> forEachNVec{1,2,3,4,5,6,7,8,9,10};
    std::for_each_n(forEachNVec.begin(), 5, [](int &n){n*=2;});// use it with sort
    for (auto &n: forEachNVec){
        print(n);
    }
    printOneLine("");
    //----------------------------------------------------------------------------------

}