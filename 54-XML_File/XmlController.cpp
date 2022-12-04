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

bool XmlController::openXmlFile(const std::string &pFolderName, const std::string &pFileName){
    if(mMainXmlDoc == nullptr)
        return false;

    mMainXmlDoc->Clear();
    mMainXmlDoc->LoadFile((pFolderName+pFileName).c_str());

    if(mMainXmlDoc->Error() == true){
        std::cout<<"File Read Error : "<<mMainXmlDoc->ErrorName()<<std::endl;
        std::cout<<"Error Info : "<<mMainXmlDoc->ErrorStr()<<std::endl;
        std::cout<< "File Name : "<<pFolderName+pFileName<<std::endl;
        return false;
    }
    else{
        std::cout<<"File is read correctly : "<<(pFolderName+pFileName).c_str()<<std::endl;
        return true;
    }
    
}

void XmlController::uavElementsProcess(){
    
    tinyxml2::XMLElement *tUavVehicles = mMainXmlDoc->FirstChildElement();
    std::cout<< tUavVehicles->FirstChildElement()->Attribute("name")<<std::endl;
    std::cout<< tUavVehicles->FirstChildElement()->NextSibling()->ToElement()->Attribute("name")<<std::endl;
    std::cout<< tUavVehicles->FirstChildElement()->NextSiblingElement()->Attribute("name")<<std::endl;
}


