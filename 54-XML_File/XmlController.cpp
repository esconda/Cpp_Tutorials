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
    tinyxml2::XMLElement *tUavVehicleType = tUavVehicles->FirstChildElement();

    while(tUavVehicleType){
        tinyxml2::XMLElement *tUavItem = tUavVehicleType->FirstChildElement();
        uavElementsArr.uavVehicleTypes.emplace_back(tUavVehicleType->Attribute("name"));

        while(tUavItem){
            std::cout<<tUavVehicleType->IntAttribute("id")<<std::endl;
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


