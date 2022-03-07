#ifndef STDOPTIONAL_H
#define STDOPTIONAL_H

#include <iostream>
#include <cstring>
#include <functional>
#include <optional>

/*
std::optional<T> türünden bir nesne, programın çalışma zamanının belirli bir noktasında T türünden bir değer tutuyor ya da tutmuyor durumda olabilir. 
optional nesnesinin bir değere sahip olması kadar bir değere sahip olmaması da son derece doğal bir durum. Size bir bardak veriliyor. Bardak dolu da olabilir boş da.
Diğer taraftan bir optional nesnesi tutacağı değer için kendisi için ayrılmış bir bellek alanınını kullanıyor. Yani dinamik bir bellek alanına ihtiyaç duymuyor. 
*/
class StdOptional
{
public:
    StdOptional();
    StdOptional(int val) = delete;
    StdOptional(StdOptional &&ruleOfFive) noexcept = delete;         //III. MOVE CONSTRUCTOR
    StdOptional(const StdOptional &ruleOfThree) = delete;            // II. COPY CONSTRUCTOR
    StdOptional &operator=(const StdOptional &ruleOfThree) = delete; // III. COPY ASSIGNMENT
    ~StdOptional() = default;

    struct  UavBaseControl
    {
        std::string name;
    };

    struct Uav{
        std::string name;
        std::optional<UavBaseControl> uavBaseControl;
    };
    

    void optionalInitializing();
    void stdOptionalProcess();
    void stdOptionalStructExample();
    std::optional<float> stdOptionalReturnVal();
    void stdOptionalValueOr();

};

#endif