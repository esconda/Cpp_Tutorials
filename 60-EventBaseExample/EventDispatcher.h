#ifndef EVENTDISPATCHER_H
#define EVENTDISPATCHER_H
#include <vector>
#include <memory>
#include "EventListenersInterface.h"
class EventDispatcher{
    private:
    std::vector<std::shared_ptr<EventListenersInterface>> listeners;

    public:
    void addListener(std::shared_ptr<EventListenersInterface> listener)
    {
        listeners.push_back(listener);
    }

    void dispatch(const EventClassesInterface& event)
    {
        for (const std::shared_ptr<EventListenersInterface>& listener : listeners)
        {
            listener->onEvent(event);
        }
    }

};
#endif