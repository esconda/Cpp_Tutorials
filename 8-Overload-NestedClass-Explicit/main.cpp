#include "Overload-NestedClass-Explicit.h"
#include <iostream>

int main(){
    ExampleClass1::ExampleClass2 relatedClass;
    ExampleClass1::ExampleClass2 explicitClass(20); //Explicit class example

    int tVal = 90;
    ExampleClass1::ExampleClass2 explicitClass2  = static_cast<ExampleClass1::ExampleClass2>(tVal);

    relatedClass.passbyExeExample();
    relatedClass.passbyExeOverloadExample();
    
    relatedClass.function();

    const int incVariable = relatedClass.getValue();
    std::cout<<"Incremented Variable : "<< incVariable << std::endl;

    
}