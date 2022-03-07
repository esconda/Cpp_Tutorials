#include "friendcall.h"
#include "friend.h"
FriendCall::FriendCall(){

}

FriendCall::~FriendCall(){

}

FriendCall::FriendCall(const FriendCall &ruleOfThree){

}

FriendCall &FriendCall::operator=(const FriendCall &ruleOfThree)
{
    
    
}

void FriendCall::write_private_variables(){
    FriendClass friendClass;
    friendClass.private_value_int1 = 10;
    friendClass.private_value_int2 = 20;
    friendClass.private_value_string1 = "String1 defined";
    friendClass.private_value_string2 = "String2 defined";

    std::cout<<" Variable 1 : " << friendClass.private_value_int1
             <<" Variable 2 : " << friendClass.private_value_int2
             <<" String Variable 1 :" << friendClass.private_value_string1
             <<" String Variable 2 : " << friendClass.private_value_string2<<std::endl;
}

void FriendCall::friend_function(){
    FriendClass friendclass(10);
    std::cout << "FriendClass private value : " << friendclass.private_value<< std::endl;

}

void FriendCall::non_friend_function(){
    //FriendClass friendclass(10);
    //std::cout << friendclass.private_value<< std::endl; // gives error it can not reach to porivate value
}

