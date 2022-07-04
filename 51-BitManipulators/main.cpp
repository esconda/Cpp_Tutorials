//Author: Burak Doğançay
#include "BitManipulators.h"


int main()
{
    std::unique_ptr<BitManipulators> bitManipulation = std::make_unique<BitManipulators>();

    bitManipulation.get()->generalBitManipulation();
    bitManipulation.get()->bitsetBitManipulation();
    
}

