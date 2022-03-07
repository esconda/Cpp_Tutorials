#include "StdVariantAny.h"
using VariantExample::StdVariant;
using AnyExample::StdAny;
using SetMultiSetExample::StdSetMultiset;
int main()
{
    //Check for complex implementation
    StdVariant stdVariant;
    StdAny stdAny;
    StdSetMultiset stdSetMultiset;

    stdVariant.variantBasicExample();
    stdAny.anyBasicExample();
    stdSetMultiset.setMultisetBasicExample();
    stdSetMultiset.setMultisetOp();

    
}