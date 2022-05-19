//Author: Burak Doğançay
#ifndef COPYELLISION_H 
#define COPYELLISION_H
#include <iostream>
#include <memory>
#include <thread>


class CopyEllision
{
public:
    CopyEllision();
    std::mutex my_mutex; 
    inline void getLock(){
        return std::lock_guard<std::mutex>(my_mutex);
    }
    void quaranteedCpyEllision();
    void parameterEllision(std::string str);
    std::string returnValEllision();
};

#endif