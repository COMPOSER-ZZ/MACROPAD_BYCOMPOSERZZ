#ifndef EVENT_LISTENER_H
#define EVENT_LISTENER_H

#include <Arduino.h>


enum class ButtonEvent
{
    PRESS,
    RELEASE,
    CLICK,
    LONG_PRESS
};


class EventListener
{

public:

    void handle(uint8_t buttonID, ButtonEvent event);

};


#endif