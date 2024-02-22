 // Author: Burak Doğançay
#ifndef CSTDIOOPERATIONS_H
#define CSTDIOOPERATIONS_H // fstream is both writing and reading from file
#include <cstdio>
#include <cstring>
#include <iostream>
class CStdioOperations
{
public:
    CStdioOperations();
    CStdioOperations(int val) = delete;
    CStdioOperations(CStdioOperations &&ruleOfFive) noexcept = delete;         // III. MOVE CONSTRUCTOR
    CStdioOperations(const CStdioOperations &ruleOfThree) = delete;            // II. COPY CONSTRUCTOR
    CStdioOperations &operator=(const CStdioOperations &ruleOfThree) = delete; // III. COPY ASSIGNMENT
    ~CStdioOperations() = default;

    //###########OPERATION ON FILES################
    void removeFunc(std::string fileName);  //Remove File
    void renameFunc(std::string currentPath, std::string fileName); //Rename File
    void tmpFileFunc(); //Open a temporary file
    
    //###########FILE ACCESS################
    void fcloseFunc(std::string fileName);  //Close file
    void fflushFunc(std::string fileName);  //Flush stream
    void fopenFunc(std::string fileName);   //Open file
    void freopenFunc(std::string fileName); //Reuses stream to either open the file specified by filename or to change its access mode.
    
    //###########FORMATTED INPUT/OUTPUT################
    void fprintfFunc(std::string fileName);  //Write formatted data to stream
    void fscanfFunc(std::string fileName);   //Read formatted data from stream
    void snprintfFunc(std::string fileName); //Write formatted output to sized buffer
    void sprintfFunc(std::string fileName);  //Write formatted data to string
    void sscanfFunc(std::string fileName);   //Read formatted data from string
    void vfprintfFunc(std::string fileName)  //Write formatted data from variable argument list to stdout

    //###########CHARACTER INPUT/OUTPUT:################
    void fgetcFunc(std::string fileName);   //Returns the character currently pointed by the internal file position indicator of the specified stream
    void fgetsFunc(std::string fileName);   //Get string from stream
    void fputcFunc(std::string fileName);   //Write character to stream
    void fputsFunc(std::string fileName);   //Write string to stream
    void getcFunc(std::string fileName);    //Get character from stream
    void getcharFunc(std::string fileName); //Get character form stdin
    void getsFunc(std::string fileName);    //Get string from stdin
    void putcFunc(std::string fileName);    //Write character to stream
    void putcharFunc(std::string fileName); //Write character to stdout
    void putsFunc(std::string fileName);    //Write string to stdout
    void ungetcFunc(std::string fileName);  //Unget character from stream

    //###########DIRECT INPUT/OUTPUT:################
    void freadFunc(std::string fileName);   //Read block of data from stream
    void fwriteFunc(std::string fileName);  //Write block of data to stream

    //###########FILE POSITIONING:################
    void fgetposFunc(std::string fileName); //Retrieves the current position in the stream using with fgetc
    void fseekFunc(std::string fileName);   //Reposition stream position indicator
    void fsetposFunc(std::string fileName); //Set position indicator of stream
    void ftellFunc(std::stirng fileName);   //Get current position in stream
    void rewindFunc(std::String fileName);  //Set position of stream to the beginning

    //###########ERROR HANDLING:################
    void clearerrFunc(std::string fileName);  //Clear error indicators
    void feofFunc(std::string fileName);      //Check end-of-file indicator
    void ferrorFunc(std::string fileName);    //Check error indicator
    void perrorFunc(std::string fileName);    //Print error message 


};

#endif 