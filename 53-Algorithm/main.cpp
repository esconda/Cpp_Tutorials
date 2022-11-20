//Author: Burak Doğançay
#include "CountingAlgorithm.h"
#include "SearchAlgorithms.h"
int main()
{
    std::unique_ptr<CountingAlgorithm> mCountingAlgorithm = std::make_unique<CountingAlgorithm>();
    std::unique_ptr<SearchAlgorithms> mSearchAlgorithm = std::make_unique<SearchAlgorithms>();
    mCountingAlgorithm.get()->vectorInitializations();
    mCountingAlgorithm.get()->countingAlgortihms();
    mSearchAlgorithm.get()->searchAlgorithms();
}
