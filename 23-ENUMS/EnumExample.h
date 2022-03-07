#ifndef ENUMEXAMPLE_H
#define ENUMEXAMPLE_H

#include <iostream>
#include <cstring>
#include <functional>
#include <map>
#include <vector>

/* - Prefer enumerations over macros
- Use enumerations to represent sets of related named constants
- Prefer class enums over “plain” enums
- Define operations on enumerations for safe and simple use
- Avoid unnamed enumerations
- Specify the underlying type of an enumeration only when necessary
    *The default is the easiest to read and write. int is the default integer type. int is compatible with C enums.
- Specify enumerator values only when necessary 
*/
class EnumExample
{
public:
    EnumExample();
    EnumExample(int val) = delete;
    EnumExample(EnumExample &&ruleOfFive) noexcept = delete;         //III. MOVE CONSTRUCTOR
    EnumExample(const EnumExample &ruleOfThree) = delete;            // II. COPY CONSTRUCTOR
    EnumExample &operator=(const EnumExample &ruleOfThree) = delete; // III. COPY ASSIGNMENT
    ~EnumExample() = default;

    void enumClassProcess(int enumType);
    void iterator_over_enum();

    //Scoped Enum
    enum class UavTypesClass
    {
        tb2,
        akinci,
        anka,
        aksungur
    };

    //Use enumerations to represent sets of related named constants
    enum UavTypesNormal
    {
        tb2 = 0,
        akinci = 1,
        anka = 2,
        aksungur = 3
    };

    UavTypesNormal &operator++(int en)
    {
        if (en == static_cast<int>(UavTypesNormal::aksungur))
        {
            throw std::out_of_range("for E& operator ++ (E&)");
        }
        en = static_cast<int>(UavTypesNormal(static_cast<std::underlying_type<UavTypesNormal>::type>(en) + 1));
        return (UavTypesNormal&)en;
    }
};

#endif