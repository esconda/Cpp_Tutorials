// Author: Burak Doğançay
#include "StreamController.h"
#include <filesystem>

int main(int argc, char **argv)
{
   std::unique_ptr<StreamController> streamController = std::make_unique<StreamController>();

   //streamController.get()->ifStreamExample();
   //streamController.get()->osStreamExample();
   streamController.get()->isStreamExample();

   //Serialize Data and create BinaryData.bin
   const std::string filename = "57-Stream/BinaryData.bin";
   StreamController::UAVVehicles originalData = {(char*)"Tb2",(char*)"Baykar",50,152345};
   streamController.get()->dataSerialize(originalData,filename);

   //Deserialize Data and read BinaryData.bin
   StreamController::UAVVehicles loadedData;
   streamController.get()->dataDeserialize(loadedData,filename);

   std::cout<<"----DESERIALIZE DATA---- : FROM : "<<filename<<"..."<<std::endl;
   std::cout<<loadedData.uavName<<" , "
            <<loadedData.uavCompanyName<<" , "
            <<loadedData.uavCount<<" , "
            <<loadedData.uavSerialNo<<std::endl;
   std::cout<<"------------------------------------"<<std::endl;


   //----------------------------
}