#ifndef EVENTLISTENERS_H
#define EVENTLISTENERS_H
#include "EventListenersInterface.h"
#include "EventTypes.h"
#include <iostream>
class ButtonClickListener : public EventListenersInterface{
    public:
    void onEvent(const EventClassesInterface& event) override
    {
        if(event.getType() == UIEventType::BUTTON_CLICKED)
        {
            std::cout << "Button clicked!" << std::endl;
        }
    }
};

class TextChangedListener : public EventListenersInterface{
    public:
    void onEvent(const EventClassesInterface& event) override
    {
        if(event.getType() == UIEventType::TEXT_CHANGED)
        {
            std::cout << "Text is changed!" << std::endl;
        }
    }
};

class DropDownChangedListener : public EventListenersInterface{
    public:
    void onEvent(const EventClassesInterface& event) override
    {
        if(event.getType() == UIEventType::DROPDOWN_CHANGED)
        {
            std::cout << "DropDown is changed!" << std::endl;
        }
    }
};
#endif