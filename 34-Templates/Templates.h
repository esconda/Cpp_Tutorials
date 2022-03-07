#ifndef TEMPLATES_H
#define TEMPLATES_H
#include <iostream>
#include "math.h"
// 1)BASIC CLASS TEMPLATE
template <typename T>
class Templates
{
public:
    Templates();
    void setNum(T pNumber);
    T plus1() const;
    ~Templates() = default; // Destructor
private:
    T mNumber;

public:
    // 2)FUNCTION TEMPLATE
    template <typename Type>
    void printSum(Type add1, Type add2);
    //--------------------------------------------------------------
};
class TemplatesAnother
{
public:
    TemplatesAnother();
    ~TemplatesAnother() = default; // Destructor
    /* 3)Structure Base Aproach to Template
    This feature allows us to simplify code when we combine template structures and functions. There is a common
    pattern in the standard library that allows us to make template structure X using a helper function make_X() */
    template <typename T1, typename T2>
    struct MyPair
    {
        T1 first;
        T2 second;
    };
    // A make function that has a parameter type for
    // each template parameter in the template structure.
    template <typename T1, typename T2>
    MyPair<T1, T2> make_MyPair(T1 t1, T2 t2)
    {
        return MyPair<T1, T2>{t1, t2};
    }
    //--------------------------------------------------------------

    // 4)Variadic Template Rest here
    /*   It is often useful to define classes or structures that have a variable number and type of data members which are
  defined at compile time. The canonical example is std::tuple, but sometimes is it is necessary to define your own
  custom structures */
    template <typename... Ty>
    struct DataStructure
    {
    };

    template <typename Ty, typename... Rest>
    struct DataStructure<Ty, Rest...>
    {
        DataStructure(const Ty &first, const Rest &...rest)
            : first(first), rest(rest...)
        {
        }
        Ty first;
        DataStructure<Rest...> rest;
    };

    template <typename Ty, typename... Rest>
    DataStructure<Ty, Rest...> make_MyDataStruct(Ty t1, Rest... t2)
    {
        return DataStructure<Ty, Rest...>{t1, t2...};
    }
    //--------------------------------------------------------------

    // 5)Argument Forwarding
    // Template may accept both lvalue and rvalue references using forwarding reference:
    // In this case, the real type of t will be deduced depending on the context:
    struct X
    {
    };

    template <typename Ttyp>
    void f(Ttyp &&t)
    {
    }

    X x;
    //--------------------------------------------------------------

    // 6)PARTIAL TEMPLATE SPECIALIZATION;
    //  Common case:
    template <typename T, typename U>
    struct D
    {
        T t_val;
        U u_val;
    };
    // Special case when the first template argument is fixed to int
    template <typename V>
    struct D<int, V>
    {
        double another_value = 0;
        int foo(V arg)
        {
            std::cout << arg << std::endl;
            return (int)arg;
        }
    };
    D<int, double> d;
    //--------------------------------------------------------------

    // 7)Template Specialization
    // For example if you have :
    template <typename T>
    T sqrt(T t)
    {
        std::cout << std::sqrt(t) << std::endl;
        return t;
    }
    // You can then write :
    /*  template <>
     int sqrt<int>(int i)
     {
         /* Highly optimized integer implementation */
    // return i;

    /*/}
    /* Then a user that writes sqrt(4.0) will get the generic implementation whereas sqrt(4) will get the specialized
        implementation. */
    //--------------------------------------------------------------

    // 8)Alias Template
    template <typename T>
    using aliasPointer = T *;
    aliasPointer<int> alPointer;
    //--------------------------------------------------------------

    // 9)Explicit instantiation
    /*  An explicit instantiation definition creates and declares a concrete class, function, or variable from a template,
 without using it just yet. An explicit instantiation can be referenced from other translation units. This can be used to
 avoid defining a template in a header file, if it will only be instantiated with a finite set of arguments. For example: */
    // print_string.h
    /* template <class T>
    void print_string(const T* str);
    // print_string.cpp
    #include "print_string.h"
    template void print_string(const char*);
    template void print_string(const wchar_t*); */
    //--------------------------------------------------------------

    // 10)Non-type template parameter
    /*  Apart from types as a template parameter we are allowed to declare values of constant expressions meeting one of
 the following criteria:
     *integral or enumeration type,
     *pointer to object or pointer to function,
     *lvalue reference to object or lvalue reference to function,
     *pointer to member,
     *std::nullptr_t */
    template <typename T, std::size_t size>
    std::size_t size_of(T (&anArray)[size]) // Pass array by reference. Requires.
    {                                       // an exact size. We allow all sizes
        return size;                        // by using a template "size".
    }

    // 11)Template Template Parameters
    template <typename T>
    struct Tag1
    {
        T val2 = 5;
    };
    template <typename T>
    struct Tag2
    {
        T val2 = 5;
    };
    template <template <class> typename Tag>
    struct IntTag
    {
        typedef Tag<int> type ;
    };
    IntTag<Tag1>::type mTempType;
    //--------------------------------------------------------------
};

#endif
