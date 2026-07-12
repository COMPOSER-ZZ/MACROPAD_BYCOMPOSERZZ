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

    void setListener(EventListener* listener);

private:

    struct ButtonState
{
    bool pressed = false;

    bool longPressSent = false;

    bool waitingDoubleClick = false;

    unsigned long pressTime = 0;

    unsigned long releaseTime = 0;

    unsigned long lastRepeatTime = 0;
};

    static constexpr uint8_t NUM_BUTTONS = 15;

    static constexpr unsigned long LONG_PRESS_TIME = 600;

    static constexpr unsigned long HOLD_REPEAT_TIME = 100;
    static constexpr unsigned long DOUBLE_CLICK_TIME = 250;
    ButtonState buttons[NUM_BUTTONS];

    EventListener* listener = nullptr;

    void emitEvent(uint8_t id, ButtonEvent event);
};

#endif