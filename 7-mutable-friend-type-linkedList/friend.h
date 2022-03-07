#ifndef FRIEND_H
#define FRIEND_H

#include <iostream>
#include <functional>
#include "friendcall.h"
//Author : Burak Dogancay
class FriendClass
{
public:
    FriendClass();
    FriendClass(int val);
    FriendClass(const FriendClass &ruleOfThree);            // II. COPY CONSTRUCTOR
    FriendClass &operator=(const FriendClass &ruleOfThree); // III. COPY ASSIGNMENT
    ~FriendClass();       
                        
private:
//Friend Function
friend void  FriendCall::friend_function(); //friend function definition, therefore this function can access to the private value of this class
friend FriendCall; // friend class , this class can acess to the private values of this class
int private_value;

int private_value_int1;
int private_value_int2;
std::string private_value_string1;
std::string private_value_string2;

};
#endif