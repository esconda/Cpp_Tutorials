//Author : Burak Dogancay
//Below implementation macros are called include guards
/* A header file may be included by other header files. A source file (compilation unit) that includes multiple headers
may therefore, indirectly, include some headers more than once. If such a header file that is included more than
once contains definitions, the compiler (after preprocessing) detects a violation of the One Definition Rule 

Multiple inclusion is prevented using "include guards", which are sometimes also known as header guards or macro
guards.

The key advantage of using include guards is that they will work with all standard-compliant compilers and
preprocessors.
*/
#ifndef INCLUDEGUARDS_H //INCLUDE GUARDS THAT PREVENTS TO USE THIS HEADER FILE MORE THAN ONCE
#define INCLUDEGUARDS_H

#include <iostream>
#include <chrono>
#include <functional>
#include <memory>

/* The C preprocessor is a simple text parser/replacer that is run before the actual compilation of the code. Used to
extend and ease the use of the C (and later C++) language, it can be used for: */

/* a. Including other files using #include
b. Define a text-replacement macro using #define
c. Conditional Compilation using#if #ifdef
d. Platform/Compiler specific logic (as an extension of conditional compilation) */

class IncludeGuards
{
public:
    IncludeGuards();
    IncludeGuards(int val) = delete;
    IncludeGuards(IncludeGuards &&ruleOfFive) noexcept = delete;         //III. MOVE CONSTRUCTOR
    IncludeGuards(const IncludeGuards &ruleOfThree) = delete;            // II. COPY CONSTRUCTOR
    IncludeGuards &operator=(const IncludeGuards &ruleOfThree) = delete; // III. COPY ASSIGNMENT
    ~IncludeGuards() = default; //Destructor

    void checkIncludeGuards();
};

#endif