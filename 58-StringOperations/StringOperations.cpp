// Author: Burak Doğançay
#include "StringOperations.h"
StringOperations::StringOperations()
{
}

void StringOperations::basicCharPointerStrEx(){
   char *tCharVar = "Here is my string";
   
   int tVariableLength = strlen(tCharVar);// get length of the string
   
   char *tPartofVar1 = tCharVar+8;  //get adress of the pointer
   char *tPartofVar2 = &tCharVar[8]; // same as above
   char *tWholeString = tCharVar;
   
   std::cout<<"*******BASIC CHAR POINTER EXAMPLE*******"<<std::endl;
   std::cout<<"Assigned whole string is :"<<tWholeString<<std::endl; 
   std::cout<<"Part of variable is: "<<tPartofVar1<<"  or  "<<tPartofVar2<<std::endl;// way of printing string
   std::cout<<"########################################"<<std::endl<<std::endl;

   //Initialize char variables
   char tCharVar2[5] = {'A','B','C','D'}; //initialize char pointer as array list
   char *tCharVar2Ptr = tCharVar2; //assign char array to char pointer and pass initial adress as &tCharVar2[0]
   char *tCharVar3Ptr = new char[4]{'A','B','C','D'};//Initializing and Dynmaic allocation with C++
   char *tCharVar4Ptr = static_cast<char*>(calloc(4,sizeof(char)));//Initializing with value of zero using calloc and Dynmaic allocation with C
   char *tCharVar5Ptr = static_cast<char*>(malloc(4*sizeof(char)));//Initializing, malloc will be uninitialized so reading it would be undefined behavior and Dynmaic allocation with C
   char *tCharVar6Ptr = new char[strlen(tCharVar3Ptr)+1];// +1 to accommodate for the null terminator
   char *tCharVar7Ptr = new char[sizeof(tCharVar3Ptr)];//Initializing and Dynmaic allocation with C++
   char tCharVar3[5];
    
   //Initializing with strcpy
   strcpy(tCharVar4Ptr,tCharVar3Ptr);
   strcpy_s(tCharVar5Ptr,strlen(tCharVar4Ptr) + 1,tCharVar4Ptr);// +1 to accommodate for the null terminator
   memcpy(tCharVar6Ptr, tCharVar5Ptr, strlen(tCharVar5Ptr)+1);// +1 to accommodate for the null terminator
   memcpy(tCharVar3,tCharVar2+2,sizeof(tCharVar3)-2);// Copy C,D to tCharVar3 from A,B,C,D , tCharVar2+2 pass to the memory location of C
   std::copy(tCharVar3Ptr,tCharVar3Ptr+2,tCharVar7Ptr);//Copy A,B to tCharVar7Ptr from A,B,C,D tCharVar3Ptr+2 means that you copy first two character i char pointer

   std::cout<<"*******INITIALIZING CHAR POINTERS*******"<<std::endl;
   std::cout<<"tCharVar2 string is :"<<tCharVar2<<std::endl; 
   std::cout<<"tCharVar2Ptr string is : "<<tCharVar2Ptr<<std::endl; 
   std::cout<<"tCharVar3Ptr string is : "<<tCharVar3Ptr<<std::endl; 
   std::cout<<"tCharVar4Ptr string is : "<<tCharVar4Ptr<<std::endl; 
   std::cout<<"tCharVar5Ptr string is : "<<tCharVar5Ptr<<std::endl; 
   std::cout<<"tCharVar6Ptr string is : "<<tCharVar6Ptr<<std::endl; 
   std::cout<<"tCharVar3 string is : "<<tCharVar3<<std::endl; 
   std::cout<<"tCharVar7Ptr string is :"<<tCharVar7Ptr<<std::endl;
   std::cout<<"########################################"<<std::endl<<std::endl;

   Mystruct myStructVar;
   std::cout<<myStructVar.a<<myStructVar.b<<std::endl;
}


