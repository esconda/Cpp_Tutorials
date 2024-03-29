#include "IncludeGuards.h"
#include "IncludeGuards.h"
#include "ConditionalLogic.h"
#include "UsefulMacros.h"
#include "Macros.h"


int main()
{
    //Check for complex implementation
    IncludeGuards includeGuardClass;
    ConditionalLogic condLogicClass;
    Macros macros;

    includeGuardClass.checkIncludeGuards();

    if (condLogicClass.printVariable(25))
        std::cout<<"Function is working correctly"<<std::endl;

    macros.macroFuncExample();
    macros.macroFuncSecondEx();
    macros.complexFunctionMacros();
    macros.variadicFunctionMacro();
    macros.preprocessorOperatorsFirstEx();
    macros.preprocessorOperatorSecondEX();
    macros.preprocessorOpVarDefine();
    macros.preprocessorErrorMessage();
    macros.variableMacro();
    
}