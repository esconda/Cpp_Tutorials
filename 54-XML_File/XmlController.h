// Author: Burak Doğançay
#ifndef XMLCONTROLLER_H
#define XMLCONTROLLER_H
#include <iostream>
#include <memory>
#include <algorithm>
#include <vector>
#include <map>
#include "tinyxml2.h"
#define print(a) std::cout << a
#define printOneLine(a) std::cout << a << std::endl
#define printTwoLine(a,b) std::cout << a << b << std::endl
// An algorithm is a strategy for performing a particular  task such as sorting or searching.These algorithms implemented as function so they work
// on most of the different container types.ALGORİTHMs are not generally part of the containers.It is necessary in order to support generic programming in the standart library
//Note that generic algorithms do not wok directly ont he containers .They use intermediate that called an iterator
class XmlController
{
public:
    XmlController();
    XmlController(int val) = delete;
    XmlController(XmlController &&ruleOfFive) noexcept = delete;         //III. MOVE CONSTRUCTOR
    XmlController(const XmlController &ruleOfThree) = delete;            // II. COPY CONSTRUCTOR
    XmlController &operator=(const XmlController &ruleOfThree) = delete; // III. COPY ASSIGNMENT
    ~XmlController();

    struct UAVElements{
        UAVElements(){
            uavVehicleTypes.reserve(5);
            uavBasicElems.reserve(5);
            uavComplexElems.reserve(5);
            uavAdvanceElems.reserve(5);
            uavOtherElems.reserve(5);
        }
        std::vector<std::string> uavVehicleTypes;
        std::vector<std::string> uavBasicElems;
        std::vector<std::string> uavComplexElems;
        std::vector<std::string> uavAdvanceElems;
        std::vector<std::string> uavOtherElems;
    }uavElementsArr;

    void init();
    tinyxml2::XMLDocument* getXmlMainDoc() const;
    tinyxml2::XMLElement* getElementWithTagName(tinyxml2::XMLNode * pParent, const std::string &pTagName) const;
    bool openXmlFile(const std::string &pFolderName, const std::string &pFileName);
    void uavElementsProcess();
    const char * getIndent( unsigned int pNumOfIndents);
    void dumpToStdOut(tinyxml2::XMLNode * pParent, unsigned int pIndent = 0);
    void load_and_display();


private:
    tinyxml2::XMLDocument* mMainXmlDoc;
};

#endif