#ifndef STDMAP_H
#define STDMAP_H

#include <iostream>
#include <cstring>
#include <functional>
#include <map>
#include <vector>
//Author : Burak Dogancay
/* 
-   To use any of std::map or std::multimap the header file <map> should be included.
-   std::map and std::multimap both keep their elements sorted according to the ascending order of keys. In
    case of std::multimap, no sorting occurs for the values of the same key.
-   The basic difference between std::map and std::multimap is that the std::map one does not allow duplicate
    values for the same key where std::multimap does.
-   Maps are implemented as binary search trees. So search(), insert(), erase() takes Θ(log n) time in
    average. For constant time operation use std::unordered_map.
-   size() and empty() functions have Θ(1) time complexity, number of nodes is cached to avoid walking
    through tree each time these functions are called. */
class StdMap
{
public:
    StdMap();
    StdMap(int val) = delete;
    StdMap(StdMap &&ruleOfFive) noexcept = delete;         //III. MOVE CONSTRUCTOR
    StdMap(const StdMap &ruleOfThree) = delete;            // II. COPY CONSTRUCTOR
    StdMap &operator=(const StdMap &ruleOfThree) = delete; // III. COPY ASSIGNMENT
    ~StdMap() = default;

    void mapAccessingElements();
    void iteratorBaseAproach();
    void insertingElements();
    void initializingElments();
    void deletingElemenets();
};

#endif