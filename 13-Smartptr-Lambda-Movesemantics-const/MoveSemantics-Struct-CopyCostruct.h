#include <iostream>
#include <memory>
#include <cstring>
#include "ConstExamples.h"
#include <functional>
class MoveSemantics
{
public:
    //Move semantics means the class will transfer ownership of the object rather than making copy
    MoveSemantics();
    MoveSemantics(const MoveSemantics& movesemantics); //A user-defined copy constructor is generally needed when an object owns pointers or non-shareable references, 
                                                       //such as to a file, in which case a destructor and an assignment operator should also be written (see Rule of three).
    ~MoveSemantics();
    void moveSemanticsExample();
    void moveSemanticsStruct();
    void typedefStructcheck();
    void normalStructCheck();
    void callStruct(void *fun);
    void callStaticVariables();

//Used for copy constructor
    int x;
    int y;

private:
    //struct is normmaly public but class is normally private
    typedef struct typedefstruct
    {
        int xVar;
        int yVar;
        int zVar;
        typedefstruct()
        {
            xVar = 50;
            yVar = 100;
            zVar = 200;
        }
    };

    struct normalstruct
    {
        int xVar;
        int yVar;

        normalstruct()
        {
            xVar = 100;
            yVar = 450;
        }
    };

    ConstExamples *mConstClass;
    ConstExamples *mConstClasstrans;
    typedefstruct *mTypedefStruct;
};