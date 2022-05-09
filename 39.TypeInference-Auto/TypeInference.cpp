#include "TypeInference.h"

TypeInference::TypeInference()
{
}

// Auto Data type Inferences
void TypeInference::autoDataType()
{
    auto varFirst = 5;                    // varFirst = int
    auto varSecond = 2u;                  // varSecond = unsigned int
    auto varThird = &varFirst;            // varThird = int*
    const auto varFourth = varThird;      // varForth = const int&
    const auto &varFifth = varSecond;     // varFifth = const unsigned int&
    auto varSixth = varFirst + varSecond; // varSecond = unsigned int

    std::vector<int> varVector;

    auto varSeventh = varVector; // varSeventh = std::vector<int>
    varSeventh.reserve(2);
    varSeventh.assign(2, 10);

    std::function<void()> var = [=]()
    {
        std::cout << "******Auto Data Types******" << std::endl;
        std::cout << "Int : " << varFirst << std::endl;
        std::cout << "Unsigned Int : " << varSecond << std::endl;
        std::cout << "Pointer Int : " << varThird << std::endl;
        std::cout << "Const Adress of Int  : " << varFourth << std::endl;
        std::cout << "Const Unsigned Adress of Int : " << varFifth << std::endl;
        std::cout << "Unsigned Int : " << varSixth << std::endl;
        std::cout << "Vector Int : " << varSeventh[0] << " " << varSeventh[1] << std::endl;
        std::cout << "***************************" << std::endl;
    };
    var();
}

void TypeInference::autoLambda(){
    //The data type auto keyword is a convenient way for programmers to declare lambda functions. It helps by
    //shortening the amount of text programmers need to type to declare a function pointer.
    float tPi = 3.14;

    //Auto type definition Inference
    auto tCircleArea = [=](int tRadius){ return tPi * tRadius;};
    //-----------------------

    //Long way of definition
    //float (*lCircleArea)(int tRadius) = [=](int tRadius){ return  tPi * tRadius;};
    //-----------------------

    //Another long way of definition
    std::function<float(int)> circleAreaFunc = [=](int tRadius){ return tPi * tRadius;};

    //Assign return types lambda functions to variables
    auto callFirstLambda = tCircleArea(25);
    auto callSecondLambda = circleAreaFunc(45);

    std::cout << "******Lambda Auto Types******" << std::endl;
    std::cout << "First Circle Area: " <<callFirstLambda<< std::endl;
    std::cout << "Second Circle Area: " <<callSecondLambda<< std::endl;
    std::cout << "***************************" << std::endl;

    //These three inferences are same
    std::cout << "******Lambda Auto Types******" << std::endl;
    [=](int tRadius) -> int { std::cout << "First Circle Area: " <<tPi * tRadius<< std::endl; return tPi * tRadius; };
    [=](int tRadius) -> auto { std::cout << "Second Circle Area: " <<tPi * tRadius<< std::endl; return tPi * tRadius; return tPi * tRadius; };
    [=](int tRadius) { std::cout << "Third Circle Area: " <<tPi * tRadius<< std::endl; return tPi * tRadius; return tPi * tRadius; };
    std::cout << "***************************" << std::endl;
}

void TypeInference::autoLoops(){
    //AUTO DECLERATION FOR LOOPS
    std::map<int, std::string> Map;
    for (auto pair : Map) // pair = std::pair<int, std::string>
    for (const auto pair : Map) // pair = const std::pair<int, std::string>
    for (const auto& pair : Map) // pair = const std::pair<int, std::string>&
    for (auto i = 0; i < 1000; ++i) // i = int
    for (auto i = 0; i < Map.size(); ++i) // Note that i = int and not size_t
    for (auto i = Map.size(); i > 0; --i) // i = size_t
}