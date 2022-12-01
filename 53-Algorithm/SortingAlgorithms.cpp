//Author: Burak Doğançay
#include "SortingAlgorithms.h"

SortingAlgorithms::SortingAlgorithms()
{
}

void SortingAlgorithms::sortingFunction(){
    //WE WILL CONSIDER
    //std::is_sorted, is_sorted_until, nth_element, partial_sort,partial_sort_copy, sort,stable_sort

    printOneLine("----SORTING ALGORITHMS----");

    printOneLine("-----------std::is_sorted-----------");
    //std::is_sorted
    //Check if a sequence is sorted or which subsequence is sorted

    std::vector<int> isSortedVec{1,4,3,2,7,6,5,8,9,10};
    for (auto i : isSortedVec) 
        std::cout << i << ' ';

    std::cout << ": is_sorted: " << std::boolalpha
              << std::is_sorted(std::begin(isSortedVec), std::end(isSortedVec)) << '\n';
 
    std::sort(std::begin(isSortedVec), std::end(isSortedVec));
 
    for (auto i : isSortedVec) 
        std::cout << i << ' ';

    std::cout << ": is_sorted: "
              << std::is_sorted(std::begin(isSortedVec), std::end(isSortedVec)) << '\n';

    printOneLine("");
    //----------------------------------------------------------------------------------

    
    printOneLine("-----------std::is_sorted_until-----------");
    //std::is_sorted_until
    //Check if a sequence is sorted or which subsequence is sorted

    std::vector<int> isSortedUntilVec{1,2,3,2,7,6,5,8,9,10};
    std::vector<int>::iterator isSortedIt = std::is_sorted_until(isSortedUntilVec.begin(), isSortedUntilVec.begin()+3);
    
    if(isSortedIt == isSortedUntilVec.end()){
        std::cout<<"The vector is not sorted: "<<std::endl;
    }
    else{
        std::cout<<"The vector is sorted to : "<< std::distance(isSortedUntilVec.begin(),isSortedIt)<<"  Variable Name : "<< *isSortedIt <<std::endl; 
    }

    printOneLine("");
    //----------------------------------------------------------------------------------

    printOneLine("-----------std::nth_element-----------");
    //std::nth_element
    //nth_element is a partial sorting algorithm that rearranges elements in [first, last) such that:
    //The element pointed at by nth is changed to whatever element would occur in that position if [first, last) were sorted.
    //All of the elements before this new nth element are less than or equal to the elements after the new nth element.

    std::vector<int> nthElementVec{1,2,3,2,7,6,5,8,9,10};
    std::nth_element(nthElementVec.begin(), nthElementVec.begin()+5, nthElementVec.end(), std::greater{});
    for (auto i : nthElementVec) 
        std::cout << i << ' ';
    printTwoLine(" : The Largest Element is : ", nthElementVec.at(0));

    printOneLine("");
    //----------------------------------------------------------------------------------

     printOneLine("-----------std::partial_sort-----------");
    //std::partial_sort
    //Partially sorts the sequence the first n elements are sorted either in place on by copying them to a new sequence
    
    std::vector<int> partialSortVec{1,2,3,2,7,6,5,8,9,10};
    std::partial_sort(partialSortVec.begin(), partialSortVec.begin()+5, partialSortVec.end());
    for (auto &n: partialSortVec){
        print(n);
    }

    printOneLine("");
    //----------------------------------------------------------------------------------

    printOneLine("-----------std::partial_sort_copy-----------");
    //std::partial_sort
    //Partially sorts the sequence the first n elements are sorted either in place on by copying them to a new sequence
    
    std::vector<int> partialSortCopyFirstVec{1,2,3,2,7,6,5,8,9,10};
    std::vector<int> partialSortCopySecondVec(5);

    std::partial_sort_copy(partialSortCopyFirstVec.begin(), partialSortCopyFirstVec.end()+5,partialSortCopySecondVec.begin(),partialSortCopySecondVec.end());
    for (auto &n: partialSortCopySecondVec){
        print(n);
    }

    printOneLine("");
    //----------------------------------------------------------------------------------

    printOneLine("-----------std::sort-----------");
    //std::sort
    //Sorts the elements in the range [first, last) in non-descending order. The order of equal elements is not guaranteed to be preserved.
    std::vector<int> sortVec{1,5,3,2,7,6,5,8,9,10};

    std::sort(sortVec.begin(), sortVec.end());
    for (auto &n: sortVec){
        print(n);
    }

    printOneLine("");
    //----------------------------------------------------------------------------------
}