//Author: Burak Doğançay
#include "UndefinedBehaviour.h"


int main()
{
    std::unique_ptr<UndefinedBehaviour> undefBehaviourClass = std::make_unique<UndefinedBehaviour>();

    //undefBehaviourClass.get()->readingOrWritingnullPointer();
    //undefBehaviourClass.get()->unInitVariable();
    //undefBehaviourClass.get()->accessOutOfBoundsIndex();
    //undefBehaviourClass.get()->invalidPointerArithmetic();
   //undefBehaviourClass.get()->nonreturnTypeUB();
    undefBehaviourClass.get()->accessDanglingReference();
    //undefBehaviourClass.get()->intDivisionByZero();
    //undefBehaviourClass.get()->shiftingInvalidNumber();
    //undefBehaviourClass.get()->incorrectPairingMemAlloc();
    //undefBehaviourClass.get()->signedIntegerOverflow();
    //undefBehaviourClass.get()->incorrectPairingMemAlloc();
}