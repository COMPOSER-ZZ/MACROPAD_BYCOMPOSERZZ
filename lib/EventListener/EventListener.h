#ifndef EVENT_LISTENER_H
#define EVENT_LISTENER_H

#include <Arduino.h>

#include "ButtonEvent.h"

class Profile;
class ActionExecutor;
class MacroRunner;

class EventListener
{
public:

    void setProfile(Profile* profile);

    void setExecutor(ActionExecutor* executor);

    void setMacroRunner(MacroRunner* macroRunner);

    void handle(uint8_t buttonID, ButtonEvent event);

private:

    Profile* profile = nullptr;

    ActionExecutor* executor = nullptr;

    MacroRunner* macroRunner = nullptr;
};

#endif