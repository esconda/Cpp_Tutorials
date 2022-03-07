#ifndef VARIABLEDECLERATIONKEYWORD_H
#define VARIABLEDECLERATIONKEYWORD_H

#include <iostream>
#include <functional>
#include <vector>

//Enum and struct also keyword"
class VariableDeclerationKeyword
{
public:
    VariableDeclerationKeyword();
    VariableDeclerationKeyword(int val);
    VariableDeclerationKeyword(const VariableDeclerationKeyword &ruleOfThree);            // II. COPY CONSTRUCTOR
    VariableDeclerationKeyword &operator=(const VariableDeclerationKeyword &ruleOfThree); // III. COPY ASSIGNMENT
    ~VariableDeclerationKeyword();    

    //DECLERATION TYPE
    void declerationTypeExample();

    //CONST TYPE
    void constantTypeExample();

    //VOLATILE TYPE
    char memory_mapped_port;
    void volatileTypeExample(int x);

    //SIGNED TYPE
    void signedTypeExample();

private:
       struct S {
        void f();
        void g() const;
    };

   
};
#endif