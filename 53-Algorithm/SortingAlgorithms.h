// Author: Burak Doğançay
#ifndef SORTINGALGORITHMS_H
#define SORTINGALGORITHMS_H
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
class SortingAlgorithms
{
public:
    SortingAlgorithms();
    SortingAlgorithms(int val) = delete;
    SortingAlgorithms(SortingAlgorithms &&ruleOfFive) noexcept = delete;         //III. MOVE CONSTRUCTOR
    SortingAlgorithms(const SortingAlgorithms &ruleOfThree) = delete;            // II. COPY CONSTRUCTOR
    SortingAlgorithms &operator=(const SortingAlgorithms &ruleOfThree) = delete; // III. COPY ASSIGNMENT
    ~SortingAlgorithms() = default;

    void sortingFunction();
};

#endif