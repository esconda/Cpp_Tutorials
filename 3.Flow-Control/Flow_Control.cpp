#include "Flow_Control.h"

Flow_Control::Flow_Control() : mRet_Def(0),
                               mGoto_Def(0)
{
}

Flow_Control::~Flow_Control()
{
}

int Flow_Control::getRet_Def()
{
    return mRet_Def;
}

void Flow_Control::setRet_Def(int pRet_Def)
{
    mRet_Def = pRet_Def;
}

void Flow_Control::flowControlSwitch()
{
    mswitchcnt = SwitchControl::Second;

    switch (mswitchcnt)
    {
    case SwitchControl::First:
        std::cout << "First Case is Run" << std::endl;
        break;
    case SwitchControl::Second:
        std::cout << "Second Case is Run" << std::endl;
        break;
    case SwitchControl::Third:
        std::cout << "Third Case is Run" << std::endl;
        break;
    case SwitchControl::Forth:
        std::cout << "Forth Case is Run" << std::endl;
        break;
    default:
        std::cout << "Default case Run" << std::endl;
        break;
    }
}

void Flow_Control::flowControlTryCatch()
{
/* 1. To implement exception handling in C++, you use try, throw, and catch expressions.
2. First, use a try block to enclose one or more statements that might throw an exception.
3. A throw expression signals that an exceptional condition—often, an error—has occurred in a try block. You
can use an object of any type as the operand of a throw expression. Typically, this object is used to
communicate information about the error. In most cases, we recommend that you use the std::exception
class or one of the derived classes that are defined in the standard library. If one of those is not appropriate,
we recommend that you derive your own exception class from std::exception.
4. To handle exceptions that may be thrown, implement one or more catch blocks immediately following a try
block. Each catch block specifies the type of exception it can handle */
    try
    {
        std::vector<int> v(5);
        // do something
        v.assign(5, 200);
        if (*v.begin() > 100)
        {
            std::cout << "first val of vector is bigger than 100" << std::endl;
            std::cout << "First Value is: " << *v.begin() << std::endl;

            for (std::vector<int>::iterator i = v.begin(); i != v.end(); ++i)
            {
                std::cout << *i;
            }
        }
    }
    catch (const std::bad_alloc &)
    {
        std::cout << "failed to allocate memory for vector!" << std::endl;
    }
    catch (const std::runtime_error &e)
    {
        std::cout << "runtime error: " << e.what() << std::endl;
    }
    catch (...)
    {
        std::cout << "unexpected exception!" << std::endl;
        throw;
    }
}

void Flow_Control::flowControlGoto()
{
    if (!mGoto_Def)
    {
        goto end;
    }
end:
    std::cout << "Go to def is realized"<<std::endl;
    std::cout << "It is run correctly";
}

void Flow_Control::flowControlForLoop()
{
    std::vector<int> v = {0, 1, 2, 3, 4, 5};

    for (const int &i : v) // access by const reference
        std::cout << i << ' ';
    std::cout << '\n';

    for (auto i : v) // access by value, the type of i is int
        std::cout << i << ' ';
    std::cout << '\n';

    for (auto &&i : v) // access by forwarding reference, the type of i is int&
        std::cout << i << ' ';
    std::cout << '\n';

    const auto &cv = v;

    for (auto &&i : cv) // access by f-d reference, the type of i is const int&
        std::cout << i << ' ';
    std::cout << '\n';

    for (int n : {0, 1, 2, 3, 4, 5}) // the initializer may be a braced-init-list
        std::cout << n << ' ';
    std::cout << '\n';

    int a[] = {0, 1, 2, 3, 4, 5};
    for (int n : a) // the initializer may be an array
        std::cout << n << ' ';
    std::cout << '\n';

    for ([[maybe_unused]] int n : a)
        std::cout << 1 << ' '; // the loop variable need not be used
    std::cout << '\n';

    // for (auto n = v.size(); auto i : v) // the init-statement (C++20)
    //    std::cout << --n + i << ' ';
    // std::cout << '\n';
}