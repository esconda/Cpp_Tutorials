#ifndef FINALCLASSANDSTRUCTS_H
#define FINALCLASSANDSTRUCTS_H

#include <iostream>
#include <cstring>
#include <functional>
//Author : Burak Dogancay
//ClassBasics1 is equal to ClassBasics
class FinalClassAndStructs final
{
public:
    FinalClassAndStructs();
    FinalClassAndStructs(int val);
    FinalClassAndStructs(const FinalClassAndStructs &ruleOfThree);            // II. COPY CONSTRUCTOR
    FinalClassAndStructs &operator=(const FinalClassAndStructs &ruleOfThree); // III. COPY ASSIGNMENT
    ~FinalClassAndStructs();


};

//Final class may appear anywhere in class hierarchy:
class FinalClassAndStructs1 {
};

// OK.
class FinalClassAndStructs2 final : public FinalClassAndStructs1 {
};
/* // Compilation error: cannot derive from final class B.
class FinalClassAndStructs3 : public FinalClassAndStructs2 {
}; */

#endif