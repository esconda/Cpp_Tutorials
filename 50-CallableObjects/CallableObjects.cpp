// Author: Burak Doğançay
#include "CallableObjects.h"

CallableObjects::CallableObjects()
{
}

bool CallableObjects::lessThanInt(int first, int second)
{

    return first < second;
}

bool CallableObjects::GreaterThanInt::cmp(int first, int second)
{
    return first > second;
}

void CallableObjects::sortVectorInt(std::vector<int> &v, LessThanFunctionPtr lessThan)
{
    if (v.size() < 2)
        return;

    if (v.size() == 2)
    {
        if (!lessThan(v.front(), v.back())) // Invoke the function pointer
            std::swap(v.front(), v.back());
        return;
    }
    std::sort(v, lessThan);
}

void CallableObjects::applyFunctions()
{
    std::vector<int> intVecVars  = {20,30,15,40};

    sortVectorInt(intVecVars,lessThanInt);
    sortVectorInt(intVecVars,&GreaterThanInt::cmp);

}
