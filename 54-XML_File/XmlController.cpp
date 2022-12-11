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

tinyxml2::XMLElement* XmlController::getElementWithTagName(tinyxml2::XMLNode * pParent, const std::string &pTagName) const{

    if ( !pParent ) return nullptr;

    tinyxml2::XMLNode * tChild;
    for ( tChild = pParent->FirstChild(); tChild != 0; tChild = tChild->NextSibling()) 
    {
         if(tChild->Value()==pTagName.c_str()){
            return tChild->ToElement();
            break;
        }

        else{
            getElementWithTagName( tChild, pTagName);
        }
    }
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

const char * XmlController::getIndent(unsigned int pNumOfIndents){
    static const char * tIndent = "                                      + ";
    static const unsigned int tLength = strlen( tIndent );

    if ( pNumOfIndents > tLength ) pNumOfIndents = tLength;
     return &tIndent[ tLength-pNumOfIndents ];
}

void XmlController::dumpToStdOut(tinyxml2::XMLNode * pParent, unsigned int pIndent = 0){
    if ( !pParent ) return;


    tinyxml2::XMLText *Text;
    int t = pParent->;
    printf( "%s", getIndent(pIndent));

    switch ( t )
    {
    case tinyxml2::XMLNode::DOCUMENT:
        printf( "Document" );
        break;

    case TiXmlNode::ELEMENT:
        printf( "Element \"%s\"", pParent->Value() );
        break;

    case TiXmlNode::COMMENT:
        printf( "Comment: \"%s\"", pParent->Value());
        break;

    case TiXmlNode::UNKNOWN:
        printf( "Unknown" );
        break;

    case TiXmlNode::TEXT:
        pText = pParent->ToText();
        printf( "Text: [%s]", pText->Value() );
        break;

    case TiXmlNode::DECLARATION:
        printf( "Declaration" );
        break;
    default:
        break;
    }
    printf( "\n" );

    tinyxml2::XMLNode * pChild;

    for ( pChild = pParent->FirstChild(); pChild != 0; pChild = pChild->NextSibling()) 
    {
        dumpToStdOut( pChild, pIndent+2 );
    }
}

void XmlController::load_and_display(){
     // important for the poetry demo, but you may not need this 
    // in your own projects
    tinyxml2::XMLUtil::SkipWhiteSpace( false );

    TiXmlDocument doc( "demo.xml" );
    bool loadOkay = doc.LoadFile();

    if ( loadOkay )
    {
        dump_to_stdout( &doc );
    }
    else
    {
        printf( "Something went wrong\n" );
    }
}

