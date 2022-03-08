#include "StdFunction.h"

StdFunction::StdFunction()
{
}


StdFunction::StdFunction(StdFunction &&ruleOfFive) noexcept // III. MOVE CONSTRUCTOR
{
    std::cout << "Move assignment is called" << std::endl;
}

StdFunction& StdFunction::operator=(const StdFunction &ruleOfThree) // IV COPY ASSIGNMENT
{
    std::cout << "Copy assignment is called" << std::endl;
}

void StdFunction::simpleFunction(int pI, const std::string &pString)
{

    std::cout << "Function is called values are : " << pI << " " << pString << std::endl;
}
void StdFunction::simpleCallIntFunct(const std::string &a)
{

    std::cout << "String is : " << a << std::endl;
}

void StdFunction::simpleCallVoidFunct()
{
    std::cout << "Void function is called";
}
