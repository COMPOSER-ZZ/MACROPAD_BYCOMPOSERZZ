#include "EventManager.h"


void EventManager::begin()
{
    for (uint8_t i = 0; i < NUM_BUTTONS; i++)
    {
        buttonDown[i] = false;
        pressTime[i] = 0;
        longPressSent[i] = false;
    }
}


void EventManager::update()
{
    unsigned long now = millis();

    for (uint8_t i = 0; i < NUM_BUTTONS; i++)
    {
        if (buttonDown[i] && !longPressSent[i])
        {
            if (now - pressTime[i] >= LONG_PRESS_TIME)
            {
                longPressSent[i] = true;

                emitEvent(i, ButtonEvent::LONG_PRESS);
            }
        }
    }
}


void EventManager::onPress(uint8_t id)
{
    buttonDown[id] = true;

    pressTime[id] = millis();

    longPressSent[id] = false;

    emitEvent(id, ButtonEvent::PRESSED);
}


void EventManager::onRelease(uint8_t id)
{
    emitEvent(id, ButtonEvent::RELEASED);

    if (buttonDown[id])
    {
        buttonDown[id] = false;

        if (!longPressSent[id])
        {
            emitEvent(id, ButtonEvent::CLICK);
        }
    }
}


void EventManager::emitEvent(uint8_t id, ButtonEvent event)
{
    Serial.print("BTN ");
    Serial.print(id + 1);

    switch(event)
    {
        case ButtonEvent::PRESSED:

            Serial.println(" PRESSED");
            break;


        case ButtonEvent::RELEASED:

            Serial.println(" RELEASED");
            break;


        case ButtonEvent::CLICK:

            Serial.println(" CLICK");
            break;


        case ButtonEvent::LONG_PRESS:

            Serial.println(" LONG PRESS");
            break;
    }
}