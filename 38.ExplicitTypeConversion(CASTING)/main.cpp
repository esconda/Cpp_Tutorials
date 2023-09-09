#include "Casting.h"
#include <iostream>

int main()
{
/* reinterpret_cast is a low-level casting operator that should be used with extreme caution. 
  It is typically used for situations where you have a deep understanding of memory layout and need to perform unsafe conversions.

static_cast is a safe and well-defined casting operator suitable for most type conversions within C++'s type system.

dynamic_cast is used in the context of inheritance and polymorphism to safely cast pointers or references to base and derived classes, 
performing runtime type checks to ensure validity. */

  Casting tCasting;

  tCasting.constCastEx();
  tCasting.staticCastEx();
  //tCasting.dynamicCastEx();
  //tCasting.reinterpretCastEx();
  //tCasting.enumConversion();
  //tCasting.voidPointertoTpointer();

}