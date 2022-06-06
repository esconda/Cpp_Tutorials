//Author : Burak Dogancay
#include "TypeDeduction.h"
#include <iostream>
#include <memory>

int main()
{
  std::unique_ptr<TypeDeduction> typeDeduct= std::make_unique<TypeDeduction>();

  //Call Typedefand Alias Functions
  typeDeduct.get()->autoTypeDeduction();
  typeDeduct.get()->dclTypeAuto();
  typeDeduct.get()->anotherAutoTypeDedeuction();
  typeDeduct.get()->templateTypeDeduction();

}