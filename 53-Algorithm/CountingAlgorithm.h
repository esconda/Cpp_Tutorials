// Author: Burak Doğançay
#ifndef COUNTINGALGORITHM_H
#define COUNTINGALGORITHM_H
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
class CountingAlgorithm
{
public:
    CountingAlgorithm();
    CountingAlgorithm(int val) = delete;
    CountingAlgorithm(CountingAlgorithm &&ruleOfFive) noexcept = delete;         //III. MOVE CONSTRUCTOR
    CountingAlgorithm(const CountingAlgorithm &ruleOfThree) = delete;            // II. COPY CONSTRUCTOR
    CountingAlgorithm &operator=(const CountingAlgorithm &ruleOfThree) = delete; // III. COPY ASSIGNMENT
    ~CountingAlgorithm() = default;

    void vectorInitializations();
    void countingAlgortihms();
};

#endif