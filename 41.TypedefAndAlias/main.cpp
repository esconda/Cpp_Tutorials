//Author : Burak Dogancay
#include "TypedefAndAlias.h"
#include <iostream>
#include <memory>

int main()
{
  std::unique_ptr<TypedefAndAlias> typeDef= std::make_unique<TypedefAndAlias>();

  //Call Typedefand Alias Functions
  typeDef.get()->basicTypeDef();
  typeDef.get()->declareMultipleTypes();
  typeDef.get()->aliasDeclWithUsing();
  
}