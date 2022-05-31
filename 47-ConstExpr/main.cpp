//Author: Burak Doğançay
#include "ConstExpr.h"


int main()
{
    std::unique_ptr<ConstExpr> constExpr = std::make_unique<ConstExpr>();

    constExpr.get()->constExpVariable();
    constExpr.get()->staticIfStatement();
}