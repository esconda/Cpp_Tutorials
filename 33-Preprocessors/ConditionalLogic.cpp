#include "ConditionalLogic.h"

ConditionalLogic::ConditionalLogic()
{
}

bool ConditionalLogic::printVariable(int var)
{
    if (var)
    {
        std::cout << "Integer variable value : " << var << std::endl;
        return true;
    }
    else
    {
        return false;
    }
}

bool ConditionalLogic::removeFileDirectly(const std::string &path)
{
    return remove(path.c_str());
}