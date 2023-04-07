#include "InlineVariables.h"
InlineVariables::InlineVariables()
{
}

void InlineVariables::inlineVarExample(){
    std::cout<<"Inline Variable Before Change : "<<inlinevar<<std::endl;
    int inlinevar = 20;
    std::cout<<"Inline Variable AfterChange : "<<inlinevar<<" : "<< InlineVariables::inlinevar<<" : "<<inlinevar2<<std::endl;
}

void InlineVariables::constantExpExample(){
    std::cout<<"Const Variable Before Change : "<<constExp<<std::endl;
    inlinevar = 20;
    std::cout<<"Const Variable After Change : "<<InlineVariables::constExp<<" : "<<constExp2<<std::endl;
}