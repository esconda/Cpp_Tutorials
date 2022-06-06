#include "StdOptional.h"

StdOptional::StdOptional()
{
}

void StdOptional::optionalInitializing()
{
    //Aşağıdaki kodda optional<int> türünden op1, op2 ve op3 isimli nesneler hayata boş olarak getiriliyorlar.
    //nullopt bu boş sınıf türünden oluşturulan ve sabit ifadesi olarak kullanılabilen bir constexpr sınıf nesnesi
    //optional sınıfının nullopt_t türünden parametreye sahip kurucu işlevi, nullopt sabiti ile çağrıldığında bu kurucu işlev boş bir optional nesnesini hayata getiriyor.
    std::optional<int> op1;               //empty
    std::optional<int> op2{};             //empty
    std::optional<int> op3{std::nullopt}; //empty

    std::cout << "OP1 Value : " << *op1 << std::endl;
    std::cout << "OP2 Value : " << *op2 << std::endl;
    std::cout << "OP3 Value : " << *op3 << std::endl;
}
void StdOptional::stdOptionalProcess()
{
    //std::optional Operations
    std::optional<int> op4{100};
    std::cout << "OP4 Value : " << *op4 << std::endl;
    op4 = std::nullopt;
    std::cout << "Op4 Value After Nullable : " << *op4 << std::endl;
}
void StdOptional::stdOptionalStructExample()
{
    Uav uavStructs;
    UavBaseControl uavBaseControlCpy;
    uavStructs.uavBaseControl = uavBaseControlCpy; // if we do not define BaseControlCpy struct, it does not enter if condition and not used
    uavStructs.name = "Akinci";
    uavStructs.uavBaseControl->name = "Ground Control System Kesan";

    if (uavStructs.uavBaseControl)
    {
        std::cout << uavStructs.name << "'s Basecontrol's name is " << uavStructs.uavBaseControl->name << std::endl;
    }

    else
    {
        std::cout << uavStructs.name << " is alone." << std::endl;
    }
}

std::optional<float> StdOptional::stdOptionalReturnVal()
{
    float a = 20;
    float b = 4;
    float divide = a / b;
    if (b != 0.f)
    {
        std::cout<<"Optional division : "<<divide<<std::endl;
        return a / b;
    }
    return {};
}

void StdOptional::stdOptionalValueOr(){
    std::optional<std::string> a;
    a=std::nullopt;

    std::cout<<"A value is : "<<a.value_or("<ValueMissing>")<<std::endl;//value_or either returns the value stored in the optional, or the argument if there is nothing store there
}