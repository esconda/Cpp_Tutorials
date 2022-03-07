#ifndef UNORDEREDMAP_H
#define UNORDEREDMAP_H

#include <iostream>


/* A static data member of the class may be fully defined within the class definition if it is declared inline. For
example, the following class may be defined in a header. Prior to C++17, it would have been necessary to provide a
.cpp file to contain the definition of Foo::num_instances so that it would be defined only once, but in C++17 the
multiple definitions of the inline variable Foo::num_instances all refer to the same int object.
 */
class InlineVariables
{
public:
    InlineVariables();
    InlineVariables(int val) = delete;
    InlineVariables(InlineVariables &&ruleOfFive) noexcept = delete;         //III. MOVE CONSTRUCTOR
    InlineVariables(const InlineVariables &ruleOfThree) = delete;            // II. COPY CONSTRUCTOR
    InlineVariables &operator=(const InlineVariables &ruleOfThree) = delete; // III. COPY ASSIGNMENT
    ~InlineVariables() = default;
    inline static int inlinevar = 0;
    inline static int inlinevar2 = 10;

//As a special case, a constexpr static data member is implicitly inline
    static constexpr int constExp = 0;
    static constexpr int constExp2 = 10;

    void inlineVarExample();
    void constantExpExample();
};

#endif