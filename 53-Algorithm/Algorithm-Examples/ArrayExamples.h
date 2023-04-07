// Author: Burak Doğançay
#ifndef ARRAYEXAMPLES_H
#define ARRAYEXAMPLES_H
#include <iostream>
#include <memory>
#include <unordered_set>
#include <vector>
#include <algorithm>
#include <functional>
#include <map>

class ArrayExamples
{
public:
    ArrayExamples();
    ArrayExamples(int val) = delete;
    ArrayExamples(ArrayExamples &&ruleOfFive) noexcept = delete;         //III. MOVE CONSTRUCTOR
    ArrayExamples(const ArrayExamples &ruleOfThree) = delete;            // II. COPY CONSTRUCTOR
    ArrayExamples &operator=(const ArrayExamples &ruleOfThree) = delete; // III. COPY ASSIGNMENT
    ~ArrayExamples() =default;   

    void removeDuplicatesFromSortedArray();
    void rotateArray();
    void firstNonRepeatedCharacterIndex();
    void containsDuplicate();
    void singleNumber();
    void intersectionOfTwoArrays();
    void findSecondLargestElementInArray();
};

#endif