#ifndef NAMESPACEEXAMPLE_H
#define NAMESPACEEXAMPLE_H

#include <iostream>
#include <cstring>
#include <functional>
//Author : Burak Dogancay
/* A C++ namespace is a collection of C++ entities (functions, classes, variables), whose names are prefixed by the
name of the namespace. When writing code within a namespace, named entities belonging to that namespace
need not be prefixed with the namespace name, but entities outside of it must use the fully qualified name. The
fully qualified name has the format <namespace>::<entity>. Example: */
//Using directive
/* namespace NameBased
{
    namespace NameDerived  //If it is inline namespace you have to call it exact NameBased::NameDerived::Namespace 
    {
        class NameSpaceExample
        {
        public:
            NameSpaceExample();
            NameSpaceExample(int val) = delete;
            NameSpaceExample(NameSpaceExample &&ruleOfFive) noexcept = delete;         //III. MOVE CONSTRUCTOR
            NameSpaceExample(const NameSpaceExample &ruleOfThree) = delete;            // II. COPY CONSTRUCTOR
            NameSpaceExample &operator=(const NameSpaceExample &ruleOfThree) = delete; // III. COPY ASSIGNMENT
            ~NameSpaceExample() = default;

            void printNamespace();
        };
    }
}
 */
//SAME CLASS CAN BE DEFINED LIKE THIS
/* It is recommended to never use unnamed namespaces in header files as this gives a version of the content for
every translation unit it is included in. This is especially important if you define non-const globals. */
namespace NameBased::NameDerived
{

    class NameSpaceExample
    {
    public:
        NameSpaceExample();
        NameSpaceExample(int val) = delete;
        NameSpaceExample(NameSpaceExample &&ruleOfFive) noexcept = delete;         //III. MOVE CONSTRUCTOR
        NameSpaceExample(const NameSpaceExample &ruleOfThree) = delete;            // II. COPY CONSTRUCTOR
        NameSpaceExample &operator=(const NameSpaceExample &ruleOfThree) = delete; // III. COPY ASSIGNMENT
        ~NameSpaceExample() = default;

        void printNamespace();
    };
}

#endif