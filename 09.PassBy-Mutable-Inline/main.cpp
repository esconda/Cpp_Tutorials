#include "PassBy-Mutable-Inline.h"
#include <iostream>

int main(){
    PassByExample relatedClass;

    relatedClass.passbyExeExample();
    
    relatedClass.function();

    const int incVariable = relatedClass.getValue();
    std::cout<<"Incremented Variable : "<< incVariable << std::endl;

    
}