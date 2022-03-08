#include "VariableDeclerationKeyword.h"

VariableDeclerationKeyword::VariableDeclerationKeyword(){
    
}

VariableDeclerationKeyword::VariableDeclerationKeyword(int val)
{

}

VariableDeclerationKeyword::~VariableDeclerationKeyword(){

}

VariableDeclerationKeyword::VariableDeclerationKeyword(const VariableDeclerationKeyword &ruleOfThree){

}

VariableDeclerationKeyword &VariableDeclerationKeyword::operator=(const VariableDeclerationKeyword &ruleOfThree)
{
    
    
}

void VariableDeclerationKeyword::declerationTypeExample(){
    //decltype vector "v" gets the type of the "x"
    int x = 60;
    std::vector<decltype(x)> v(100,x);
    std::cout<<"Variable Decleration Decltype Variable: "<<v.at(0)<<std::endl;
}

void VariableDeclerationKeyword::constantTypeExample(){
//A type specifier; when applied to a type, produces the const-qualified version of the type. See const keyword for
//details on the meaning of const.
    const int x = 123;
    //x = 456; // errorGoalKicker.com – C++ Notes for Professionals 112
    //int& r = x; // error
    const S s;
    std::cout<<"Variable Decleration Const Variable : "<<x<<std::endl;

//s.f(); // error

}
extern volatile char memory_mapped_port;
void VariableDeclerationKeyword::volatileTypeExample(int x){
//     A type qualifier; when applied to a type, produces the volatile-qualified version of the type. Volatile qualification
// plays the same role as const qualification in the type system, but volatile does not prevent objects from being
// modified; instead, it forces the compiler to treat all accesses to such objects as side effects.
// In the example below, if memory_mapped_port were not volatile, the compiler could optimize the function so that it
// performs only the final write, which would be incorrect if sizeof(int) is greater than 1. The volatile qualification
// forces it to treat all sizeof(int) writes as different side effects and hence perform all of them (in order)
    
    const char* p = reinterpret_cast<const char*>(&x);
    for (int i = 0; i < sizeof(int); i++) {
        memory_mapped_port = p[i];
        std::cout<<"mapped port : "<<std::hex<< static_cast<int>(memory_mapped_port)<<std::endl;
    }
}

void VariableDeclerationKeyword::signedTypeExample(){
  /*   
*When used alone, int is implied, so that signed, signed int, and int are the same type.
*When combined with char, yields the type signed char, which is a different type from char, even if char is
also signed. signed char has a range that includes at least -127 to +127, inclusive.
*When combined with short, long, or long long, it is redundant, since those types are already signed.
*signed cannot be combined with bool, wchar_t, char16_t, or char32_t */

    signed char charVal;
    charVal = 108;
    std::cout<<"Celcius temp : "<<std::hex<<static_cast<int>(charVal)<<std::endl;

}

