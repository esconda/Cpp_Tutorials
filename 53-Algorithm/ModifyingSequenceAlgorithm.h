// Author: Burak Doğançay
#ifndef MODIFYINGSEQUENCEALGORTITHM_H
#define MODIFYINGSEQUENCEALGORTITHM_H
#include <iostream>
#include <memory>
#include <algorithm>
#include <functional>
#include <vector>
#include <map>
#define print(a) std::cout << a
#define printOneLine(a) std::cout << a << std::endl
#define printTwoLine(a,b) std::cout << a << b << std::endl
// An algorithm is a strategy for performing a particular  task such as sorting or searching.These algorithms implemented as function so they work
// on most of the different container types.ALGORİTHMs are not generally part of the containers.It is necessary in order to support generic programming in the standart library
//Note that generic algorithms do not wok directly ont he containers .They use intermediate that called an iterator
class ModifyingSequenceAlgorithm
{
public:
    ModifyingSequenceAlgorithm();
    ModifyingSequenceAlgorithm(int val) = delete;
    ModifyingSequenceAlgorithm(ModifyingSequenceAlgorithm &&ruleOfFive) noexcept = delete;         //III. MOVE CONSTRUCTOR
    ModifyingSequenceAlgorithm(const ModifyingSequenceAlgorithm &ruleOfThree) = delete;            // II. COPY CONSTRUCTOR
    ModifyingSequenceAlgorithm &operator=(const ModifyingSequenceAlgorithm &ruleOfThree) = delete; // III. COPY ASSIGNMENT
    ~ModifyingSequenceAlgorithm() = default;

    void copyFunctions();
    void fillFunctions();
    void generateFunctions();
    void moveFunctions();
    void removeFunctions();
    void replaceFunctions();
    void reverseFunctions();
    void rotateFunctions();
    void sampleShuffleFunctions();
    void transformFunctions();
    void uniqueFunctions();
};

#endif