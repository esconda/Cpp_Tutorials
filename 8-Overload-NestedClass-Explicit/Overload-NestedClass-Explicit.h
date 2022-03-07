#include <iostream>
#include <vector>
#include <cstring>
#include <cstddef>
#include <utility>


//NESTED CLASS EXAMPLE
class ExampleClass1
{
public:
     class ExampleClass2
    {

    public:
        ExampleClass2();
        explicit ExampleClass2(int a);
        ~ExampleClass2(); // I DESTRUCTOR

        //PASS BY EXAMPLES
        void passbyReference(int &pValue);
        void passbyValue(int pValue);
        void passbyPointer(int *pValue);

        //OVERLOADING FUNCTIONS
        void passbyReference(int &pValue1,int &pValue2);
        void passbyValue(int pValue1, int pValue2);
        void passbyPointer(int *pValue1, int *pValue2);

        //Pass by example execution
        void passbyExeExample();
        void passbyExeOverloadExample();

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
            std::cout << "Pointer Variable : " << *tPointerVar << std::endl;
        }

        mutable int mValue; // can be changed in const getValue function because it is mutable
        int getValue() const;

    private:
        char *cstring;
    };
};
