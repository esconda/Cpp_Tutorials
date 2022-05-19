//Author: Burak Doğançay
#include "UndefinedBehaviour.h"

UndefinedBehaviour::UndefinedBehaviour()
{
}

void UndefinedBehaviour::readingOrWritingnullPointer(){
    int *myPtr = nullptr;
    std::cout<<"My pointer is : "<<myPtr<<std::endl;
    *myPtr = 1;//Undefined behaviour
}

void UndefinedBehaviour::unInitVariable(){
    //Using an uninitialized local variable results in undefined behavior, because a is uninitialised.
    int x;
    std::cout<<x<<std::endl;

    //Using an indeterminate value of unsigned char type does not produce undefined behavior if the value is used as:
    //the second or third operand of the ternary conditional operator;
    //the right operand of the built-in comma operator;
    //the operand of a conversion to unsigned char;
    //the right operand of the assignment operator, if the left operand is also of type unsigned char;
    //the initializer for an unsigned char object;

    static int y;
    std::cout<< y <<std::endl; //Defined Behaviour y is 0
}

void UndefinedBehaviour::accessOutOfBoundsIndex() {
    //It is undefined behavior to access an index that is out of bounds for an array (or standard library container for that
    //matter, as they are all implemented using a raw array):
    int array[] = { 1,2,3,4,5,6,7,8,9};
    array[9] = 0;//UndefinedBehaviour
}

//Deleting a derived object via a pointer to a
//base class that doesn't have a virtual destructor

void UndefinedBehaviour::invalidPointerArithmetic(){
    //Addition or subtraction of an integer, if the result does not belong to the same array object as the pointer operand. (Here, the element one past the end is considered to still belong to the array.)
    int x[10];
    int* ptr1 = &x[5];
    int* ptr2 = ptr1 + 4; // ok; p2 points to a[9]
    int* ptr3 = ptr1 + 5; // ok; p2 points to one past the end of a
    int* ptr4 = ptr1 + 6; // Undefined Behaviour
    int* ptr5 = ptr1 - 5; // ok; p2 points to a[0]
    int* ptr6 = ptr1 - 6; // Undefined Behavour
    int* ptr7 = ptr3 - 5; // ok; p7 points to a[5]

    //Subtraction of two pointers if they do not both belong to the same array object. (Again, the element one past
    //the end is considered to belong to the array.) The exception is that two null pointers may be subtracted,
    //yielding 0.
    int y[10];
    int z[10];
    int *ptr8 = &y[8], *ptr9 = &y[3];
    int d1 = ptr8 - ptr9; // yields 5
    int *ptr10 = ptr9 + 2; // ok; p3 points to one past the end of a
    int d2 = ptr10 - ptr9; // yields 7
    int *ptr11 = &z[0];
    int d3 = ptr11 - ptr8; // Undefined Behaviour
    //Subtraction of two pointers if the result overflows std::ptrdiff_t.

    //Any pointer arithmetic where either operand's pointee type does not match the dynamic type of the object
    //pointed to (ignoring cv-qualification). According to the standard, "[in] particular, a pointer to a base class
    //cannot be used for pointer arithmetic when the array contains objects of a derived class type."

    struct Base { int x; };
    struct Derived : Base { int y; };
    Derived a[10];
    Base* p1 = &a[1]; // ok
    Base* p2 = p1 + 1; // UB; p1 points to Derived
    Base* p3 = p1 - 1; // likewise
    Base* p4 = &a[2]; // ok
    auto p5 = p4 - p1; // UB; p4 and p1 point to Derived
    const Derived* p6 = &a[1];
    const Derived* p7 = p6 + 1; // ok; cv-qualifiers don't matter
}

int UndefinedBehaviour::nonreturnTypeUB(){
    //Undefined behaviour
}

void UndefinedBehaviour::accessDanglingReference(){
    //It is illegal to access a reference to an object that has gone out of scope or been otherwise destroyed. Such a
    //reference is said to be dangling since it no longer refers to a valid object.
    int& var = getVar();
    std::cout << r<<std::endl;

    //In this example, the local variable x goes out of scope when getX returns. (Note that lifetime extension cannot
    //extend the lifetime of a local variable past the scope of the block in which it is defined.) Therefore r is a dangling
    //reference. This program has undefined behavior, although it may appear to work and print 42 in some cases.
}

void UndefinedBehaviour::intDivisionByZero(){
    int x = 5 / 0; //Undefined Behaviour
    //Division by 0 is mathematically undefined, and as such it makes sense that this is undefined behavior.
    float x = 5.0f / 0.0f; //x is +infinity
    //Most implementation implement IEEE-754, which defines floating point division by zero to return NaN
}

void UndefinedBehaviour::shiftingInvalidNumber(){
    //For the built-in shift operator, the right operand must be nonnegative and strictly less than the bit width of the
    //promoted left operand. Otherwise, the behavior is undefined.
    const int a = 30;
    const int b = a << -1; // UB
    const int c = a << 0; // ok
    const int d = a << 32; // UB if int is 32 bits or less
    const int e = a >> 32; // also UB if int is 32 bits or less
    const signed char f = 'x';
    const int g = f << 10; // ok even if signed char is 10 bits
}

void UndefinedBehaviour::incorrectPairingMemAlloc(){
    //An object can only be deallocated by delete if it was allocated by new and is not an array. If the argument to delete
    //was not returned by new or is an array, the behavior is undefined.
    int* ptr1 = new int;
    delete ptr1; // correct
    // delete[] p1; // undefined
    // free(p1); // undefined

    int* ptr2 = new int[10];
    delete[] ptr2; // correct
    // delete p2; // undefined
    // free(p2); // undefined
    
    int* ptr3 = static_cast<int*>(malloc(sizeof(int)));
    free(ptr3); // correct
    // delete p3; // undefined
    // delete[] p3; // undefined
}

void UndefinedBehaviour::signedIntegerOverflow(){

    int x = INT_MAX + 1; // x can be anything -> Undefined behavior
    unsigned int x = UINT_MAX + 1; // x is 0
}

void UndefinedBehaviour::modifyConstObj(){
    //Any attempt to modify a const object results in undefined behavior. This applies to const variables, members of
    //const objects, and class members declared const. (However, a mutable member of a const object is not const.)
    //A compiler will usually inline the value of a const int object, so it's possible that this code compiles and prints 123.
    //Compilers can also place const objects' values in read-only memory, so a segmentation fault may occur.
    //In any case, the behavior is undefined and the program might do anything.
    const int x = 123;
    const_cast<int&>(x) = 456;
    std::cout << x << '\n';
}

void UndefinedBehaviour::returnFromFunction(){

    [[ noreturn ]] void f() {
        throw "error"; // OK
    }

    [[ noreturn ]] void q(int i) { // behavior is undefined if called with an argument <= 0
        if (i > 0)
        throw "positive";
    }
}

void UndefinedBehaviour::infTemplateRecursion(){

    template<class T> class X {
        X<T>* p; // OK
        X<T*> a; // implicit generation of X<T> requires
        // the implicit in/ the implicit instantiation of X<T**> which ...
    };

}

void UndefinedBehaviour::overflowDuringConv(){

    //an integer type to a floating point type,
    //a floating point type to an integer type, or
    //a floating point type to a shorter floating point type,
    double x = 1e100;
    int y = x; // int probably cannot hold numbers that large, so this is Undefined Behaviour
}

void UndefinedBehaviour::modifyingStringLiteral(){
    char *myStr = "hello world"; //"hello world" is a string literal, so modifying it gives undefined behaviour.
    myStr[0] = 'H';

    //Another definition
    char *myStr = const_cast<char *>("hello world");
    myStr[0] = 'H';
}

void UndefinedBehaviour::accessWrongTypeObj(){
    //In most cases, it is illegal to access an object of one type as though it were a different type (disregarding cvqualifiers).
    float x = 42;
    int y = reinterpret_cast<int&>(x);
}

void UndefinedBehaviour::destroyDestroyedObj(){
    //A destructor is explicitly invoked for an object that will later be automatically destroyed.
    struct MyStruct {
    ~MyStruct() { std::cout << "destroying S\n"; }
    };

    MyStruct myStruct;
    myStruct.~MyStruct();
}

void UndefinedBehaviour::floatingPointOverflow(){
    //If an arithmetic operation that yields a floating point type produces a value that is not in the range of representable
    //values of the result type, the behavior is undefined according to the C++ standard, but may be defined by other
    //standards the machine might conform to, such as IEEE 754.
    float var = 1.0;
    for (int i = 0; i < 10000; i++) {
        x *= 10.0; // will probably overflow eventually; undefined behavior
    }

}

void UndefinedBehaviour::funCallMismatchPointerType(){
    //In order to call a function through a function pointer, the function pointer's type must exactly match the function's
    //type. Otherwise, the behaviour is undefined. Example:
    int f();
    void (*p)() = reinterpret_cast<void(*)()>(f);
    p(); // undefined
}

