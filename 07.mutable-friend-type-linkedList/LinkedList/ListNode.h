#ifndef LISTNODE_H
#define LISTNODE_H

#include <iostream>
#include <functional>

//Enum and struct also keyword"
class ListNode
{
public:
    ListNode();
    ListNode(int val);
    ListNode(const ListNode &ruleOfThree);            // II. COPY CONSTRUCTOR
    ListNode &operator=(const ListNode &ruleOfThree); // III. COPY ASSIGNMENT
    ~ListNode(); 
    
    int data;
    ListNode *next; 

   
};
#endif