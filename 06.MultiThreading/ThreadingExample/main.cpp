#include "UavTaiContrDerived.h"
#include "UavBaykarContrDerived.h"

int main(){
    std::unique_ptr<UavBaykarContrDerived> uavControllerBaykar = std::make_unique<UavBaykarContrDerived>();
    std::unique_ptr<UavTaiContrDerived> uavControllerTai = std::make_unique<UavTaiContrDerived>();
    uavControllerBaykar.get()->init();
    uavControllerTai.get()->init();

    uavControllerBaykar.get()->getMainThread()->get();
    uavControllerTai.get()->getMainThread()->get();
}