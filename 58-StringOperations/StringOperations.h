 // Author: Burak Doğançay
#ifndef STRINGOPERATIONS_H
#define STRINGOPERATIONS_H // fstream is both writing and reading from file
#include <iostream>
#include <vector>
#include <string.h>

class StringOperations
{
public:
    StringOperations();
    StringOperations(int val) = delete;
    StringOperations(StringOperations &&ruleOfFive) noexcept = delete;         // III. MOVE CONSTRUCTOR
    StringOperations(const StringOperations &ruleOfThree) = delete;            // II. COPY CONSTRUCTOR
    StringOperations &operator=(const StringOperations &ruleOfThree) = delete; // III. COPY ASSIGNMENT
    ~StringOperations() = default;

    void basicCharPointerStrEx();
    void stdStrandCharOpEx();

    //####COPYING####
    void memcpyFunc();  //Copy Block of memory 
    void memmoveFunc(); //Move Block of Memory
    void strcpyFunc();  //Copy string
    void strncpyFunc(); //Copy characters from string

    //####CONCATENATION####
    void strcatFunc();  //Concanate strings
    void strncatFunc(); //Append characters from string

    //####COMPARISON####
    void memcmpFunc();   //Compare two block of memory
    void strcmpFunc();   //Compare two strings
    void strcollFunc();  //Compare two string using locale
    void strncmpFunc();  //Compare characters of two strings
    void strxfrmFunc();  //Transform string using locale

    //####SEARCHING####
    void memchrFunc();   //Locate character in block of memory
    void strchrFunc();   //Locate first occurence of character in string
    void strcspnFunc();  //Get span untill character in string
    void strpbrkFunc();  //Locate characters in string
    void strrchrFunc();  //Locate Last occurence of character in string
    void strspnFunc();   //Get span of character set in string
    void strstrFunc();   //Locate substring
    void strtokFunc();   //Split string into tokens

    //####OTHER####
    void memsetFunc();   //Fill block of memeory
    void strerrorFunc(); //Get pointer to error message string
    void strlenFunc();   //Get string length


    typedef struct mystruct{
        int a = 5;
        int b = 8;
    }Mystruct;

    

};

#endif 