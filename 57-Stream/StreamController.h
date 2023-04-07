 // Author: Burak Doğançay
#ifndef STREAMCONTROLLER_H
#define STREAMCONTROLLER_H
#include <fstream> // fstream is both writing and reading from file
#include <iostream>
/*
1)ifstream is input file stream which allows you to read the contents of a file.
2)ofstream is output file stream which allows you to write contents to a file.
3)fstream allows both reading from and writing to files by default. However, you can have an
  fstream behave like an ifstream or ofstream by passing in the ios::open_mode flag.

The open mode flags are:

Flag	    Description
ios::app	All write operations must occur at the end of the file
ios::binary	Open in binary mode
ios::in	    Open for reading
ios::out	Open for writing
ios::trunc	Empty the contents of the file after opening
ios::ate	Go to the end of the file after opening
  */
class StreamController
{
public:
    StreamController();
    StreamController(int val) = delete;
    StreamController(StreamController &&ruleOfFive) noexcept = delete;         // III. MOVE CONSTRUCTOR
    StreamController(const StreamController &ruleOfThree) = delete;            // II. COPY CONSTRUCTOR
    StreamController &operator=(const StreamController &ruleOfThree) = delete; // III. COPY ASSIGNMENT
    ~StreamController() = default;

    void osStreamExample();
    void ifStreamExample();
    void isStreamExample();

};

#endif 