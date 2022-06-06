//Author: Burak Doğançay
#include "CopyEllision.h"

CopyEllision::CopyEllision()
{
}

void CopyEllision::quaranteedCpyEllision(){
    //Normally, elision is an optimization. While virtually every compiler support copy elision in the simplest of cases,
    //having elision still places a particular burden on users. Namely, the type who's copy/move is being elided must still
    //have the copy/move operation that was elided.
    //This might be useful in cases where a_mutex is a mutex that is privately held by some system, yet an external user
    //might want to have a scoped lock to it.
    std::lock_guard the_lock = getLock();

    //Since the result of get_lock is a prvalue expression being used to initialize an object of the same type, no copying
    //or moving will happen. That expression never creates a temporary; it is used to directly initialize the_lock. There is
    //no elision because there is no copy/move to be elided elide.

}

void CopyEllision::parameterEllision(std::string str){
    //When you pass an argument to a function, and the argument is a prvalue expression of the function's parameter
    //type, and this type is not a reference, then the prvalue's construction can be elided.
    std::cout<<"Parameter Ellision: "<<str<<std::endl;
}

std::string CopyEllision::returnValEllision(){
    //If you return a prvalue expression from a function, and the prvalue expression has the same type as the function's
    //return type, then the copy from the prvalue temporary can be elided:
    return std::string("foo");
}