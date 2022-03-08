#include "main.h"
Example::Example() : something(true) //THIS IS CTOR INITIALIZATON
{
    doubleval = 50.0;
    integerval = 30;
}

Example::~Example()
{
}

void Example::setVariable(int *pvariable)
{
    mVariable = pvariable;
}

int Example::getVariable() const
{

    return *mVariable;
}

int main()
{
    Example example;
    int defvariable = 50;

    std::cout << example.something << "  " << HEIGHT << std::endl;
    std::cout << static_cast<int>(example.doubleval)<<" and " << static_cast<double>(example.integerval) << std::endl; //STATİC CAST EXAMPLE

    printString("Macro is succesfully defin"); //MACRO DEFINITION FOR PRINTING

    example.setVariable(&defvariable); //GET SET EXAMPLE
    std::cout << example.getVariable();
}