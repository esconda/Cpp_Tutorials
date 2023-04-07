// Author: Burak Doğançay
#include "StreamController.h"
StreamController::StreamController()
{
}

void StreamController::ifStreamExample()
{
    //READING FROM FILE EXAMPLE
    char myData1[50];
    char myData2[255];
    char myData3;
    std::ifstream ifStream;
    ifStream.open("57-Stream/Data.txt", std::ios::in | std::ios::binary); // open data in binary mode

    // Read from file
    if (ifStream.is_open())
    {
        ifStream >> myData1;
        std::cout << "IfStream first data is : " << myData1 << std::endl;
    }
    else
    {
        std::cout << "Error opening file" << std::endl;
    }
    
    // Clear and get back to beginning of frame
    ifStream.clear();
    ifStream.seekg(0);//Sets the position of the next character to be extracted from the input stream.

    // Another methode
    if (ifStream.is_open())
    {
        while(ifStream.good()){
            ifStream.getline(myData2,255);
            std::cout << "IfStream second data is : " << myData2 << std::endl;
        }
    }
    else
    {
        std::cout << "Error opening file" << std::endl;
    }

    ifStream.clear();
    ifStream.seekg(0);

    // Another methode
    if (ifStream.is_open())
    {
        while(ifStream.good()){
            myData3 = ifStream.get();
            std::cout << "IfStream third data is : " << myData3 << std::endl;
        }
    }
    else
    {
        std::cout << "Error opening file" << std::endl;
    }

    ifStream.close();
}

void StreamController::osStreamExample()
{
}

void StreamController::isStreamExample()
{
}
