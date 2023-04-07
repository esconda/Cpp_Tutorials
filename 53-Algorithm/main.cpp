//Author: Burak Doğançay
#include "CountingAlgorithm.h"
#include "SearchAlgorithms.h"
#include "SetAndOperationalAlgorithms.h"
#include "ComparisonAlgorithm.h"
#include "ModifyingSequenceAlgorithm.h"
#include "SwapAndExchangeAlgorithms.h"
#include "SortingAlgorithms.h"
int main()
{
    std::unique_ptr<CountingAlgorithm> mCountingAlgorithm = std::make_unique<CountingAlgorithm>();
    std::unique_ptr<SearchAlgorithms> mSearchAlgorithm = std::make_unique<SearchAlgorithms>();
    std::unique_ptr<SetAndOperationalAlgorithms> mSetAndOpAlgorithm = std::make_unique<SetAndOperationalAlgorithms>();
    std::unique_ptr<ComparisonAlgorithm> mComparisonAlgorithms = std::make_unique<ComparisonAlgorithm>();
    std::unique_ptr<ModifyingSequenceAlgorithm> mModifyingAlgorithms = std::make_unique<ModifyingSequenceAlgorithm>();
    std::unique_ptr<SwapAndExchangeAlgorithms> mSwapAndExchangeAlgorithm = std::make_unique<SwapAndExchangeAlgorithms>();
    std::unique_ptr<SortingAlgorithms> mSortingAlgorithms = std::make_unique<SortingAlgorithms>();
    
    mCountingAlgorithm.get()->vectorInitializations();
    mCountingAlgorithm.get()->countingAlgortihms();
    mSearchAlgorithm.get()->searchAlgorithms();
    mSearchAlgorithm.get()->binarySearchAlgorithms();
    mSetAndOpAlgorithm.get()->setAlgorithm();
    mSetAndOpAlgorithm.get()->operationalAlgorithm();
    mComparisonAlgorithms.get()->comparisonAlgorithms();
    mModifyingAlgorithms.get()->copyFunctions();
    mModifyingAlgorithms.get()->fillFunctions();
    mModifyingAlgorithms.get()->generateFunctions();
    mModifyingAlgorithms.get()->moveFunctions();
    mModifyingAlgorithms.get()->removeFunctions();
    mModifyingAlgorithms.get()->replaceFunctions();

    mSwapAndExchangeAlgorithm.get()->swapAndExchangeFunctions();
    mSortingAlgorithms.get()->sortingFunction();
   
}
