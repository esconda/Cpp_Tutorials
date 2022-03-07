#ifndef INTEGERSEQUENCE_H
#define INTEGERSEQUENCE_H

#include <iostream>
#include <cstring>
#include <functional>
#include <optional>
#include <forward_list>
#include <tuple>
#include <utility>


class IntegerSequence
{
public:
    IntegerSequence();
    IntegerSequence(int val) = delete;
    IntegerSequence(IntegerSequence &&ruleOfFive) noexcept = delete;         //III. MOVE CONSTRUCTOR
    IntegerSequence(const IntegerSequence &ruleOfThree) = delete;            // II. COPY CONSTRUCTOR
    IntegerSequence &operator=(const IntegerSequence &ruleOfThree) = delete; // III. COPY ASSIGNMENT
    ~IntegerSequence() = default;

    void func(int i, std::string const& s);
    void func(int i, double d, std::string const& s);
    void func(char c, int i, double d, std::string const& s);
    void func(int i, int j, int k);

    template<typename Tuple, std::size_t... I>
    void processSub(Tuple const& tuple, std::index_sequence<I...>);

    template <typename Tuple>
    void process(Tuple const& tuple);


};

#endif