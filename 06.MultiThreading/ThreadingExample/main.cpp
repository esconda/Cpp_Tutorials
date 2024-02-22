#include "UavTaiContrDerived.h"
#include "UavBaykarContrDerived.h"

int main(){
    std::unique_ptr<UavBaykarContrDerived> uavControllerBaykar = std::make_unique<UavBaykarContrDerived>();
    std::unique_ptr<UavTaiContrDerived> uavControllerTai = std::make_unique<UavTaiContrDerived>();
    uavControllerBaykar.get()->init();
    uavControllerTai.get()->init();

    //The get member function waits until the future has a valid result and (depending on which template is used) retrieves it. 
    //It effectively calls wait() in order to wait for the result.
    uavControllerBaykar.get()->getMainThread()->get();
    uavControllerTai.get()->getMainThread()->get();
}