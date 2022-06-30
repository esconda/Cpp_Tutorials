// Author: Burak Doğançay
#ifndef STATICASSERT_H
#define STATICASSERT_H
#include <iostream>
#include <memory>
#include <thread>
// Assertations mean that a condition should be checked and if it's false, it's an error. For static_assert(), this is
// done compile-time.

class StaticAssert
{
public:
    StaticAssert();

    template <typename T>
    T multiplicationby10(const T t)
    {
        static_assert(std::is_integral<T>::value, "multplication() only works for integral types");
        return (t << 3) + (t << 1);
    }

    /*  A static_assert() has a mandatory first parameter, the condition, that is a bool constexpr. It might have a second
 parameter, the message, that is a string literal. From C++17, the second parameter is optional; before that, it's
 mandatory. */
    template <typename T>
    T multiplicationby10(const T t)
    {
        static_assert(std::is_integral<T>::value);
        return (t << 3) + (t << 1);
    }

/* It is used when:
In general, a verification at compile-time is required on some type on constexpr value
A template function needs to verify certain properties of a type passed to it
One wants to write test cases for:
template metafunctions
constexpr functions
macro metaprogramming
Certain defines are required (for ex., C++ version)
Porting legacy code, assertations on sizeof(T) (e.g., 32-bit int)
Certain compiler features are required for the program to work (packing, empty base class optimization, etc.) */

};

#endif