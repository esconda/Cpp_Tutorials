// Author: Burak Doğançay
#include "StreamController.h"
StreamController::StreamController()
{
}

void StreamController::ifStreamExample()
{
    // READING FROM FILE EXAMPLE
    char myDatafirstLine[255];
    char myDataSecondLine[255];
    char myData2[255];
    char myData3;
    std::ifstream ifStream;
    ifStream.open("57-Stream/Data.txt", std::ios::in | std::ios::binary); // open data in binary mode

    // Read from file
    if (ifStream.is_open())
    {
        ifStream >> myDatafirstLine >> myDataSecondLine;
        std::cout << "IfStream first data is : " << myDatafirstLine << " " << myDataSecondLine << std::endl;
    }
    else
    {
        std::cout << "Error opening file" << std::endl;
    }

    // Clear and get back to beginning of frame
    ifStream.clear();
    ifStream.seekg(0); // Sets the position of the next character to be extracted from the input stream.

    // Another methode
    if (ifStream.is_open())
    {
        while (ifStream.good())
        {
            ifStream.getline(myData2, 255);
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
        while (ifStream.good())
        {
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

    // We can use different variable types to serialize them with ostream and ofstream
    // Note that the << operator automatically converts the values into their string representations and inserts them into the stream.
    // The output file will contain:
    struct Person
    {
        const char *name = "Burak";
        const char *surname = "Dogancay";
        const int age = 25;
        const char *city = "Istanbul";
        const char *country = "Turkey";
        const int postCode = 34678;
    } person;

    std::ifstream ofStream;

    ofStream.open("57-Stream/DataOstream.txt", std::ios::out | std::ios::binary); // open data in binary mode

    if (!ofStream.is_open())
    {
        std::cerr << "Error: failed to open input file.\n";
        return;
    }

    std::ostream out(ofStream.rdbuf());
    out.clear();
    out << "Name : " << person.name << std::endl
        << "Surname : " << person.surname << std::endl
        << "Age : " << person.age << std::endl
        << "City : " << person.city << std::endl
        << "Country : " << person.country << std::endl
        << "PostCode : " << person.postCode << std::endl;

    if (out.eofbit)
    {
        std::cerr << "The file is created correctly";
    }

    ofStream.close();
}

void StreamController::isStreamExample()
{
   std::vector<std::string> myStringVector;  
   std::string myString;

   std::ifstream ifStream;
   ifStream.open("57-Stream/Data.txt", std::ios::in | std::ios::binary); // open data in binary mode

    
    if(ifStream.is_open()) {
        std::istream &isStream = ifStream;
        
        isStream.clear();
        isStream.seekg(0);
        //Get each word from file 
        while(isStream >> myString ){
            std::cout<<"The string is :"<<myString<<std::endl;
            myStringVector.push_back(myString);
        }
        
        //Clear file and set position the initial point
        isStream.clear();
        isStream.seekg(0);

        //Clear vector and release memory
        myStringVector.clear();
        myStringVector.shrink_to_fit();

        //Get whole line of the file
        while(std::getline(isStream,myString)){
            std::cout<<"Vector capacity is:"<<myStringVector.capacity()<<std::endl;
            std::cout<<"The string is : "<<myString<<std::endl;
            myStringVector.push_back(myString);
        }

        for(std::string &string : myStringVector){
            std::cout<<"Vector string : "<<string<<std::endl;
        }
   }
   //First Methode

}
