#ifndef UNTITLED1_H
#define UNTITLED1_H

#include <iostream>
#include <vector>
#include <utility>
#include <string>
//Author : Burak Dogancay
template<typename T>
class myClass
{
public:
    myClass();
    explicit myClass(T value);
    T mvalue;
    T mprivval;
    T intFunction();
    void somemaths();
    void writeString(T string);
    double doubleval;
    double doubleval2;
    double doubleval3;
    

private:
};
typedef myClass<std::string> myClassConst; 



#endif