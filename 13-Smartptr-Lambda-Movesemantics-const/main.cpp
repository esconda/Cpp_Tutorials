#include "SmartPointers-Lambda.h"
#include "MoveSemantics-Struct-CopyCostruct.h"

void constexample(){
    ConstExamples consta;

    //// We can assign to the reference. Non-const version of GetScore is called
    consta.GetScore(true) = 'C';
    consta.GetScore(false) = 'D';

    const ConstExamples constb(consta);
    // We still can call GetScore method of const object,
    // because we have overloaded const version of GetScore
    std::cout << constb.GetScore(true) << constb.GetScore(false) << '\n';

    //CONST MEMBER FUNCTIONS
    int myInt = 80;
    consta.setIntegerVal(myInt);
    std::cout<<"Integer val is : "<< consta.getIntegerVal() <<" ";
}

void smartPointersEx(){
    SmartPointers smartpointerEx;
    smartpointerEx.conditionalOperator();
    smartpointerEx.lambdaexample();
    smartpointerEx.lambdaexample2(50);
    smartpointerEx.lambdaexample3();
}

void semanticsCpyCostr(){
    //Mem operations also called in this class check
    MoveSemantics moveSemantics;
    MoveSemantics moveSemantics2 (moveSemantics); // Copy constructor is called here we can also write it as  "MoveSemantics moveSemantics2  = moveSemantics" COPY CONSTRUCTOR EXAMPLE
    moveSemantics.moveSemanticsExample();
    moveSemantics.typedefStructcheck();
    moveSemantics.normalStructCheck();
    moveSemantics.moveSemanticsStruct();
    moveSemantics.callStaticVariables();

    std::cout<<"Copy constructor X and Y Values is not changed :  "<<moveSemantics.x<<" "<<moveSemantics.y<<std::endl;
    std::cout<<"Copy constructor X and Y Values Changed with :  "<<moveSemantics2.x<<" "<<moveSemantics2.y<<std::endl;
    std::cout<<"Copy constructor X and Y Values is not changed :  "<<moveSemantics.x<<" "<<moveSemantics.y<<std::endl;

}
int main()
{
    //constexample();
    //smartPointersEx();
    //semanticsCpyCostr();
}