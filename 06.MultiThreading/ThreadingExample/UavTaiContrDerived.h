#ifndef UAVTAICONTRDERIVED_H
#define UAVTAICONTRDERIVED_H
#include "ThreadBaseClass.h"
//Author : Burak Dogancay
class UavTaiContrDerived : public ThreadBaseClass 
{
public:
    UavTaiContrDerived();
    ~UavTaiContrDerived();

    virtual void tickUpdate() override;
    virtual void someOtherFunctions() override;
    void showUavInfos();
    void taiInfo();
};

#endif