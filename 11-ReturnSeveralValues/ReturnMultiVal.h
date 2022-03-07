#ifndef RETURNMULTIVAL_H
#define RETURNMULTIVAL_H

#include <iostream>
#include <cstring>
#include <functional>
#include <tuple>
#include <map>
#include <utility>
#include <vector>
//Author : Burak Dogancay
//Enum and struct also keyword"
class ReturnMultiVal
{
public:
    ReturnMultiVal();
    ReturnMultiVal(int val);
    ReturnMultiVal(const ReturnMultiVal &ruleOfThree);            // II. COPY CONSTRUCTOR
    ReturnMultiVal &operator=(const ReturnMultiVal &ruleOfThree); // III. COPY ASSIGNMENT
    ~ReturnMultiVal();

    //TUPLE EXAMPLE
    std::tuple<int, int, int, int> tupleReturning(int val1, int val2, int val3); //tuple returning example, tie can be used with tuple you can check it in main function

    //STRUCTURED BINDINGS (C++17 introduces structured bindings, which makes it even easier to deal with multiple return types, as you do not
    //need to rely upon std::tie() or do any manual tuple unpacking:)
    //Map return only key and value, for multiple value binding check structural bindings
    void mapBaseReturning();

    //A struct can be used to bundle multiple return values:
    typedef struct MathOp
    {
        int add;
        int mul;
        int sub;
        int div;

        MathOp(int add, int sub, int mul, int div)
            : add(add), sub(sub), mul(mul), div(div){};
    } mathOp;
    mathOp structBaseReturning(int val1, int val2, int val3);

    //std::pair type,The struct template std::pair can bundle together exactly two return values, of any two types:
    std::pair<int,int> pairBaseReturning(int val1,int val2);

    //std::array type,The container std::array can bundle together a fixed number of return values. This number has to be known at
    //compile-time and all return values have to be of the same type:
    std::array<int,4> arrayBaseReturning(int val1,int val2);

    //std::vector type, A std::vector can be useful for returning a dynamic number of variables of the same type. The following example
    //uses int as data type, but a std::vector can hold any type that is trivially copyable:
    std::vector<int> vectorBaseReturning(int val1,int val2);
};
#endif