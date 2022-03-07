#include "TypeTraits.h"
#include <iostream>

int main()
{
  TypeTraits *typeTraits = new TypeTraits();

  typeTraits->isContstant();
  typeTraits->isSigned();
  typeTraits->isUnsigned();
  typeTraits->isVolatile();

  //Standard tyeptraits
  typeTraits->isPointer();

  //Type Relation
  typeTraits->is_same();

}