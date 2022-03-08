#include "TypeInference.h"
#include <iostream>
#include <memory>

int main()
{
  std::unique_ptr<TypeInference> typeInference= std::make_unique<TypeInference>();

  //Call Auto Datatype
  typeInference.get()->autoDataType();
}