#include "Templates.h"
#include "Templates.cpp"
#include <iostream>

int main()
{
    // 1)BASIC TEMPLATES EXAMPLE
    Templates<int> tempInt;
    tempInt.setNum(1);
    std::cout << "Integer Value is : " << tempInt.plus1() << std::endl;

    Templates<double> tempDouble;
    tempDouble.setNum(1.456);
    std::cout << "Double Value is : " << tempDouble.plus1() << std::endl;

    Templates<float> tempFloat;
    tempFloat.setNum(1.4);
    std::cout << "Float Value is : " << tempFloat.plus1() << std::endl;

    TemplatesAnother tempNorm;

    // 2)FUNCTION TEMPLATE EXAMPLE
    tempInt.printSum<int>(4, 5);
    tempInt.printSum<int>(4.5f, 8.9f);

    // 3)FUNCTION TEMPLATE STRUCT APROACH
    // auto val1 = tempNorm.MyPair<int, float>{ 5, 10.2};// Create object explicitly defining the types
    auto val2 = tempNorm.make_MyPair(3, 6.6); // Create object using the types of the parameters.
                                              // In this code both val1 and val2 are the same
                                              // type.
    // std::cout<<"First Variable : "<<val1<<std::endl;
    std::cout << "Second Variable : " << val2.first << " : " << val2.second << std::endl;

    // 4)Variadic Template
    auto variadicVar = tempNorm.make_MyDataStruct(1, 2.1, "hello");
    std::cout << "Variadic Template First Variable : " << variadicVar.first << std::endl;
    std::cout << "Variadic Template Rest of Variable : " << variadicVar.rest.first << " : " << variadicVar.rest.rest.first << std::endl;

    // 5)Argument Forwardin
    tempNorm.f(tempNorm.x); // calls f<X&>(x)
    // tempNorm.f(tempNorm.X()); // calls f<X>(x)

    // 6)Partial Template Specialization
    tempNorm.d.foo(5.0);
    std::cout << tempNorm.d.another_value << std::endl;

    // 7)Template Specialization
    tempNorm.sqrt<double>(36.0);

    // 8)Alias Template
    tempNorm.alPointer = new int(20);
    std::cout << "Alias Pointer is : " << *tempNorm.alPointer << std::endl;

    // 10)None Type Template Parameter
    char anArrayOfChar[15];
    std::cout << "anArrayOfChar: " << tempNorm.size_of(anArrayOfChar) << "\n";
    int anArrayOfData[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    std::cout << "anArrayOfData: " << tempNorm.size_of(anArrayOfData) << "\n";

    //11)Template Template Parameters
    std::cout<<"Value odf templaet template : "<<tempNorm.mTempType.val2<<std::endl;
}