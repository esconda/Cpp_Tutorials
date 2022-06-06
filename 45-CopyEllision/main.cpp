//Author: Burak Doğançay
#include "CopyEllision.h"


int main()
{
    std::unique_ptr<CopyEllision> copyEllisionClass = std::make_unique<CopyEllision>();

    //undefBehaviourClass.get()->readingOrWritingnullPointer();
    //undefBehaviourClass.get()->unInitVariable();
    //undefBehaviourClass.get()->accessOutOfBoundsIndex();
    undefBehaviourClass.get()->invalidPointerArithmetic();
    undefBehaviourClass.get()->nonreturnTypeUB();
    undefBehaviourClass.get()->accessDanglingReference();
    undefBehaviourClass.get()->intDivisionByZero();
    undefBehaviourClass.get()->shiftingInvalidNumber();
    undefBehaviourClass.get()->incorrectPairingMemAlloc();
    undefBehaviourClass.get()->signedIntegerOverflow();
    undefBehaviourClass.get()->incorrectPairingMemAlloc();
}