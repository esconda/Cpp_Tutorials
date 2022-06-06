//Author: Burak Doğançay
#include "Alignment.h"

Alignment::Alignment()
{
}

void Alignment::alignmentControl(){
    //The alignas keyword can be used to force a variable, class data member, declaration or definition of a class, or
    //declaration or definition of an enum, to have a particular alignment, if supported. It comes in two forms:
    //alignas(x), where x is a constant expression, gives the entity the alignment x, if supported.
    //alignas(T), where T is a type, gives the entity an alignment equal to the alignment requirement of T, that is,
    //alignof(T), if supported.
    //If multiple alignas specifiers are applied to the same entity, the strictest one applies.
    //In this example, the buffer buf is guaranteed to be appropriately aligned to hold an int object, even though its
    //element type is unsigned char, which may have a weaker alignment requirement.
    alignas(int) unsigned char buf[sizeof(int)];
    new(buf) int(42);
    std::cout<<"****Alignas example****"<<std::endl;
    std::cout<<"Buffer is : "<<buf<<std::endl;
    std::cout<<"**********************************"<<std::endl;

    //alignas, when given an integer constant expression, must be given a valid alignment. Valid alignments are always
    //powers of two, and must be greater than zero. Compilers are required to support all valid alignments up to the
    //alignment of the type std::max_align_t. They may support larger alignments than this, but support for allocating
    //memory for such objects is limited. The upper limit on alignments is implementation dependent.
    //C++17 features direct support in operator new for allocating memory for over-aligned types.
}

void Alignment::checkAlignment(){
    //Check  alignment
    alignas(int) double intAlignedDoubleVar; // Align double to char
    alignas(char) long double charAlignedDoubleVar; //Align Long double to char

    std::cout<<"****Check Alignments****"<<std::endl;
    std::cout<<"Integer Alignment : "<<alignof(int)<<std::endl;
    std::cout<<"Char Alignment : "<<alignof(char)<<std::endl;
    std::cout<<"Double Alignment : "<<alignof(double)<<std::endl;
    std::cout<<"Float Alignment : "<<alignof(float)<<std::endl;
    std::cout<<"Float Alignment : "<<alignof(long double)<<std::endl;
    std::cout<<"Integer Alignment Double : "<<alignof(intAlignedDoubleVar)<<std::endl;
    std::cout<<"Char Alignment of Long Double : "<<alignof(charAlignedDoubleVar)<<std::endl;
    std::cout<<"**********************************"<<std::endl;
}
