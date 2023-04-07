//TEHESE ARE ALL MACROS
#ifndef MAIN_H
#define MAIN_H

//Macro Definitions
#define WIDTH 1920

#ifndef HEIGHT
#define HEIGHT 1080
#endif

/* 
#ifdef HEIGHT
#define DEFINED 1
#endif */


#if DEFINED
#define RECT 50
#endif

#define printString(a) std::cout<<a<<std::endl

//Author : Burak Dogancay
#include <iostream>

class Example{
    
    public:
        Example();
        ~Example();

        bool something;
        double doubleval;
        int integerval;

        int getVariable() const;
        void setVariable( int *pvariable);

    private:
        int *mVariable;

};
#endif