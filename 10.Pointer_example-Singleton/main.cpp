#include "pointerclass.h"

int main(){

    std::cout<<"Workşing well"<<std::endl;

   pointerclass *tpointerclass = pointerclass::instance(); //SINGLETON APROACH
   tpointerclass->pointercheckbyadress(*tpointerclass); //PASS CLASS POINTER TO THE FUNCTION WITH PASS BY POINTER
    return 0;
}