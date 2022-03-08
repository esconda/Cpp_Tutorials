#include "StdFunction.h"
#include <iostream>

void print_num(int i)
{
    std::cout << "Print Num free function : " << i << '\n';
}

struct PrintNum
{
    void operator()(int i) const
    {
        std::cout << "Object int Param : " << i << '\n';
    }
};

int main()
{
/* 
    function allocates memory because it needs something to copy/move into; function takes ownership of the
callable it is given. But SortMyContainer does not need to own the callable; it's just referencing it. So using function
here is overkill; it may be efficient, but it may not */
    StdFunction stdFunction;
    //--------------SIMPLE FUNCTION USAGE---------------
    std::function<void(StdFunction &, int, const std::string &)> funcCall;
    funcCall = stdFunction.simpleFunction;
    funcCall(stdFunction, 20, "String is defined"); //Pass class type if you would like to  assign function to std::function
    //----------------------------------------------------

    //--------------BIND AND STD:FUNC USAGE---------------
    std::function<void(StdFunction &, const std::string &)> bindfuncCall;
    bindfuncCall = std::bind(&StdFunction::simpleCallIntFunct, stdFunction, std::placeholders::_2);
    bindfuncCall(stdFunction, "Mystring");
    //----------------------------------------------------

    //------------store a free function------------------
    std::function<void(int)> f_display = print_num;
    f_display(18);
    //----------------------------------------------------

    //--------store a call to a function object-----------------
    std::function<void(int)> f_display_obj = PrintNum();
    f_display_obj(30);
    //----------------------------------------------------

    //--------LAMBDA STD::FUNCTION OPERATIONS--------------
    std::function<int(int)> factorial = [](int n)
    {
        // store a lambda object to emulate "recursive lambda"; aware of extra overhead
        std::function<int(int)> fac = [&](int n)
        { 
            return (n < 2) ? 1 : n * fac(n - 1); 
            
            };
        // note that "auto fac = [&](int n){...};" does not work in recursive calls
        return fac(n);
    };


    for (int i{5}; i != 8; ++i)
    {
        std::cout << i << "! = " << factorial(i) << ";  ";
    }
    //----------------------------------------------------
}