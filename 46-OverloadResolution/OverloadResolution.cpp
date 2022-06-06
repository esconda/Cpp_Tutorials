// Author: Burak Doğançay
#include "OverloadResolution.h"

OverloadResolution::OverloadResolution()
{
}

void OverloadResolution::categorizeArgument()
{

    //*Standart sequence
    // void f(int var); f(60);

    // User defined conversion sequence
    // void f(std::string s); f("pass string to function");

    // Ellipsis conversion sequence
    // void f(...); f(60);

    // List initialization sequence
    // void f(std::vector<int> v); f({1, 2, 3});

    // A special case is the list initialization sequence, which does not constitute a conversion (an initializer list is not an
    // expression with a type). Its cost is determined by defining it to be equivalent to one of the other three conversion
    // sequences, depending on the parameter type and form of initializer list
}

void OverloadResolution::arithmeticPromConv()
{
    // Converting an integer type to the corresponding promoted type is better than converting it to some other integer
    // type.
    // void f(int x);
    // void f(short x);
    // signed char c = 60;
    // f(c); // calls f(int); promotion to int is better than conversion to short
    // short s = 42;
    // f(s); // calls f(short); exact match is better than promotion to int
    //---------------------------------------------------------------------------

    // Promoting a float to double is better than converting it to some other floating point type
    // void f(double x);
    // void f(long double x);
    // f(3.14f); // calls f(double); promotion to double is better than conversion to long double
    //---------------------------------------------------------------------------

    // Arithmetic conversions other than promotions are neither better nor worse than each other
    /* void f(float x);
    void f(long double x);
    f(3.14); // ambiguous
    void g(long x);
    void g(long double x);
    g(42); // ambiguous
    g(3.14); // ambiguous */
}

void OverloadResolution::exactMatch()
{
    // An overload without conversions needed for parameter types or only conversions needed between types that are
    // still considered exact matches is preferred over an overload that requires other conversions in order to call
    /* void f(int x);
    void f(double x);
    f(42); // calls f(int) */
    //---------------------------------------------------------------------------

    /* void f(int& x);
    void f(double x);
    int x = 42;
    f(x); // argument type is int; exact match with int&
    void g(const int& x);
    void g(int x);
    g(x); // ambiguous; both overloads give exact match */
    //---------------------------------------------------------------------------

    /*  For the purposes of overload resolution, the type "array of T" is considered to match exactly with the type "pointer
     to T", and the function type T is considered to match exactly with the function pointer type T*, even though both
     require conversions.
     void f(int* p);
     void f(void* p);
     void g(int* p);
     void g(int (&p)[100]);
     int a[100];
     f(a); // calls f(int*); exact match with array-to-pointer conversion
     g(a); // ambiguous; both overloads give exact match */
}

void OverloadResolution::exactMatch()
{
    // Passing a pointer argument to a T* parameter, if possible, is better than passing it to a const T* parameter
    /* struct Base {};
    struct Derived : Base {};
    void f(Base* pb);
    void f(const Base* pb);
    void f(const Derived* pd);
    void f(bool b);
    Base b;
    f(&b); // f(Base*) is better than f(const Base*)
    Derived d;
    f(&d); // f(const Derived*) is better than f(Base*) though;
    // constness is only a "tie-breaker" rule */
    //---------------------------------------------------------------------------
}

void OverloadResolution::ovlerloadingHierarchy()
{
    /* The following examples will use this class hierarchy : struct A
    {
        int m;
    };
    struct B : A
    {
    };
    struct C : B
    {
    };
    The conversion from derived class type to base class type is preferred to user - defined conversions.This applies
                                                                                         when passing by value or
        by reference,
        as well as when converting pointer - to - derived to pointer - to - base.struct Unrelated
    {
        Unrelated(B b);
    };
    void f(A a);
    void f(Unrelated u);
    B b;
    f(b); // calls f(A)
    A pointer conversion from derived class to base class is also better than conversion to void *.void f(A * p);
    void f(void *p);
    B b;
    f(&b); // calls f(A*)
    If there are multiple overloads within the same chain of inheritance, the most derived base class overload is preferred.This is based on a similar principle as virtual dispatch : the "most specialized" implementation is chosen.However, overload resolution always occurs at compile time and will never implicitly down - cast.void f(const A &a);
    void f(const B &b);
    C c;
    f(c); // calls f(const B&)
    B b;
    A &r = b;
    f(r); // calls f(const A&); the f(const B&) overload is not viable
For pointers to members, which are contravariant with respect to the class, a similar rule applies in the opposite
direction: the least derived derived class is preferred.GoalKicker.com – C++ Notes for Professionals 539
void f(int B::*p);
void f(int C::*p);
int A::*p = &A::m;
f(p); // calls f(int B::*) */
}
