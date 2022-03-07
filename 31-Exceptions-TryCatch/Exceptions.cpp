#include "Exceptions.h"

Exceptions::Exceptions()
{
}

void Exceptions::catching_Exception()
{
    std::string tString = {"String"};

    try
    {
        tString.at(10);
    }
    catch (const std::out_of_range &e)
    {
        // what() is inherited from std::exception and contains an explanatory message
        std::cout << e.what();
    }
}
void Exceptions::multipleCatch()
{
    std::string tString("string");

    try
    {
        tString.reserve(2); // reserve extra capacity, may throw std::length_error
        tString.at(10);     // access element, may throw std::out_of_range
    }
    catch (const std::length_error &e)
    {
        std::cout << e.what() << std::endl;
    }
    catch (const std::out_of_range &e)
    {
        std::cout << e.what() << std::endl;
    }
}

void Exceptions::generalExceptions()
{

    std::string tString("string");

    try
    {
        tString.reserve(2); // reserve extra capacity, may throw std::length_error
        tString.at(10);     // access element, may throw std::out_of_range
    }
    catch (const std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
}
