#ifndef EVENT_INTERPRETER_H
#define EVENT_INTERPRETER_H

#include <Arduino.h>
#include "EventListener.h"

class EventInterpreter
{
public:

    void onPress(uint8_t buttonID);

    void onRelease(uint8_t buttonID);

    void update();

    void setListener(EventListener* listener);

private:

    EventListener* listener = nullptr;

};

#endif