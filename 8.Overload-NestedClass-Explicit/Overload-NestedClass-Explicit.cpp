#include "Overload-NestedClass-Explicit.h"

ExampleClass1::ExampleClass2::ExampleClass2() : mValue(0)
{
}
ExampleClass1::ExampleClass2::ExampleClass2(int a)
{
    int tValueA = a;
    int tValueB = 80;

    std::cout << "Values are : " << tValueA << " , " << tValueB << std::endl;
    std::cout << "Sum Values are : " << tValueA + tValueB << std::endl;
}

ExampleClass1::ExampleClass2::~ExampleClass2() //DESTRUCTOR
{
}
//Pvalue is the reference of passed value therefore if pValue is changed mValue will be changed too
void ExampleClass1::ExampleClass2::passbyReference(int &pValue)
{
    std::cout << "Before changing Integer Value : " << pValue << std::endl;
    pValue = 40;
    std::cout << "After changing Integer Integer Value : " << pValue << std::endl;
}
void ExampleClass1::ExampleClass2::passbyValue(int pValue)
{
    int tValue = pValue;
    pValue = 50;
    std::cout << "Integer Value : " << tValue << pValue << std::endl;
}
//Pvalue is the poniter of passed value therefore if pValue is changed mValue will be changed too
void ExampleClass1::ExampleClass2::passbyPointer(int *pValue)
{
    *pValue = 100;
    std::cout << "Integer Value : " << *pValue << std::endl;
}

void ExampleClass1::ExampleClass2::passbyReference(int &pValue1, int &pValue2)
{
    std::cout << "Before changing Integer Overloaded Values : " << pValue1 << "  " << pValue2 << std::endl;
    pValue1 = 300;
    pValue2 = 450;

    std::cout << "After changing Integer Integer Overloaded Value : " << pValue1 << "  " << pValue2 << std::endl;
}

void ExampleClass1::ExampleClass2::passbyValue(int pValue1, int pValue2)
{
    int tValue = pValue1;
    int tValue2 = pValue2;
    pValue1 = 550;
    pValue2 = 580;
    std::cout << "Integer Overloaded Value  : " << pValue1 << "  " << pValue2 << std::endl;
}

void ExampleClass1::ExampleClass2::passbyPointer(int *pValue1, int *pValue2)
{
    *pValue1 = 1200;
    *pValue2 = 1400;
    std::cout << "Integer Overloaded Value  : " << *pValue1 << "  " << *pValue2 << std::endl;
}

void ExampleClass1::ExampleClass2::passbyExeOverloadExample()
{
   int tValue1 = 80;
   int tValue2 = 450;
    passbyReference(tValue1,tValue2);
    passbyValue(tValue1,tValue2);
    passbyPointer(&tValue1,&tValue2); 
}

void ExampleClass1::ExampleClass2::passbyExeExample()
{
    int tValue = 80;
    passbyReference(tValue);
    passbyValue(tValue);
    passbyPointer(&tValue);
}

int ExampleClass1::ExampleClass2::getValue() const
{
    mValue++;
    return mValue;
}
