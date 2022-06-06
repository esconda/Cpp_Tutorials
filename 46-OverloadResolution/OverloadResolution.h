//Author: Burak Doğançay
#ifndef OVERLOADRESOLUTION_H 
#define OVERLOADRESOLUTION_H
#include <iostream>
#include <memory>
#include <thread>


class OverloadResolution
{
public:
    OverloadResolution();
    void categorizeArgument();
    void arithmeticPromConv();
    void exactMatch();
    void overloadingVolatily();
    void ovlerloadingHierarchy();
};

#endif