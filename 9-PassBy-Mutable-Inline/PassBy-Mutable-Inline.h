#include <iostream>
#include <vector>
#include <cstring>
#include <cstddef>
#include <utility>
//Author : Burak Dogancay
class PassByExample
{

public:
    PassByExample();
    ~PassByExample(); // I DESTRUCTOR

    //PASS BY EXAMPLES
    void passbyReference(int &pValue);
    void passbyValue(int pValue);
    void passbyPointer(int *pValue);

    //Pass by example execution
    void passbyExeExample();

    //MUTABLE EXAMPLE
    void mutableExample();

    //INLINE FUNCTIONS(This is just a suggestion to compiler to make the function inline,
    //if function is big (in term of executable instruction etc) then, compiler can ignore the “inline” request and treat the function as normal function.)
    //The inline functions are a C++ enhancement feature to increase the execution time of a program.
    inline void function()
    {
        int tInlineVar = 500;
        int *tPointerVar;
        tPointerVar = &tInlineVar;
        std::cout << "Pointer Variable : " << *tPointerVar <<std::endl;
    }

    mutable int mValue; // can be changed in const getValue function because it is mutable
    int getValue() const;

private:
    char *cstring;
};
