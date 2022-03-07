#include "friendcall.h"
#include "Type/typekeyword.h"
#include "Type/BasicTypeKeyword.h"
#include "Type/VariableDeclerationKeyword.h"
#include "LinkedList/List.h"

#include "Type/typekeyword.cpp"
#include "Type/BasicTypeKeyword.cpp"
#include "Type/VariableDeclerationKeyword.cpp"
#include "LinkedList/List.cpp"

int main()
{
    FriendCall friendcall;
    TypeKeyword typedefKeyword;
    BasicTypeKeyword basicTypeKeyword;
    VariableDeclerationKeyword variableDeclerationKeyword;
    List linkedList;

    int variable = 20;

    friendcall.friend_function();
    friendcall.write_private_variables();

    //Type keywords like class,enum,struct
    typedefKeyword.enumOperation();
    typedefKeyword.enumClassOperation();
    typedefKeyword.structOperation();
    typedefKeyword.structOperation2();
    typedefKeyword.unionOperation();

    //Basic typewords
    basicTypeKeyword.basicTypeKeywordProcess();

    //Decleration type keyword
    variableDeclerationKeyword.declerationTypeExample();
    variableDeclerationKeyword.constantTypeExample();
    variableDeclerationKeyword.volatileTypeExample(variable);
    variableDeclerationKeyword.signedTypeExample();

    //LinkedListExamples
    linkedList.insertAtEnd(20);
    linkedList.insertAtEnd(35);
    linkedList.insertAtEnd(45);
    linkedList.print();

}