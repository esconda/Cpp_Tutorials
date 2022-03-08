#include "MoveSemantics-Struct-CopyCostruct.h"

int ConstExamples::staticIntVar = 50;
char ConstExamples::staticCharVar = 'A';

MoveSemantics::MoveSemantics() : mConstClass(nullptr),
                                 mConstClasstrans(nullptr),
                                 x(30),
                                 y(40)
{

}

//COPY CONSTRUCTOR EXAMPLE
MoveSemantics::MoveSemantics(const MoveSemantics& movesemantics){
    std::cout<<"Copy constructor called X and y value is : "<<movesemantics.x<<" "<<movesemantics.y<<std::endl;
    x = 50;
    y = 90;
}



void MoveSemantics::moveSemanticsExample()
{

    mConstClass = new ConstExamples;
    mConstClasstrans = mConstClass; // MOVESEMANTICS it transfers ownership rather  than making copy // different from copy constructor
    int intVal = 100;
    mConstClass->setIntegerVal(intVal);
    std::cout << "Get Integer Value : " << mConstClass->getIntegerVal() << std::endl;
}

void MoveSemantics::typedefStructcheck(){
    typedefstruct typedefStruct;
    std::cout<<"Size of Struct is : "<<sizeof(typedefStruct)<<std::endl;
    std::cout<<"Multiply of the two variable TypedefStruct : "<<typedefStruct.xVar*typedefStruct.yVar<<std::endl;
}

void MoveSemantics::normalStructCheck(){
    struct normalstruct normalStruct;
    std::cout<<"Size of Struct is : "<<sizeof(normalStruct)<<std::endl;
    std::cout<<"Multiply of the variables NormalStruct : "<<normalStruct.xVar*normalStruct.yVar<<std::endl;
}

void MoveSemantics::moveSemanticsStruct(){
    typedefstruct typedefStruct;
    struct normalstruct normalStruct;
    mTypedefStruct = &typedefStruct;

    std::memcpy(&normalStruct,mTypedefStruct,sizeof(normalStruct));
    std::cout<<"Multiply of the variables TypedefStruct of NormaLStruct : "<<normalStruct.xVar*normalStruct.yVar<<std::endl;

    callStruct(&typedefStruct);
}

void MoveSemantics::callStruct(void* fun){
    struct normalstruct normalStruct;
    std::memcpy(&normalStruct,fun,sizeof(normalStruct));
    std::cout<<"Multiply of the variables FunctionPointer TypedefStruct of NormaLStruct : "<<normalStruct.xVar*normalStruct.yVar*20<<std::endl;
}

void MoveSemantics::callStaticVariables(){
    std::cout<<"Static Integer Variable : "<<ConstExamples::staticIntVar<<std::endl;
    std::cout<<"Static Char Variable : "<<ConstExamples::staticCharVar<<std::endl;
}
MoveSemantics::~MoveSemantics()
{

}