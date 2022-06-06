//Author : Burak Dogancay
#include "TypedefAndAlias.h"

TypedefAndAlias::TypedefAndAlias()
{
}

void TypedefAndAlias::basicTypeDef(){

    std::cout << "******TYPEDEF EXPLAINATION******" << std::endl;
    
    //BASIC TYPEDEF EXPLAINATION
    int var; // var has type of int
    typedef int t; //t is a alias for int
    t intVariable = 20;
    std::cout<< "First Simple Typedef Variable:"<<intVariable<<std::endl;

    //---------------------------------

    int vraArr[100]; // A has type "array of 100 ints"
    typedef int Arr[100];
    Arr intArrVar = {2,3,4,5,6,7,8};
    std::cout<<"Second Simple Typedef Variable:"<< intArrVar[0] <<std::endl;

    //TYP0EDEF STRUCT EXAMPLE
    typedef struct Struct{
        int a=20;
        int b=30;
    }intStruct;

    intStruct myStruct;
    std::cout<<"Struct Typedef Variable a:"<< myStruct.a <<std::endl;
    std::cout<<"Struct Typedef Variable b:"<< myStruct.b <<std::endl;


    std::cout << "***************************" << std::endl;
}

void TypedefAndAlias::complexTypeDef(){
//The rule that typedef declarations have the same syntax as ordinary variable and function declarations can be used
//to read and write more complex declarations.

//void (*func)(int); // func has type "pointer to function of int returning void"
//typedef void (*func)(int); // func is an alias for "pointer to function of int returning void"

//void (Foo::*pointerToFunc)(int); // pointerToFunc has type "pointer to member function of Foo taking int and returning void"
//typedef void (Foo::*pointerToFunc)(int); // pointerToFunc is an alias for "pointer to member function of Foo taking int and returning void"

//typedef void (Foo::pointerToFunc)(int); // pointerToFunc is a pointer to member function type
//pointerToFunc Foo::func(const char*); // func is a member function of Foo
//typedef int (&ra)[100]; // ra means "reference to array of 100 ints"
//ra g(); // g returns reference to array of 100 ints

}

void TypedefAndAlias::declareMultipleTypes(){
    int x , *y, (*p)(); // x has type int, y has type of int* and p has type int(*)()
    int a , *b, (*c)();

    x = 50;
    y = &x;
    std::cout << "****** MULTIPLE TYPEDEF EXPLAINATION******" << std::endl;
    std::cout <<"Variables are : "<< x<< *y <<std::endl;
    std::cout << "***************************" << std::endl;
}

void TypedefAndAlias::aliasDeclWithUsing(){
    using intVar = int; // int decleration
    using intVector = std::vector<int>; //
    using intArr = int[100];

    intVar var = 50;
    intVector varVector = {20,30,40,50};
    intArr varArr = {60,70,80};

    std::cout << "****** USING EXPLAINATION******" << std::endl;
    std::cout<<"Integer Variable : "<< var<< std::endl;
    std::cout<<"Integer Vector Variable : "<< varVector[0]<< std::endl;
    std::cout<<"Integer Array Variable : "<< varArr[2]<< std::endl;
    std::cout << "***************************" << std::endl;
}