#include "mutable.h"

MutableClass::MutableClass()
{
}

MutableClass::MutableClass(const MutableClass &ruleOfThree)
{
}

MutableClass::~MutableClass()
{
}

MutableClass &MutableClass::operator=(const MutableClass &ruleOfThree)
{
}

void MutableClass::mutableLambdas()
{

    /*By default, the implicit operator() of a lambda is const. This disallows performing non-const operations on the
lambda. In order to allow modifying members, a lambda may be marked mutable, which makes the implicit
operator() non-const:*/

    int a = 0;
    /*
    std::function<int()> bad_counter = [a] {
        return a++; // error: operator() is const
        // cannot modify members
    };
    */

    std::function<int()> good_counter = [a]() mutable {
        return a++; // OK
    };

    std::cout << good_counter() << std::endl; // 0
    std::cout << good_counter() << std::endl; // 1
    std::cout << good_counter() << std::endl; // 2
}

double MutableClass::getPi() const
{
    if (pi_calculated)
    {
        return pi;
    }
    else
    {
        double new_pi = 0;
        for (int i = 0; i < 10; ++i)
        {
            // some calculation to refine new_pi
            new_pi += i;
            
        }
        // note: if pi and pi_calculated were not mutable, we would get an error from a compiler
            // because in a const method we can not change a non-mutable field
        pi = new_pi;
        pi_calculated = true;
        std::cout<<"P Value is : "<<pi<<std::endl;
        std::cout<<"New pi Value is : " <<new_pi<<std::endl;
        return pi;
    }
}
