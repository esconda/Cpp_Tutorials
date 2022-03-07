#ifndef STDVARIANTANY_H
#define STDVARIANTANY_H

#include <iostream>
#include <cstring>
#include <functional>
#include <vector>
#include <optional>
#include <forward_list>
#include <variant>
#include <any>
#include <cassert>
#include <set>
//Author : Burak Dogancay
/* 
This creates a variant (a tagged union) that can store either an int or a string
Variants guarantee no dynamic memory allocation (other than which is allocated by their contained types). Only
one of the types in a variant is stored there, and in rare cases (involving exceptions while assigning and no safe way
to back out) the variant can become empty. */
namespace VariantExample
{
    class StdVariant
    {
    public:
        StdVariant();
        StdVariant(int val) = delete;
        StdVariantardList(StdVariant &&ruleOfFive) noexcept = delete;  //III. MOVE CONSTRUCTOR
        StdVariant(const StdVariant &ruleOfThree) = delete;            // II. COPY CONSTRUCTOR
        StdVariant &operator=(const StdVariant &ruleOfThree) = delete; // III. COPY ASSIGNMENT
        ~StdVariant() = default;

        void variantBasicExample();
        void variantPointerExample();
    };
}
/* std::any is the smarter void* shared_ptr<void>. You can initialize an any with a value of any copyable type:

std::any a0; 
std::any a1 = 42; 
std::any a2 = month{"October"};
Like shared_ptr, any remembers how to destroy the contained value for you when the any object is destroyed. 
Unlike shared_ptr, any also remembers how to copy the contained value and does so when the any object is copied: */

namespace AnyExample
{
    class StdAny
    {
    public:
        StdAny();
        StdAny(int val) = delete;
        StdAny(StdAny &&ruleOfFive) noexcept = delete;         //III. MOVE CONSTRUCTOR
        StdAny(const StdAny &ruleOfThree) = delete;            // II. COPY CONSTRUCTOR
        StdAny &operator=(const StdAny &ruleOfThree) = delete; // III. COPY ASSIGNMENT
        ~StdAny() = default;

        void anyBasicExample();
    };
}


/* std::set is an associative container that contains a sorted set of unique objects of type Key. 
Sorting is done using the key comparison function Compare. Search, removal, and insertion operations have logarithmic complexity. 
Sets are usually implemented as red-black trees. */
namespace SetMultiSetExample
{
    class StdSetMultiset
    {
    public:
        StdSetMultiset();
        StdSetMultiset(int val) = delete;
        StdSetMultiset(StdSetMultiset &&ruleOfFive) noexcept = delete;         //III. MOVE CONSTRUCTOR
        StdSetMultiset(const StdSetMultiset &ruleOfThree) = delete;            // II. COPY CONSTRUCTOR
        StdSetMultiset &operator=(const StdSetMultiset &ruleOfThree) = delete; // III. COPY ASSIGNMENT
        ~StdSetMultiset() = default;

        void setMultisetBasicExample();
        void setMultisetOp();

        struct custom_compare final
        {
            inline bool operator()(const std::string &left, const std::string &right) const
            {
                int nLeft = atoi(left.c_str());
                int nRight = atoi(right.c_str());
                return nLeft < nRight;
            }
        };
    };
}

#endif