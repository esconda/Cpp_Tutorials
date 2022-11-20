//Author: Burak Doğançay
#include "Algorithm.h"
int main()
{
    std::unique_ptr<Algorithm> mAlgorithm = std::make_unique<Algorithm>();
    mAlgorithm.get()->vectorInitializations();
    mAlgorithm.get()->countingAlgortihms();
    mAlgorithm.get()->searchAlgorithms();
}
