#ifndef MAIN_H
#define MAIN_H

#include <iostream>
#include <cstdlib>

class Mymain{

public:
    Mymain();
    ~Mymain();
    //never define static in header file , you expect one instance but it creates two if you create class
    static int staticdefone;

private:

protected:

};

#endif
