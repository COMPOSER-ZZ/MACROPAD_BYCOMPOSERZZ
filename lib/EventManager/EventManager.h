#ifndef EVENT_MANAGER_H
#define EVENT_MANAGER_H

#include <Arduino.h>

#include "ButtonEvent.h"
#include "InteractionConfig.h"
#include "EventListener.h"

enum class InteractionState : uint8_t
{
    IDLE,
    PRESSED,
    LONG_HOLDING,
    WAIT_SECOND_CLICK,
    SECOND_PRESSED
};



struct ButtonContext
{
    InteractionState state = InteractionState::IDLE;

    unsigned long pressedAt = 0;
    unsigned long releasedAt = 0;
    unsigned long lastRepeatAt = 0;
};

class EventManager
{
public:

    void begin();

    void update();

    void onPress(uint8_t id);

    void onRelease(uint8_t id);

    void setListener(EventListener* listener);

    void setInteractionConfig(uint8_t id, const InteractionConfig& config);

private:

    static constexpr uint8_t NUM_BUTTONS = 15;

    InteractionConfig configs[NUM_BUTTONS];
    ButtonContext contexts[NUM_BUTTONS];

    EventListener* listener = nullptr;

    bool isValidButton(uint8_t id) const;

    void emitEvent(uint8_t id, ButtonEvent event);
};

#endif