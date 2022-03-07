#include "main.h"

int Mymain::staticdefone;
Mymain::Mymain() {
    
}

Mymain::~Mymain(){

}

int main(){
    Mymain main;
    Mymain::staticdefone = 30;
    std::cout<<"Class working well";
    std::cout<<"static defone : "<<Mymain::staticdefone<<std::endl;
    
    for(int i=0; i<10; i++){
        std::cout<<"Rakamlara 10 dahil değildir"<<i<<std::endl;
    }

    return 1;
}