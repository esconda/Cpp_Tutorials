#include "ConstExamples.h"
ConstExamples::ConstExamples() 
{

}
//In code above, we call const version of GetBar from the non-const GetBar by casting this to const type:
//const_cast<const Foo*>(this). Since we call const method from non-const, the object itself is non-const, and
//casting away the const is allowed
char &ConstExamples::GetScore(bool midterm)
{
    return const_cast<char &>(const_cast<const ConstExamples *>(this)->GetScore(midterm));
}

const char &ConstExamples::GetScore(bool midterm) const
{
    if (midterm)
    {
        return midtermScore;
    }
    else
    {
        return finalScore;
    }
}

int ConstExamples::getIntegerVal() const{
    return myInt;
}

void ConstExamples::setIntegerVal(int &MyInt){
    myInt = MyInt;
}

ConstExamples::~ConstExamples(){
    
}