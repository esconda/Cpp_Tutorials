//Author: Burak Doğançay
#include "SwapAndExchangeAlgorithms.h"

SwapAndExchangeAlgorithms::SwapAndExchangeAlgorithms()
{
}

void SwapAndExchangeAlgorithms::swapAndExchangeFunctions(){
    //WE WILL CONSIDER
    //std::iter_swap, std::swap_range, std::swap, std::exchange

    printOneLine("----SWAP AND EXCHANGE ALGORITHMS----");

    printOneLine("-----------std::iter_swap-----------");
    //std::iter_swap
    //Swaps two elements or sequence of elements
    std::vector<int> setSwapVec{1,4,3,2,7,6,5,8,9,10};
    //Sorting op
    for (std::vector<int>::iterator i = setSwapVec.begin(); i != setSwapVec.end(); ++i)
        std::iter_swap(i, std::min_element(i, setSwapVec.end()));


    for (auto &n: setSwapVec){
        print(n);
    }
    printOneLine("");
    //----------------------------------------------------------------------------------

     printOneLine("-----------std::swap_range-----------");
    //std::swap_range
    //Swaps two elements or sequence of elements
    std::vector<int> setSwapRangeFirstVec{1,4,3,2,7,6};
    std::vector<int> setSwapRangeSecondVec{20,30,40,50,60,70};

    std::swap_ranges(setSwapRangeFirstVec.begin(),setSwapRangeFirstVec.begin()+3, setSwapRangeSecondVec.begin());


    for (auto &n: setSwapRangeFirstVec){
        print(n);
    }
    printOneLine("");
    //----------------------------------------------------------------------------------

    printOneLine("-----------std::swap-----------");
    //std::swap_ranges
    //Swaps two elements or sequence of elements
    std::vector<int> setSwapFirstVec{1,4,3,2,7,6};
    std::vector<int> setSwapSecondVec{20,30,40,50,60,70};

    std::swap(setSwapFirstVec,setSwapSecondVec);


    for (auto &n: setSwapFirstVec){
        print(n);
    }
    printOneLine("");
    //----------------------------------------------------------------------------------  
}