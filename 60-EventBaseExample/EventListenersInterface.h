#ifndef EVENTLISTENERSINTERFACE_H
#define EVENTLISTENERSINTERFACE_H
#include "EventClassesInterface.h"
class EventListenersInterface{
    public:
    virtual ~EventListenersInterface() = default;
    virtual void onEvent(const EventClassesInterface& event) = 0;
};
#endif