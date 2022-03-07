#ifndef TYPEKEYWORD_H
#define TYPEKEYWORD_H

#include <iostream>
#include <functional>

//Enum and struct also keyword"
class TypeKeyword
{
public:
    TypeKeyword();
    TypeKeyword(int val);
    TypeKeyword(const TypeKeyword &ruleOfThree);            // II. COPY CONSTRUCTOR
    TypeKeyword &operator=(const TypeKeyword &ruleOfThree); // III. COPY ASSIGNMENT
    ~TypeKeyword();       
    void enumOperation();
    void enumClassOperation();
    void structOperation();
    void structOperation2();
    void unionOperation();

    //Enum type Keyword
    enum Direction{
        UP,
        LEFT,
        DOWN,
        RIGHT
    };

    //Enum type class Keyword: In C++11, enum may optionally be followed by class or struct to define a scoped enum. Furthermore, both scoped
//and unscoped enums can have their underlying type explicitly specified by : T following the enum name, where T
//refers to an integer type
    enum class Format : char {
        TEXT = 'B',
        TEXT1 = 'U',
        TEXT2 = 'R',
        TEXT3 = 'A',
        TEXT4 = 'K'
    };

    typedef struct somethingStruct
    {
        char variable1[6];
        int variable2;
        somethingStruct(){
            variable1[0] = 'B';
            variable2 = 25;
        }
        /* data */
    };

    struct SomethingStruct2{
        int variable;
        int variable2;
        SomethingStruct2(){
            variable = 50;
            variable2 = 100;
        }
    }somethingStruct2;

//
    union Sigval{
        int sival_int;
        void *sival_ptr;
    };
    
};
#endif