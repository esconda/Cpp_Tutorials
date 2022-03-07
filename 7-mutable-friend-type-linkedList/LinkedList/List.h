#ifndef LIST_H
#define LIST_H

#include <iostream>
#include <functional>
#include "ListNode.h"
#include "ListNode.cpp"

//Enum and struct also keyword"

class List
{
public:
    List();
    List(const List &ruleOfThree);            // II. COPY CONSTRUCTOR
    List &operator=(const List &ruleOfThree); // III. COPY ASSIGNMENT
    ~List(); 
    
    ListNode *head;
    void insertAtBegin(int val);
    void insertAtEnd(int val);
    void insertAtPos(int pos,int val);
    void remove(int toBeRemoved);
    void print();
    

   
};
#endif