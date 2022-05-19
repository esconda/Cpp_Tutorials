//Author: Burak Doğançay
#include "Alignment.h"


int main()
{
    std::unique_ptr<Alignment> alignmentClass = std::make_unique<Alignment>();

    alignmentClass.get()->alignmentControl();
    alignmentClass.get()->checkAlignment();
}