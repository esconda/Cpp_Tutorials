#include "TypeTraits.h"
#include <iostream>

int main()
{
  TypeTraits *tCasting = new TypeTraits();

  tCasting->isContstant();
  tCasting->isSigned();
  tCasting->isUnsigned();
  tCasting->isVolatile();

}