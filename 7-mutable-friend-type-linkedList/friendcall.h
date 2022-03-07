#ifndef FRIENDCALL_H
#define FRIENDCALL_H

#include <iostream>
#include <functional>

class FriendCall
{
public:
    FriendCall();
    FriendCall(const FriendCall &ruleOfThree);            // II. COPY CONSTRUCTOR
    FriendCall &operator=(const FriendCall &ruleOfThree); // III. COPY ASSIGNMENT
    ~FriendCall(); 

    void friend_function();   
    void write_private_variables();
    void non_friend_function();
                        

};
#endif