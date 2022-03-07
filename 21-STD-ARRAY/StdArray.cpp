#include "StdArray.h"

StdArray::StdArray()
{
}

void StdArray::ArrayInitialization()
{
    /*   //Initializing std::array<T, N>, where T is a scalar type and N is the number of elements of type T
    // 1) Using aggregate-initialization */
    std::array<int, 3> arrFirst{0, 1, 2};
    // or equivalently
    std::array<int, 3> arrSecond = {2, 3, 4};

    //2)Using Copy Constructor
    std::array<int, 3> arrThird{0, 2, 3};
    std::array<int, 3> arrThirdcpy(arrThird);
    //or equavalently
    std::array<int, 3> arrThirdCpyAlt = arrThird;

    std::cout << "Array Size : " << arrSecond.size() << std::endl;

    for (int i = 0; i < arrSecond.size(); i++)
    {
        std::cout << "Agregate Initialization : " << arrFirst.at(i) << ":" << arrSecond.at(i) << std::endl;
    }

    for (int i = 0; i < arrThird.size(); i++)
    {
        std::cout << "Using Copy Constructor : " << arrThird.at(i) << ":" << arrThirdcpy.at(i) << ":" << arrThirdCpyAlt.at(i) << std::endl;
    }
}

void StdArray::ArrayInitStruct()
{
    struct arrStruct
    {
        int values[3];
    };
    // 1) Using aggregate initialization with brace elision
    // It works only if T is an aggregate type!
    std::array<arrStruct, 2> arrFirst{0, 1, 2, 3, 4, 5};
    //or equavalently
    std::array<arrStruct, 2> arrSecond = {0, 1, 2, 3, 4, 5};

    for (int i = 0; i < arrFirst.size(); i++)
    {   
        std::cout<<"Size of the struct : "<< arrFirst.size()<<std::endl;
        std::cout << "Array Elements : " << arrFirst.at(i).values[i] << std::endl;
    }

    // 2) Using aggregate initialization with brace initialization of sub-elements
    std::array<arrStruct, 2> arrThird{arrStruct{0, 1, 2}, arrStruct{3, 4, 5}};
    // or equivalently
    std::array<arrStruct, 2> arrFort = {arrStruct{0, 1, 2}, arrStruct{3, 4, 5}};

    // 3)
    std::array<arrStruct, 2> arrFifth{{{0, 1, 2}, {3, 4, 5}}};
    // or equivalently
    std::array<arrStruct, 2> arrSixth = {{{0, 1, 2}, {3, 4, 5}}};

    //Using The Copy constructor
    std::array<arrStruct, 2> arrSeventh{1, 2, 3};
    std::array<arrStruct, 2> arrSeventhCpy(arrSeventh);
    //or equivalently
    std::array<arrStruct, 2> arrSeventhCpyAlt = arrSeventhCpy;

    //5)Using the move Constructor
    /* A move constructor allows the resources owned by an rvalue object to be moved into an lvalue without creating its copy. 
An rvalue is an expression that does not have any memory address, and an lvalue is an expression with a memory address. */
    std::array<arrStruct, 2> arrEighth = std::array<arrStruct, 2>{0, 1, 2, 3, 4, 5};
}

void StdArray::ElementAccess()
{
    std::array<int, 3> arr;

    //at example
    arr.at(0) = 4;
    arr.at(1) = 8;
    arr.at(2) = 12;

    int a = arr.at(0);
    int b = arr.at(1);
    int c = arr.at(2);

    std::cout << "Access element with 'at'  : " << a << " : " << b << " : " << c << std::endl;

    //operator[pos] Example
    arr[0] = 2;
    arr[1] = 4;
    arr[2] = 6;

    int posA = arr[0];
    int posB = arr[1];
    int posC = arr[2];

    std::cout << "Access Element with 'pos[]' : " << posA << " : " << posB << " : " << posC << std::endl;

    //std::get<pos> example
    /* This non-member function returns a reference to the element at compile-time constant position pos without
    bounds checking. If pos is not within the range of the container, a runtime segmentation violation error can occur. */
    std::get<0>(arr) = 15;
    std::get<1>(arr) = 18;
    std::get<2>(arr) = 21;

    // read values
    int getPosA = std::get<0>(arr); // a is now 2
    int getPosB = std::get<1>(arr); // b is now 4
    int getPosC = std::get<2>(arr); // c is now 6

    std::cout << "Access Element with 'pos[]' : " << getPosA << " : " << getPosB << " : " << getPosC << std::endl;

    //front example
    //Returns a reference to the first element in container. Calling front() on an empty container is undefined.
    int frontVal = arr.front(); //it shows first element

    std::cout << "First Element of The Array is : " << frontVal << std::endl;

    //back() example
    int backVal = arr.back(); //it shows last element
    std::cout << "Last Element of The Array is : " << backVal << std::endl;

    //data() example
    const char *cstr = "Test string";
    std::array<char, 12> arrStr;
    std::memcpy(arrStr.data(), cstr, 12);    // copy cstr to arr
    std::cout << arrStr.data() << std::endl; // outputs: Test string
}

void StdArray::IteratingThroughArray()
{
    std::array<int, 3> arr = {1, 2, 3};
    for (auto i : arr)
        std::cout << i << '\n';
}

void StdArray::ChangingAllElements()
{

    std::array<int, 3> arr = {1, 2, 3};
    // change all elements of the array to 100
    arr.fill(100);

    if (!arr.empty())
    {

        for (int i = 0; i < arr.size(); i++)
        {
            std::cout << "Filled Array Elements : " << arr.at(i) << std::endl;
        }
    }
}