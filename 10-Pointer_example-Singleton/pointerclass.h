#include <string>
#include <stdlib.h>
#include <iostream>

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


