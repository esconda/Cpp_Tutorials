#include "PassBy-Mutable-Inline.h"
PassByExample::PassByExample() : mValue(0)
{
}

PassByExample::~PassByExample() //DESTRUCTOR
{
}
//Pvalue is the reference of passed value therefore if pValue is changed mValue will be changed too
void PassByExample::passbyReference(int &pValue)
{
    std::cout << "Before changing Integer Value : " << pValue << std::endl;
    pValue = 40;
    std::cout << "After changing Integer Integer Value : " << pValue << std::endl;
}
void PassByExample::passbyValue(int pValue)
{
    int tValue = pValue;
    pValue = 50;
    std::cout << "Integer Value : " << tValue << pValue << std::endl;
}

void PassByExample::passbyPointer(int *pValue)
{
    *pValue = 100;
    std::cout << "Integer Value : " << *pValue << std::endl;
}

void PassByExample::passbyExeExample()
{
    int tValue = 80;
    passbyReference(tValue);
    passbyValue(tValue);
    passbyPointer(&tValue);
}

int PassByExample::getValue() const
{
    mValue++;
    return mValue;
}
