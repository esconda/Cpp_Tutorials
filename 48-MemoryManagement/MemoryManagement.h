//Author: Burak Doğançay
#ifndef MEMORYMANAGEMENT_H 
#define MEMORYMANAGEMENT_H
#include <iostream>
#include <memory>
#include <thread>


class MemoryManagement
{
public:
    MemoryManagement();

    void freeStorage();
    void freeStorageExOne();
    void placementNew();
    void stack();
   
};

#endif