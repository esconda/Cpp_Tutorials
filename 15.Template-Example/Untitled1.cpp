#include "Untitled1.h"
template<typename T>
myClass<T>::myClass()//: mvalue(20),mprivval(10)
{
    
}

template<typename T>
 myClass<T>::myClass(T value){
    mvalue = value;
    mprivval = value*4;

    doubleval = static_cast<double>(value);
    doubleval2 = static_cast<double>(value*6);
    doubleval3 = static_cast<double>(value*40);
}

template<typename T>
void myClass<T>::somemaths(){
    int sum = mvalue+mprivval;
    int mult= mvalue*mprivval;
    std::cout<<"Sum and Multiply : "<<sum<<",,"<<mult<<std::endl;
}


template<typename T>
 T myClass<T>::intFunction(){
     int t_value= 20;
     std::cout<<"Function called with value : "<<t_value<<std::endl;
     return t_value; 
 }

 template<typename T>
 void myClass<T>::writeString(T string){
     std::cout<<"Type id name : "<<typeid(string).name()<<std::endl;
     if(typeid(string).name()){
         std::cout<<"String is : "<<string<<std::endl;
     }
 }

int main(){
    //myClass<double> myownclass(20);
    
    //std::cout<<"My value : "<<myownclass.mvalue<< myownclass.mprivval<< myownclass.doubleval<< myownclass.doubleval2<<myownclass.doubleval3<< std::endl;
    //myownclass.intFunction();
    //myownclass.somemaths();

    myClassConst classconst;
    classconst.writeString("String func is called");


    system("pause");
}

