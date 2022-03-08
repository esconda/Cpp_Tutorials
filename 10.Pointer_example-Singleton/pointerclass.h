#include <string>
#include <stdlib.h>
#include <iostream>
//Author : Burak Dogancay
class pointerclass
{
private:
    /* data */
    int mpointerval;

public:
    pointerclass(/* args */);
    static pointerclass *instance();
    void pointercheckbyadress(const pointerclass &pclass);
    ~pointerclass();
};


