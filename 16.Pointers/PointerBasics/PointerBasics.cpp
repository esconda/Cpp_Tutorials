#include "PointerBasics.h"

PointerBasics::PointerBasics()
{
}

PointerBasics::PointerBasics(int val)
{
}

PointerBasics::~PointerBasics()
{
}

PointerBasics::PointerBasics(const PointerBasics &ruleOfThree)
{
}

PointerBasics &PointerBasics::operator=(const PointerBasics &ruleOfThree)
{
}

void PointerBasics::print()
{
    std::cout << "Everything works fine here";
}
void PointerBasics::pointerOperations()
{
    /* There are two operators for pointers: Address-of operator (&): Returns the memory address of its operand.
Contents-of (Dereference) operator(*): Returns the value of the variable located at the address specified by its
operator. */
    int var = 20;
    int *ptr;
    ptr = &var;

    std::cout << var << std::endl; //Value

    std::cout << ptr << std::endl; //pointer adress

    std::cout << *ptr << std::endl; //variable stored in the pointer
}

void PointerBasics::creatingPointerVariable()
{
    typedef struct
    {
        long long int var1; //8 bytes
        long long int var2; //8 bytes
        long long int var3; //8 bytes

    } big_struct;

    big_struct tstruct;
    big_struct *tstructPtr = nullptr;

    std::cout << "sizeof(tstruct) = " << sizeof(tstruct) << std::endl;
    // Print the size of `p_bar`.
    std::cout << "sizeof(tstructPtr) = " << sizeof(tstructPtr) << std::endl;

    // tstructPtr1 is now nullptr, tstructPtr2 is &tstruct.
    // Copy `tstruct` into `tstructPtr`.
    big_struct *tstructPtr1 = tstructPtr;

    // Take the address of `bar` into `p_bar_2`
    big_struct *tstructPtr2 = &tstruct;

    // tstructPtr is now &tstruct.
    tstructPtr = tstructPtr2;

    tstructPtr2 = nullptr;

    /* 
* assigning two pointers does not overwrite the memory that the assigned pointer refers to;
* pointers can be null.
* the address of operator is required explicitly. */

    (*tstructPtr).var1 = 5;
    std::cout << "Pointer to struct variable var2 is : " << tstructPtr->var1 << " and " << tstruct.var1 << std::endl;
}