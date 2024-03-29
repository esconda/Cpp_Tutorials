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

class XmlController
{
public:
    XmlController();
    XmlController(int val) = delete;
    XmlController(XmlController &&ruleOfFive) noexcept = delete;         //III. MOVE CONSTRUCTOR
    XmlController(const XmlController &ruleOfThree) = delete;            // II. COPY CONSTRUCTOR
    XmlController &operator=(const XmlController &ruleOfThree) = delete; // III. COPY ASSIGNMENT
    ~XmlController();

    void init();
    bool openXmlFile(const std::string &pFolderName, const std::string &pFileName);
    void uavElementsProcess();
    void loadAndDisplayAllXml();
    void findElementByTagName();
    void findElementByAttrName();
    void findChildNodes();
    void attributeTypes();
    void printXmlHeaders();


private:
    tinyxml2::XMLDocument* mMainXmlDoc;

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

    struct XMLHeaders{
   
    static constexpr const char* xmlHeader		= { "<?" };
    static constexpr const char* commentHeader	= { "<!--" };
    static constexpr const char* cdataHeader		= { "<![CDATA[" };
    static constexpr const char* dtdHeader		= { "<!" };
    static constexpr const char* elementHeader	= { "<" };	// and a header for everything else; check last.
    }xmlHeaders;

    struct XmlElements{
        XmlElements(){
            elmntByTagName = nullptr;
            elmntByAttrName = nullptr;
        }
        mutable tinyxml2::XMLElement *elmntByTagName;
        mutable tinyxml2::XMLElement *elmntByAttrName;
    }specificXmlElements;

private:
    tinyxml2::XMLDocument* getXmlMainDoc() const;
    tinyxml2::XMLElement* getFirstElementWithTagName(tinyxml2::XMLNode * pParent, const std::string &pTagName) const;
    tinyxml2::XMLElement* getElementWithAttrName(tinyxml2::XMLNode * pParent, const char *pAttributeName, const char *pAttributeText) const;
    tinyxml2::XMLElement* getNodeByTag(tinyxml2::XMLNode* node, const char * tag);
    std::vector<tinyxml2::XMLElement*> getNodesByTag(tinyxml2::XMLNode* node, const char * tag);
    std::vector<tinyxml2::XMLElement*> getChildNodes(tinyxml2::XMLNode* node);
};

#endif