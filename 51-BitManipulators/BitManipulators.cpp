// Author: Burak Doğançay
#include "BitManipulators.h"

BitManipulators::BitManipulators()
{
}

void BitManipulators::generalBitManipulation(){
   /*  On modern computer architectures, the smallest addressable unit of memory is a byte. 
    Since all objects need to have unique memory addresses, this means objects must be at least one byte in size */
    char srcVariable {0x01};  //1 byte variable defined as hexadecimal value
    char orBitwiseVariable;
    char andBitwiseVariable;
    char xorBitwiseVariable;
    char leftShiftVariable;
    char rightShiftVariable;
    char notVariable;

    //Bitwise operations
    //What’s the use of “& 0xff” in programming
    orBitwiseVariable  = (srcVariable | 0x02) & 0xFF; // here is 0xff masks the variable so it leaves only the value in the last 8 bits.
    andBitwiseVariable = (srcVariable & 0x03) & 0xFF;
    xorBitwiseVariable = (srcVariable ^ 0x03) & 0xFF;
    leftShiftVariable = (srcVariable << 2) & 0xFF; // SHİFT 00000001 -> 0X00000100 
    rightShiftVariable = (leftShiftVariable >> 1) & 0XFF;
    notVariable = (~srcVariable) & 0xFF;

    //Output Bitwise 
    std::cout<<"****General Bit Manipulations****"<<std::endl;    
    std::cout<<"Nominal Variable : "<< std::bitset<8>(srcVariable)<<std::endl;
    std::cout<<"OR Bitwise Operation : "<< std::bitset<8>(orBitwiseVariable)<<std::endl;
    std::cout<<"AND Bitwise Operation : "<< std::bitset<8>(andBitwiseVariable)<<std::endl;
    std::cout<<"xOR Bitwise Operation : "<< std::bitset<8>(xorBitwiseVariable)<<std::endl;
    std::cout<<"Left Shift Bitwise Operation : "<< std::bitset<8>(leftShiftVariable)<<std::endl;
    std::cout<<"Right Shift Bitwise Operation : "<< std::bitset<8>(rightShiftVariable)<<std::endl;
    std::cout<<"Not Bitwise Operation : "<< std::bitset<8>(notVariable)<<std::endl;
    std::cout<<"**********************************"<<std::endl;
}

void BitManipulators::bitsetBitManipulation(){
    //Doing these things requires that we can manipulate objects at the bit level. Fortunately, C++ gives us tools to do precisely this. 
    //Modifying individual bits within an object is called bit manipulation.
    //Bitset std library is useful to control bits and able to do bitset opeartions 
    std::bitset<8> bitsetVariable{0b0000'0001};
    std::bitset<8> bitsetSet{0x00};
    std::bitset<8> bitsetFlip{0x00};

    bitsetSet = bitsetVariable.set(2); // set bit position to 2 0000 0101
    bitsetFlip = bitsetVariable.flip(0); //flip given position bit

    std::cout<<"****BitSet Manipulaitons****"<<std::endl;    
    std::cout<<"Biteset Set Operation : "<< bitsetSet<<std::endl;
    std::cout<<"Biteset Set Operation : "<< bitsetFlip<<std::endl;
    std::cout<<"**********************************"<<std::endl;

}

