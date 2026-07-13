#ifndef PROFILE_H
#define PROFILE_H

#include <Arduino.h>

#include "Action.h"
#include "ButtonEvent.h"
#include "InteractionConfig.h"

class Profile
{
public:

    void begin();

    Action getAction(uint8_t buttonID, ButtonEvent event) const;

    InteractionConfig getInteractionConfig(uint8_t buttonID) const;

private:

    static constexpr uint8_t NUM_BUTTONS = 15;
    static constexpr uint8_t NUM_EVENTS = 6;

    Action actions[NUM_BUTTONS][NUM_EVENTS];
    InteractionConfig interactionConfigs[NUM_BUTTONS];

    uint8_t eventToIndex(ButtonEvent event) const;

    bool isValidButton(uint8_t buttonID) const;
};

#endif