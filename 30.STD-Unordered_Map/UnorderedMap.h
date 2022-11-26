#ifndef UNORDEREDMAP_H
#define UNORDEREDMAP_H

#include <iostream>
#include <cstring>
#include <functional>
#include <optional>
#include <forward_list>
#include <tuple>
#include <utility>
#include <unordered_map>
//Author : Burak Dogancay
/* std::unordered_map is just an associative container. It works on keys and their maps. Key as the names goes, helps
to have uniqueness in the map. While the mapped value is just a content that is associated with the key. The data
types of this key and map can be any of the predefined data type or user-defined.

Internally, the elements are not sorted in any particular order, but organized into buckets. Which bucket an element is placed into depends entirely on the hash of its key.
Keys with the same hash code appear in the same bucket. 
This allows fast access to individual elements, since once the hash is computed, it refers to the exact bucket the element is placed into.
 */
class UnorderedMap
{
public:
    UnorderedMap();
    UnorderedMap(int val) = delete;
    UnorderedMap(UnorderedMap &&ruleOfFive) noexcept = delete;         //III. MOVE CONSTRUCTOR
    UnorderedMap(const UnorderedMap &ruleOfThree) = delete;            // II. COPY CONSTRUCTOR
    UnorderedMap &operator=(const UnorderedMap &ruleOfThree) = delete; // III. COPY ASSIGNMENT
    ~UnorderedMap() = default;

    void unorderedMapExample();
};

#endif