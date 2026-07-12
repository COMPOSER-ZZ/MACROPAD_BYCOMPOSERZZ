#ifndef EVENT_LISTENER_H
#define EVENT_LISTENER_H

#include <Arduino.h>

#include "ButtonEvent.h"
#include "Profile.h"
#include "ActionExecutor.h"

class EventListener
{
public:

    void setProfile(Profile* profile);

    void setExecutor(ActionExecutor* executor);

    void handle(uint8_t buttonID, ButtonEvent event);

private:

    Profile* profile = nullptr;

    ActionExecutor* executor = nullptr;

};

#endif