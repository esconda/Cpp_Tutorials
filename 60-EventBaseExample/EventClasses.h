#ifndef EVENTCLASSES_h
#define EVENTCLASSES_h
#include "EventTypes.h"
#include "EventClassesInterface.h"
class ButtonClickedEvent : public EventClassesInterface{
    public:
    UIEventType getType() const override{
        return UIEventType::BUTTON_CLICKED;
    }
};

class TextChangedEvent : public EventClassesInterface{
    public:
    UIEventType getType() const override{
        return UIEventType::TEXT_CHANGED;
    }
};

class DropDownChangedEvent : public EventClassesInterface{
    public:
    UIEventType getType() const override{
        return UIEventType::DROPDOWN_CHANGED;
    }
};

//You can add other eventclasses,Also you can create each class seperately
#endif