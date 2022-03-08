#include "RuleofFive-Ruleofthree.h"
RuleOfThree::RuleOfThree()
{
}

RuleOfThree::RuleOfThree(const char *s, std::size_t n):  cstring(new char[n])
{
    std::memcpy(cstring, s, n);
}

RuleOfThree::RuleOfThree(const char *s = " ") : RuleOfThree(s, std::strlen(s) + 1)
{
}
/*
A copy constructor is a member function that initializes an object using another object of the same class. A copy constructor has the following general function prototype: 
In C++, a Copy Constructor may be called in the following cases: 

1)Initialize one object from another of the same type.
2)Copy an object to pass it as an argument to a function.
3)Copy an object to return it from a function.

1. When an object of the class is returned by value. 
2. When an object of the class is passed (to a function) by value as an argument. 
3. When an object is constructed based on another object of the same class. 
4. When the compiler generates a temporary object.
It is, however, not guaranteed that a copy constructor will be called in all these cases, because the C++ Standard allows the compiler to optimize the copy away in certain cases
*/
RuleOfThree::RuleOfThree(const RuleOfThree &ruleOfThree) : RuleOfThree(ruleOfThree.cstring) //COPY CONSTRUCTOR
{

}

RuleOfThree::~RuleOfThree() //DESTRUCTOR
{
    delete[] cstring;
}

RuleOfThree &RuleOfThree::operator=(const RuleOfThree &ruleOfThree) // COPY ASSIGNMENT
{
    if (this == &ruleOfThree)
        return *this;

    std::size_t n{std::strlen(ruleOfThree.cstring) + 1};
    char *new_cstring = new char[n];                  // allocate
    std::memcpy(new_cstring, ruleOfThree.cstring, n); // populate

    delete[] cstring; // deallocate
    cstring = new_cstring;
    return *this;
}

//----------------------------------RULE OF FIVE-----------------------------------------
//Because the presence of a user-defined destructor, copy-constructor, or copy-assignment operator prevents implicit definition 
//of the move constructor and the move assignment operator, any class for which move semantics are desirable, has to declare all five special member functions:
//Unlike Rule of Three, failing to provide move constructor and move assignment is usually not an error, but a missed optimization opportunity.
RuleOfFive::RuleOfFive()
{
}

RuleOfFive::RuleOfFive(const char* string = " ") : mstring(nullptr)
{
    if(string){
        std::size_t tnum = std::strlen(string)+1;
        mstring = new char[tnum]; // allocate
        std::memcpy(mstring,string,tnum);
    }
}

RuleOfFive::RuleOfFive(const RuleOfFive &ruleOfFive) : RuleOfFive(ruleOfFive.mstring) // II. COPY CONSTRUCTOR
{
}

RuleOfFive::RuleOfFive(RuleOfFive&& ruleOfFive) noexcept : mstring(std::exchange(ruleOfFive.mstring,nullptr)) //III. MOVE CONSTRUCTOR , exchange can be used move assignment or move constructor
{ 

}

RuleOfFive& RuleOfFive::operator=(const RuleOfFive& ruleOfFive)// IV COPY ASSIGNMENT
{
    return *this = RuleOfFive(ruleOfFive);
}

RuleOfFive& RuleOfFive::operator=(RuleOfFive&& ruleOfFive) noexcept// V. MOVE ASSIGNMENT
{
     std::swap(mstring, ruleOfFive.mstring);
        return *this;
}

RuleOfFive::~RuleOfFive()
{
    delete[] mstring;
}
