#ifndef EVENT_MANAGER_H
#define EVENT_MANAGER_H

#include <Arduino.h>
#include "ButtonEvent.h"
#include "EventListener.h"


class EventManager
{

public:

    void begin();

    void update();

    void onPress(uint8_t id);

    void onRelease(uint8_t id);

    void emitEvent(uint8_t id, ButtonEvent event);

    void setListener(EventListener* listener);


private:

    static const uint8_t NUM_BUTTONS = 15;


    bool buttonDown[NUM_BUTTONS];

    unsigned long pressTime[NUM_BUTTONS];

    bool longPressSent[NUM_BUTTONS];


    static const unsigned long LONG_PRESS_TIME = 600;


    EventListener* listener = nullptr;

};


#endif