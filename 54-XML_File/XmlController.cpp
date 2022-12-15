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

tinyxml2::XMLElement* XmlController::getNodeByTag(tinyxml2::XMLNode* node, const char * tag){
    std::vector<tinyxml2::XMLElement*> tList = getNodesByTag(node, tag);
	return tList.size() > 0 ? tList[0] : nullptr;
}

std::vector<tinyxml2::XMLElement*> XmlController::getNodesByTag(tinyxml2::XMLNode* node, const char * tag){
     std::vector<tinyxml2::XMLElement*> tList;

	if (node->NoChildren() == true)
	{
		return tList;
	}

	tinyxml2::XMLNode* child = node->FirstChild();
	do
	{
		tinyxml2::XMLElement* tElem = child->ToElement();
		if (tElem != nullptr)
		{
			if (std::string(tElem->Name()) == tag)
			{
				tList.push_back(tElem);
			}
		}

	} while ((child = child->NextSibling()) != nullptr);

	return tList;
}

std::vector<tinyxml2::XMLElement*> XmlController::getChildNodes(tinyxml2::XMLNode* node){
    std::vector<tinyxml2::XMLElement*> list;

	if (node == nullptr)
	{
		return list;
	}

	if (node->NoChildren() == false)
	{
		tinyxml2::XMLNode* child = node->FirstChild();
		do
		{
			tinyxml2::XMLElement* elem = child->ToElement();
			if (elem != nullptr)
			{
				list.push_back(elem);
			}

		} while ((child = child->NextSibling()) != nullptr);
	}

	return list;
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
    std::cout<<"------------------Get Elements By Attribute--------------"<<std::endl;
    while(tElementByAttrName){
        std::cout<< " Element attribute name is : "<<tElementByAttrName->Attribute("name")<<std::endl;
        tElementByAttrName = tElementByAttrName->NextSiblingElement();
    }
    std::cout<<"---------------------------------------------------------"<<std::endl;
       
}

void XmlController::findChildNodes(){
    if(mMainXmlDoc == nullptr || mMainXmlDoc->Error())
        return;
    tinyxml2::XMLElement *tElementByAttrName =  getElementWithAttrName(getXmlMainDoc(),"name","Other UAV Vehicles");
    std::vector<tinyxml2::XMLElement*> tElementList = getChildNodes(tElementByAttrName);
    std::cout<<"------------------Get Child Nodes From The List--------------"<<std::endl;
    for(const auto &Item : tElementList){
        std::cout<< " Element attribute name is : "<<Item->Attribute("name")<<std::endl;
    }
    std::cout<<"---------------------------------------------------------"<<std::endl;
}

void XmlController::attributeTypes(){
    if(mMainXmlDoc == nullptr || mMainXmlDoc->Error())
        return;
    tinyxml2::XMLElement *tElementByAttribute = getElementWithAttrName(getXmlMainDoc(),"name","Complex UAV Vehicles");
    tElementByAttribute = tElementByAttribute->FirstChildElement();
    std::cout<<"------------------Attribute Types--------------"<<std::endl;
    while(tElementByAttribute){
        std::cout<<"Int Type Attribute : "<<"Type : "<<typeid(tElementByAttribute->IntAttribute("uniqueId")).name()<< " : Value : "<< tElementByAttribute->IntAttribute("uniqueId")<<std::endl;
        std::cout<<"String Type Attribute : "<<"Type : "<<typeid(tElementByAttribute->Attribute("uniqueId")).name()<< " : Value : "<< tElementByAttribute->Attribute("uniqueId")<<std::endl;
        std::cout<<"Int 64 Type Attribute : "<<"Type : "<<typeid(tElementByAttribute->Int64Attribute("uniqueId")).name()<< " : Value : "<< tElementByAttribute->Int64Attribute("uniqueId")<<std::endl;
        std::cout<<"Bool Type Attribute : "<<"Type : "<<typeid(tElementByAttribute->BoolAttribute("uniqueId")).name()<< " : Value : "<< tElementByAttribute->BoolAttribute("uniqueId")<<std::endl;
        tElementByAttribute = tElementByAttribute->NextSiblingElement();
    }
    std::cout<<"---------------------------------------------------------"<<std::endl;

    
}

void XmlController::printXmlHeaders(){
    std::cout<<"------------------XML HEADERS Types--------------"<<std::endl;
    std::cout<<XMLHeaders::xmlHeader<<std::endl;
    std::cout<<XMLHeaders::commentHeader<<std::endl;
    std::cout<<XMLHeaders::cdataHeader<<std::endl;
    std::cout<<XMLHeaders::dtdHeader<<std::endl;
    std::cout<<XMLHeaders::elementHeader<<std::endl;
    std::cout<<"---------------------------------------------------------"<<std::endl;
}
