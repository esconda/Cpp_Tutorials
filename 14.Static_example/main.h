#ifndef MAIN_H
#define MAIN_H

#include <iostream>
#include <cstdlib>
//Author : Burak Dogancay
class Mymain{

public:
    Mymain();
    ~Mymain();
    //never define static in header file , you expect one instance but it creates two if you create class
    static int staticdefone;
    static const int myStaticConstVariable = 50;

private:

protected:

};

#endif
