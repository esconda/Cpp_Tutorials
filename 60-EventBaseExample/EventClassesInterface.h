#ifndef EVENTINTERFACE_H
#define EVENTINTERFACE_H
#include "EventTypes.h"
class EventClassesInterface{

    public:
    virtual ~EventClassesInterface() = default;
    virtual UIEventType getType() const = 0; 
};
#endif