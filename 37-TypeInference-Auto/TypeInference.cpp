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
