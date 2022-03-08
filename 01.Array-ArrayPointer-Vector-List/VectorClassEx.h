#ifndef VECTORCLASSEX_H
#define VECTORCLASSEX_H

#include <iostream>
#include <cstring>
#include <functional>
#include <array>

/* A function defined with the inline specifier is an inline function. An inline function can be multiply defined without
violating the One Definition Rule, and can therefore be defined in a header with external linkage. Declaring a
function inline hints to the compiler that the function should be inlined during code generation, but does not
provide a guarantee. */
class VectorClassEx
{
public:
    VectorClassEx();
    VectorClassEx(int val) = delete;
    VectorClassEx(VectorClassEx &&ruleOfFive) noexcept = default;         //III. MOVE CONSTRUCTOR
    VectorClassEx(const VectorClassEx &ruleOfThree) = default;            // II. COPY CONSTRUCTOR
    VectorClassEx &operator=(const VectorClassEx &ruleOfThree) = delete; // III. COPY ASSIGNMENT
    ~VectorClassEx() = default;

    int getIntDef() const;
    void setIntDef(const int pIntDef);

    std::string getStringDef() const;
    void setStringDef(const std::string pStringDef);

private:
    int intDef;
    std::string stringDef;

    
};

#endif