#ifndef PROFILE_H
#define PROFILE_H

#include <Arduino.h>

#include "Action.h"
#include "ButtonEvent.h"
#include "InteractionConfig.h"
#include "Macro.h"

class Profile
{
public:

    void begin();

    Action getAction(uint8_t buttonID, ButtonEvent event) const;

    InteractionConfig getInteractionConfig(uint8_t buttonID) const;

    const Macro* getMacro(uint8_t macroId) const;

private:

    static constexpr uint8_t NUM_BUTTONS = 15;
    static constexpr uint8_t NUM_EVENTS = 6;
    static constexpr uint8_t NUM_MACROS = 1;

    Action actions[NUM_BUTTONS][NUM_EVENTS];
    InteractionConfig interactionConfigs[NUM_BUTTONS];
    Macro macros[NUM_MACROS];

    uint8_t eventToIndex(ButtonEvent event) const;

    bool isValidButton(uint8_t buttonID) const;
};

#endif