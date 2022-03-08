#include "BasicTypeKeyword.h"

BasicTypeKeyword::BasicTypeKeyword()
{
}

BasicTypeKeyword::BasicTypeKeyword(int val)
{
}

BasicTypeKeyword::~BasicTypeKeyword()
{
}

BasicTypeKeyword::BasicTypeKeyword(const BasicTypeKeyword &ruleOfThree)
{
}

BasicTypeKeyword &BasicTypeKeyword::operator=(const BasicTypeKeyword &ruleOfThree)
{
}

void BasicTypeKeyword::basicTypeKeywordProcess()
{
    BasicKeywordStr basicTypeKeyword;

    std::cout << "All variables : " << basicTypeKeyword.intValue << " , " << basicTypeKeyword.charZero << " , "
              << basicTypeKeyword.floatVal << " , " << basicTypeKeyword.doubleVal << " , "
              << basicTypeKeyword.longVal << " , " << basicTypeKeyword.shortVal << " , "
              << basicTypeKeyword.boolVal << " , " << *basicTypeKeyword.message << " , "
              << *basicTypeKeyword.fullhouse << " , " << *basicTypeKeyword.widesetcharacters << std::endl;
}
