#ifndef BASICTYPEKEYWORD_H
#define BASICTYPEKEYWORD_H

#include <iostream>
#include <functional>

//Enum and struct also keyword"
class BasicTypeKeyword
{
public:
    BasicTypeKeyword();
    BasicTypeKeyword(int val);
    BasicTypeKeyword(const BasicTypeKeyword &ruleOfThree);            // II. COPY CONSTRUCTOR
    BasicTypeKeyword &operator=(const BasicTypeKeyword &ruleOfThree); // III. COPY ASSIGNMENT
    ~BasicTypeKeyword();    

    void basicTypeKeywordProcess();

    struct BasicKeywordStr{
        char charZero; //It is implementation-defined whether char is signed (and has a range of at least -127 to +127, inclusive, 8 bit val
        int intValue;
        float floatVal;
        double doubleVal;
        long longVal; // 32 bit val
        short shortVal; //16bit val
        bool boolVal; //boolean val
        wchar_t *widesetcharacters;//An integer type large enough to represent all characters of the largest supported extended character set, also known as the wide-character set.
        char16_t *message;//An unsigned integer type with the same size and alignment as uint_least16_t,
        char32_t *fullhouse;//range includes at least -32767 to +32767, inclusive

        BasicKeywordStr(){
            charZero = 0;
            intValue = 2;
            floatVal = 3.145f;
            doubleVal = 3.1243545;
            longVal = 26;
            shortVal = 55;
            boolVal = false;
            message = u"process\n\r"; 
            fullhouse = U"process";
            widesetcharacters = L"you can write anything you watn for wchar_T";
        }
    };   
   
};
#endif