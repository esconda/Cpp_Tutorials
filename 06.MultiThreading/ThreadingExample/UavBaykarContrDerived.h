#ifndef UAVBAYKARCONTRDERIVED_H
#define UAVBAYKARCONTRDERIVED_H
#include "ThreadBaseClass.h"
//Author : Burak Dogancay
class UavBaykarContrDerived : public ThreadBaseClass 
{
public:
    UavBaykarContrDerived();
    ~UavBaykarContrDerived();

    virtual void tickUpdate() override;
    void someOtherFunctions() override;
    void showUavInfos();
    void bayKarInfo();
};

#endif