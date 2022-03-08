#include "VectorClassEx.h"

VectorClassEx::VectorClassEx() : 
intDef(0),
stringDef("0")
{
}

int VectorClassEx::getIntDef() const {
    return intDef;
}

void VectorClassEx::setIntDef(const int pIntDef) {
    intDef = pIntDef;
}

std::string VectorClassEx::getStringDef() const{
    return stringDef;
}

void VectorClassEx::setStringDef(const std::string pStringDef){
    stringDef = pStringDef;
}