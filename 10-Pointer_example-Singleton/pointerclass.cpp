#include "pointerclass.h"

pointerclass::pointerclass() : mpointerval(20){
    

}

pointerclass::~pointerclass(){

    
}

pointerclass *pointerclass::instance(){
    static pointerclass tpointerclass;
    return &tpointerclass;
}

void pointerclass::pointercheckbyadress(const pointerclass &pclass){
    std::cout << pclass.mpointerval << std::endl; 
}