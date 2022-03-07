#include "AccessSpecifier.h""

AccessSpecifier::AccessSpecifier()
{
}

AccessSpecifier::AccessSpecifier(int val)
{
}

AccessSpecifier::~AccessSpecifier()
{
}

AccessSpecifier::AccessSpecifier(const AccessSpecifier &ruleOfThree)
{
}

AccessSpecifier &AccessSpecifier::operator=(const AccessSpecifier &ruleOfThree)
{
}
void AccessSpecifier::accessPrivateVal(){
    std::cout<<"Private Valuse : "<< a <<" "<< b<<std::endl;
}
void AccessSpecifier::accessProtectedVal(){
    std::cout<<"Protected Value : "<< d <<" "<< e <<std::endl; 
}

