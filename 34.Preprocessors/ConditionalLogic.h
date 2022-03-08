#ifndef CONDITIONALLOGIC_H 
#define CONDITIONALLOGIC_H
#define IOSTREAM
#define WIN32
//Author : Burak Dogancay
/* In a nutshell, conditional pre-processing logic is about making code-logic available or unavailable for compilation
using macro definitions.
Three prominent use-cases are:
different app profiles (e.g. debug, release, testing, optimised) that can be candidates of the same app (e.g.
with extra logging).
cross-platform compiles - single code-base, multiple compilation platforms.
utilising a common code-base for multiple application versions (e.g. Basic, Premium and Pro versions of a
software) - with slightly different features. */
#ifdef IOSTREAM
#include <iostream>
#else
#include <ostream>
#endif
//or
/* #ifndef IOSTREAM
#include <ostream>
#endif */

#ifdef WIN32
#include <windows.h>
#include <cstdio>
#endif


class ConditionalLogic
{
public:
    ConditionalLogic();
    ConditionalLogic(int val) = delete;
    ConditionalLogic(ConditionalLogic &&ruleOfFive) noexcept = delete;         //III. MOVE CONSTRUCTOR
    ConditionalLogic(const ConditionalLogic &ruleOfThree) = delete;            // II. COPY CONSTRUCTOR
    ConditionalLogic &operator=(const ConditionalLogic &ruleOfThree) = delete; // III. COPY ASSIGNMENT
    ~ConditionalLogic() = default; //Destructor

    bool printVariable(int var);
    bool removeFileDirectly(const std::string &path);
};

#endif