#include <iostream>
#include <vector>
#include <cstring>
#include <cstddef>
#include <utility>

//Rule of three : destructor, copy constructor, copy assignment
class RuleOfThree
{

public:
    RuleOfThree();
    RuleOfThree (const char* s);
    ~RuleOfThree(); // I DESTRUCTOR
    RuleOfThree(const RuleOfThree& ruleOfThree);// II. COPY CONSTRUCTOR
    RuleOfThree& operator=(const RuleOfThree& ruleOfThree);// III. COPY ASSIGNMENT
    

private:
char *cstring;
RuleOfThree(const char *s, std::size_t n);

public:
operator const char *() const{return cstring;}
};


//Rule of Five: destructor , copy constructor, move constructor, copy assignment operator, move assignment
class RuleOfFive
{
public:

    RuleOfFive();
    RuleOfFive (const char* string);
    ~RuleOfFive();// I DESTRUCTOR
    RuleOfFive(const RuleOfFive& ruleOfFive);// II. COPY CONSTRUCTOR
    RuleOfFive(RuleOfFive&& ruleOfFive) noexcept;//III. MOVE CONSTRUCTOR
    RuleOfFive& operator=(const RuleOfFive& ruleOfFive);// IV COPY ASSIGNMENT
    RuleOfFive& operator=(RuleOfFive&& ruleOfFive) noexcept; // V. MOVE ASSIGNMENT


private:
    char *mstring;
};