//Author: Burak Doğançay
#include "CallableObjects.h"


int main()
{
    std::unique_ptr<CallableObjects> callableObjects = std::make_unique<CallableObjects>();
    callableObjects.get()->applyFunctions();
}

