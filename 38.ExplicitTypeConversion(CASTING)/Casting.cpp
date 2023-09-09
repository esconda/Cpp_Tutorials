#include "Casting.h"

Casting::Casting()
{
}

void Casting::constCastEx()
{
    /* A pointer to a const object can be converted to a pointer to non-const object using the const_cast keyword. Here
we use const_cast to call a function that is not const-correct. It only accepts a non-const char* argument even
though it never writes through the pointer: */
    const char *s = "Const cast is done";
    char *a = NULL;
    // a=s Error invalid conversion from 'const char*' to 'char*
    a = const_cast<char *>(s);

    std::cout << "Constant Cast Example : " << a << std::endl;
}

void Casting::staticCastEx()
{
    /* A pointer to base class can be converted to a pointer to derived class using static_cast. static_cast does not do
any run-time checking and can lead to undefined behaviour when the pointer does not actually point to the desired
type */
    struct Base
    {
    };
    struct Derived : Base
    {
    };
    Derived d;
    Base *p1 = &d;
    // Derived *p2 = p1;                         // error; cast required
    Derived *p3 = static_cast<Derived *>(p1); // OK; p2 now points to Derived object
    Base b;
    Base *p4 = &b;
    // Derived *p5 = static_cast<Derived *>(p4); // undefined behaviour since p4 does not
    //  point to a Derived object
    //------------------------------------------------------------------------------------

    // Another Example
    float var1 = 7.0;
    int var2;
    var2 = static_cast<int>(var1);
    std::cout << "Static cast is done : " << var2 << std::endl;
}
void Casting::dynamicCastEx()
{
    /*  If the source type is polymorphic, dynamic_cast can be used to perform a base to derived conversion. It performs a
 run-time check and failure is recoverable instead of producing undefined behaviour. In the pointer case, a null
 pointer is returned upon failure. In the reference case, an exception is thrown upon failure of type std::bad_cast
 (or a class derived from std::bad_cast) */

/* Purpose: dynamic_cast is used specifically for performing safe type conversions within polymorphic class hierarchies. 
         It is primarily used with pointers or references to base and derived classes in the context of inheritance.

Type Safety: dynamic_cast performs runtime type checking, ensuring that the conversion is valid based on the actual runtime types of objects involved. 
             It returns a null pointer or throws a std::bad_cast exception if the conversion is not possible. */
    struct Base
    {
        virtual ~Base();
    }; // Base is polymorphic
    struct Derived : Base
    {
        override ~Base();
    };
    Base *b1 = new Derived;
    Derived *d1 = dynamic_cast<Derived *>(b1); // OK; d1 points to Derived object
    Base *b2 = new Base;
    Derived *d2 = dynamic_cast<Derived *>(b2); // d2 is a null pointer
}

void Casting::reinterpretCastEx()
{
/* Purpose: reinterpret_cast is used for low-level type conversions, 
            typically between unrelated pointer types or when you need to treat a block of memory as a different type. 
            It is the most powerful but also the riskiest casting operator because it bypasses C++'s type safety checks.
   Type Safety: reinterpret_cast offers no type safety checks. 
                It allows you to convert pointers from one type to another without regard for their actual structure or relationship. */
    //A pointer(resp.reference) to an object type can be converted to a pointer(resp.reference) to any other object type using reinterpret_cast.This does not call any constructors or conversion functions.int x = 42;
    char *p = static_cast<char *>(&x);      // error: static_cast cannot perform this conversion
    char *p = reinterpret_cast<char *>(&x); // OK
    *p = 'z';                               // maybe this modifies x (see below)

//The result of reinterpret_cast represents the same address as the operand, provided that the address is
//appropriately aligned for the destination type. Otherwise, the result is unspecified.
    int x = 42;
    char& r = reinterpret_cast<char&>(x);
    const void* px = &x;
    const void* pr = &r;
    assert(px == pr);
}

void Casting::enumConversion()
{
    enum class Format
    {
        TEXT = 0,
        PDF = 1000,
        OTHER = 2000,
    };
    Format f = Format::PDF;
    int a = f;                         // error
    int b = static_cast<int>(f);       // ok; b is 1000
    char c = static_cast<char>(f);     // unspecified, if 1000 doesn't fit into char
    double d = static_cast<double>(f); // d is 1000.0... probably
}

void Casting::voidPointertoTpointer()
{
    // allocating an array of 100 ints, the hard way
    // int *a = malloc(100 * sizeof(*a));                     // error; malloc returns void*
    int *a = static_cast<int *>(malloc(100 * sizeof(*a))); // ok
    // int* a = new int[100]; // no cast needed
    // std::vector<int> a(100); // better
    const char c = '!';
    const void *p1 = &c;
    const char *p2 = p1;                            // error
    const char *p3 = static_cast<const char *>(p1); // ok; p3 points to c
    const int *p4 = static_cast<const int *>(p1);   // unspecified in C++03;
    // possibly unspecified in C++11 if
    // alignof(int) > alignof(char)
    char *p5 = static_cast<char *>(p1); // error: casting away constness
}