// Author: Burak Doğançay
#ifndef SWAPANDEXCHANGEALGORITHMS_H
#define SWAPANDEXCHANGEALGORITHMS_H
#include <iostream>
#include <memory>
#include <algorithm>
#include <vector>
#include <map>
#define print(a) std::cout << a
#define printOneLine(a) std::cout << a << std::endl
#define printTwoLine(a,b) std::cout << a << b << std::endl
// An algorithm is a strategy for performing a particular  task such as sorting or searching.These algorithms implemented as function so they work
// on most of the different container types.ALGORİTHMs are not generally part of the containers.It is necessary in order to support generic programming in the standart library
//Note that generic algorithms do not wok directly ont he containers .They use intermediate that called an iterator
class SwapAndExchangeAlgorithms
{
public:
    SwapAndExchangeAlgorithms();
    SwapAndExchangeAlgorithms(int val) = delete;
    SwapAndExchangeAlgorithms(SwapAndExchangeAlgorithms &&ruleOfFive) noexcept = delete;         //III. MOVE CONSTRUCTOR
    SwapAndExchangeAlgorithms(const SwapAndExchangeAlgorithms &ruleOfThree) = delete;            // II. COPY CONSTRUCTOR
    SwapAndExchangeAlgorithms &operator=(const SwapAndExchangeAlgorithms &ruleOfThree) = delete; // III. COPY ASSIGNMENT
    ~SwapAndExchangeAlgorithms() = default;

    void swapAndExchangeFunctions();
};

#endif