#ifndef INTERACTION_ENGINE_H
#define INTERACTION_ENGINE_H

#include <Arduino.h>
#include "ButtonEvent.h"
#include "EventListener.h"

enum class InteractionMode
{
    CLICK,
    DOUBLE_CLICK,
    LONG_PRESS,
    HOLD_REPEAT
};

struct ButtonPersonality
{
    InteractionMode mode;

    uint16_t holdTime = 500;
    uint16_t repeatTime = 100;
    uint16_t doubleClickTime = 300;
};

struct ButtonRuntime
{
    bool pressed = false;

    bool longPressTriggered = false;

    uint32_t pressTime = 0;
    uint32_t releaseTime = 0;

    uint32_t lastRepeatTime = 0;

    uint8_t clickCount = 0;
};

class InteractionEngine
{
public:

    void begin();

    void setListener(EventListener* listener);

    void onEvent(uint8_t buttonID, ButtonEvent event);

    void update();

private:

    EventListener* listener = nullptr;

    ButtonPersonality personalities[15];

    ButtonRuntime runtime[15];
};

#endif