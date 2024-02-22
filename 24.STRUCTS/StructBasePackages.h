#ifndef STRUCTBASEPACKAGES_H
#define STRUCTBASEPACKAGES_H
#include <string>

//------------------------------------------------------------------------------
//Pure struct usage of taiUavInfoV2
struct taiUavInfo 
{
    std::string name = "ANKA";
    std::string type = "UAV-JETBASE";
    std::string company = "TAI";
};

//You can not define struct like below
/* struct  
{
    std::string name = "ANKA";
    std::string type = "UAV-JETBASE";
    std::string company = "TAI";
}taiUavInfo; */

//You have to define "struct" like below
//static taiUavInfo mTaiUavInfo; //it gives you an error
static struct taiUavInfo mTaiUavInfo; // it is OK
static struct taiUavInfo* mTaiUavInfoPtr = &mTaiUavInfo; // it is OK

//with typedef same definition as above
//typedef struct taiUavInfo mTaiUavInfoVar;
//mTaiUavInfoVar myTaiInfoVar;

//------------------------------------------------------------------------------
//Pure struct usage as definition of taiUavInfoV2
// it means "static struct taiUavInfoV2 mTaiUavInfoV2"
static struct taiUavInfoV2 
{
    std::string name = "AKSUNGUR";
    std::string type = "UAV-JETBASE";
    std::string company = "TAI";
}mTaiUavInfoV2; 

static struct taiUavInfoV2* mTaiUavInfoV2Ptr = &mTaiUavInfoV2; 

//------------------------------------------------------------------------------
//Typedef struct usage of BaykarUavInfo
//Declares an anonymous structure and creates a typedef for it.
//Thus, with this construct, it doesn't have a name in the tag namespace, only a name in the typedef namespace.
//This means it also cannot be forward-declared. 
//If you want to make a forward declaration, you have to give it a name in the tag namespace.
typedef struct
{
    std::string name = "MIUS";
    std::string type = "UAV-JETBASE";
    std::string company = "Baykar";
} BaykarUavInfo;

//You can define BaykarUavInfo struct like;
static BaykarUavInfo mBaykarInfo;
static BaykarUavInfo* mBaykarInfoPtr = &mBaykarInfo;

//------------------------------------------------------------------------------
//Typedef struct usage of BaykarUavInfoV2
//is just an abbreviation for the declaration and typedef.
typedef struct baykaruavinfov2
{
    std::string name = "MIUS";
    std::string type = "UAV-JETBASE";
    std::string company = "Baykar";
} BaykarUavInfoV2;

//You can define BaykarUavInfo struct like;
static BaykarUavInfoV2 mBaykarInfoV2;
static BaykarUavInfoV2* mBaykarInfoV2Ptr = &mBaykarInfoV2;

#endif