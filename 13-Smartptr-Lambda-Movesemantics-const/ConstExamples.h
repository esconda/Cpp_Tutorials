#ifndef CONSTEXAMPLES_H
#define CONSTEXAMPLES_H
#include <iostream>
//Author : Burak Dogancay
class ConstExamples{
    public :
        ConstExamples();
        ~ConstExamples();
        char& GetScore(bool midterm);
        const char& GetScore(bool midterm) const;

        //Member functions of a class can be declared const, which tells the compiler and future readers that this function
        //will not modify the object:
        int getIntegerVal() const;//for reading variable
        void setIntegerVal(int &MyInt);//set variable

        //Static variables
        static int staticIntVar;
        static char staticCharVar;

    private:
        char midtermScore;
        char finalScore;
        int myInt;

};

#endif