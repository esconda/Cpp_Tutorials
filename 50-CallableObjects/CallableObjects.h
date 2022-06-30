// Author: Burak Doğançay
#ifndef CALLABLEOBJECTS_H
#define CALLABLEOBJECTS_H
#include <iostream>
#include <memory>
#include <thread>
#include <vector>
#include <algorithm>
/* Callable objects are the collection of all C++ structures which can be used as a function. In practice, this are all
things you can pass to the C++17 STL function invoke() or which can be used in the constructor of std::function, this
includes: Function pointers, Classes with operator(), Classes with implicit conversions, References to functions,
Pointers to member functions, Pointers to member data, lambdas. The callable objects are used in many STL
algorithms as predicate. */

/* typedef returnType(*name)(arguments); // All
using name = returnType(*)(arguments); // <= C++11
using name = std::add_pointer<returnType(arguments)>::type; // <= C++11
using name = std::add_pointer_t<returnType(arguments)>; // <= C++14 */

using LessThanFunctionPtr = std::add_pointer<bool(int,int)>;

class CallableObjects
{
public:
    CallableObjects();
    
    bool lessThanInt(int first, int second);
    typedef struct GreaterThanInt {static bool cmp(int first, int second);} GreaterThanInt;
    void sortVectorInt(std::vector<int> &v, LessThanFunctionPtr lessThan);

    void applyFunctions();

    

};

#endif