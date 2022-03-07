#ifndef STDOPTIONAL_H
#define STDOPTIONAL_H

#include <iostream>
#include <cstring>
#include <functional>
#include <optional>
#include <forward_list>

/*
std::forward_list is a container that supports fast insertion and removal of elements from anywhere in the
container. Fast random access is not supported. It is implemented as a singly-linked list and essentially does not
have any overhead compared to its implementation in C. Compared to std::list this container provides more
space efficient storage when bidirectional iteration is not needed

Forward lists are implemented as singly-linked lists; Singly linked lists can store each of the elements they contain in different and unrelated storage locations


Compared to other base standard sequence containers (array, vector and deque), forward_list perform generally better in inserting, 
extracting and moving elements in any position within the container, and therefore also in algorithms that make intensive use of these, like sorting algorithms.

The main drawback of forward_lists and lists compared to these other sequence containers is that they lack direct access to the elements by their position; 
For example, to access the sixth element in a forward_list one has to iterate from the beginning to that position, which takes linear time in the distance between these. 
They also consume some extra memory to keep the linking information associated to each element 

----------Method name Definition-------------
operator= assigns values to the container
assign assigns values to the container
get_allocator returns the associated allocator

---------Element access------------
front access the first element
------ ------
--------------Iterators----------------------
before_begin returns an iterator to the element before beginning
cbefore_begin returns a constant iterator to the element before beginning
begin returns an iterator to the beginning
cbegin returns a const iterator to the beginning
end returns an iterator to the end
cend returns a iterator to the end

----------Capacity---------------
empty checks whether the container is empty
max_size returns the maximum possible number of elements

---------Modifiers---------------
clear clears the contents
insert_after inserts elements after an element
emplace_after constructs elements in-place after an element
erase_after erases an element after an element
push_front inserts an element to the beginning
emplace_front constructs an element in-place at the beginning
pop_front removes the first element
resize changes the number of elements stored
swap swaps the contents

-----------Operations------------
merge merges two sorted lists
splice_after moves elements from another forward_list
remove removes elements satisfying specific criteria
remove_if removes elements satisfying specific criteria
reverse reverses the order of the elements
unique removes consecutive duplicate elements
sort sorts the elements


*/
class StdForwardList
{
public:
    StdForwardList();
    StdForwardList(int val) = delete;
    StdForwardList(StdForwardList &&ruleOfFive) noexcept = delete;         //III. MOVE CONSTRUCTOR
    StdForwardList(const StdForwardList &ruleOfThree) = delete;            // II. COPY CONSTRUCTOR
    StdForwardList &operator=(const StdForwardList &ruleOfThree) = delete; // III. COPY ASSIGNMENT
    ~StdForwardList() = default;

    void forwardListInit();
    void pairExample();


};

#endif