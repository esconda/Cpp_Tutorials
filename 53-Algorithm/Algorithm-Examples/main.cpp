//Author: Burak Doğançay
#include "ArrayExamples.h"

int main()
{
    std::unique_ptr<ArrayExamples> mArrayExample = std::make_unique<ArrayExamples>();
    
    //ArrayExample
    mArrayExample.get()->removeDuplicatesFromSortedArray();
    mArrayExample.get()->rotateArray();
    mArrayExample.get()->firstNonRepeatedCharacterIndex();
    mArrayExample.get()->containsDuplicate();
    mArrayExample.get()->singleNumber();
    mArrayExample.get()->intersectionOfTwoArrays();
    mArrayExample.get()->findSecondLargestElementInArray();
    
}
