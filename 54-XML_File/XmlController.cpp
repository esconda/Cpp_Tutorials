// Author: Burak Doğançay
#include "XmlController.h"
XmlController::XmlController():
mMainXmlDoc(nullptr)
{
}

XmlController::~XmlController(){
    if(mMainXmlDoc)
        delete mMainXmlDoc;
}

void XmlController::init(){
    mMainXmlDoc = new tinyxml2::XMLDocument();
}

tinyxml2::XMLDocument* XmlController::getXmlMainDoc() const{
    return mMainXmlDoc;
}

tinyxml2::XMLElement* XmlController::getFirstElementWithTagName(tinyxml2::XMLNode * pParent, const std::string &pTagName) const{

    if(mMainXmlDoc == nullptr || mMainXmlDoc->Error())
        return nullptr;

    if ( !pParent ) return nullptr;

    tinyxml2::XMLNode *tChild;
    for ( tChild = pParent->FirstChild(); tChild != 0; tChild = tChild->NextSibling()) 
    {
        if(std::string(tChild->Value()).compare(pTagName.c_str()) == 0 ){
            specificXmlElements.elmntByTagName = tChild->ToElement();
            break;
        }
        else{
            getFirstElementWithTagName( tChild, pTagName);
        }
    }
    return specificXmlElements.elmntByTagName;
}
tinyxml2::XMLElement* XmlController::getElementWithAttrName(tinyxml2::XMLNode * pParent, const char *pAttributeName, const char *pAttributeText) const{
    if(mMainXmlDoc == nullptr || mMainXmlDoc->Error())
        return nullptr;

    if ( !pParent ) return nullptr;

    tinyxml2::XMLNode *tChild;
    for ( tChild = pParent->FirstChild(); tChild != 0; tChild = tChild->NextSibling()) 
    {
        static bool tCond;
        tCond = tChild->ToElement() && tChild->ToElement()->Attribute(pAttributeName);
        if(tCond){
            if(std::string(tChild->ToElement()->Attribute(pAttributeName)).compare(pAttributeText)==0){
                specificXmlElements.elmntByAttrName = tChild->ToElement();
                break;
            }
        }
        getElementWithAttrName( tChild, pAttributeName , pAttributeText);    
    }    
    return specificXmlElements.elmntByAttrName;
}

bool XmlController::openXmlFile(const std::string &pFolderName, const std::string &pFileName){
    if(mMainXmlDoc == nullptr)
        return false;

    mMainXmlDoc->Clear();
    mMainXmlDoc->LoadFile((pFolderName+pFileName).c_str());

    if(mMainXmlDoc->Error() == true){
        std::cout<<"File Read Error : "<<mMainXmlDoc->ErrorName()<<std::endl;
        std::cout<<"Error Info : "<<mMainXmlDoc->ErrorStr()<<std::endl;
        std::cout<<"Error Id : " << mMainXmlDoc->ErrorID()<<std::endl;
        std::cout<< "File Name : "<<pFolderName+pFileName<<std::endl;
        return false;
    }
    else{
        std::cout<<"File is read correctly : "<<(pFolderName+pFileName).c_str()<<std::endl;
        return true;
    }
    
}

void XmlController::uavElementsProcess(){
    if(mMainXmlDoc == nullptr || mMainXmlDoc->Error())
        return;
    tinyxml2::XMLElement *tUavVehicles = mMainXmlDoc->FirstChildElement();
    tinyxml2::XMLElement *tUavVehicleType = tUavVehicles->FirstChildElement();

    while(tUavVehicleType){
        tinyxml2::XMLElement *tUavItem = tUavVehicleType->FirstChildElement();
        uavElementsArr.uavVehicleTypes.emplace_back(tUavVehicleType->Attribute("name"));

        while(tUavItem){
           
            if(tUavVehicleType->IntAttribute("id")==0)
                uavElementsArr.uavBasicElems.emplace_back(tUavItem->Attribute("name"));
            if(tUavVehicleType->IntAttribute("id")==1)
                uavElementsArr.uavComplexElems.emplace_back(tUavItem->Attribute("name"));
            if(tUavVehicleType->IntAttribute("id")==2)
                uavElementsArr.uavAdvanceElems.emplace_back(tUavItem->Attribute("name"));
            if(tUavVehicleType->IntAttribute("id")==3)
                uavElementsArr.uavOtherElems.emplace_back(tUavItem->Attribute("name"));

            tUavItem = tUavItem->NextSiblingElement();//Pass to next element
        }
        
        tUavVehicleType = tUavVehicleType->NextSiblingElement();//pass to next element;
    }
    std::cout<<"-----------Uav Main Items-----------"<<std::endl;
    for (auto &n: uavElementsArr.uavVehicleTypes)
        std::cout<<n<<std::endl;
    std::cout<<"------------------------------------"<<std::endl;

    std::cout<<"-----------Uav Basic Vehicles-----------"<<std::endl;
    for (auto &n: uavElementsArr.uavBasicElems)
        std::cout<<n<<std::endl;
    std::cout<<"------------------------------------"<<std::endl;

    std::cout<<"-----------Uav Complex Vehicles-----------"<<std::endl;
    for (auto &n: uavElementsArr.uavComplexElems)
        std::cout<<n<<std::endl;
    std::cout<<"------------------------------------"<<std::endl;

    std::cout<<"-----------Uav Advanced Vehicles-----------"<<std::endl;
    for (auto &n: uavElementsArr.uavAdvanceElems)
        std::cout<<n<<std::endl;
    std::cout<<"------------------------------------"<<std::endl;

    std::cout<<"-----------Uav Other Vehicles-----------"<<std::endl;
    for (auto &n: uavElementsArr.uavOtherElems)
        std::cout<<n<<std::endl;
    std::cout<<"------------------------------------"<<std::endl;
}

void XmlController::loadAndDisplayAllXml(){
    if(mMainXmlDoc == nullptr || mMainXmlDoc->Error())
        return;

    tinyxml2::XMLPrinter tPrinter;
    mMainXmlDoc->Accept(&tPrinter);
    const char* tXmlCstr = tPrinter.CStr();
    std::cout<<"XML Document Information"<<std::endl;
    std::cout<<tXmlCstr<<std::endl;
}

void XmlController::findElementByTagName(){
    if(mMainXmlDoc == nullptr || mMainXmlDoc->Error())
        return;
    tinyxml2::XMLElement *tElementByTagName =  getFirstElementWithTagName(getXmlMainDoc(),"VehicleType");

    while(tElementByTagName){
        std::cout<< " Element attribute name is : "<<tElementByTagName->Attribute("name")<<std::endl;
        tElementByTagName = tElementByTagName->NextSiblingElement();
    }
}

void XmlController::findElementByAttrName(){
    if(mMainXmlDoc == nullptr || mMainXmlDoc->Error())
        return;
    tinyxml2::XMLElement *tElementByAttrName =  getElementWithAttrName(getXmlMainDoc(),"name","Advanced UAV Vehicles");
    tElementByAttrName = tElementByAttrName->FirstChildElement();
    while(tElementByAttrName){
        std::cout<< " Element attribute name is : "<<tElementByAttrName->Attribute("name")<<std::endl;
        tElementByAttrName = tElementByAttrName->NextSiblingElement();
    }
       
}