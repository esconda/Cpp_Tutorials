// Author: Burak Doğançay
#ifndef SETANDOPERATIONALALGORITHMS_H
#define SETANDOPERATIONALALGORITHMS_H
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
class SetAndOperationalAlgorithms
{
public:
    SetAndOperationalAlgorithms();
    SetAndOperationalAlgorithms(int val) = delete;
    SetAndOperationalAlgorithms(SetAndOperationalAlgorithms &&ruleOfFive) noexcept = delete;         //III. MOVE CONSTRUCTOR
    SetAndOperationalAlgorithms(const SetAndOperationalAlgorithms &ruleOfThree) = delete;            // II. COPY CONSTRUCTOR
    SetAndOperationalAlgorithms &operator=(const SetAndOperationalAlgorithms &ruleOfThree) = delete; // III. COPY ASSIGNMENT
    ~SetAndOperationalAlgorithms() = default;

    void setAlgorithm();
    void operationalAlgorithm();
};

#endif