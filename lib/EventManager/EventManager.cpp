#include "EventManager.h"

void EventManager::begin()
{
    for(uint8_t i = 0; i < NUM_BUTTONS; i++)
    {
        buttons[i] = ButtonState();
    }
}

void EventManager::update()
{
    unsigned long now = millis();

    for(uint8_t i = 0; i < NUM_BUTTONS; i++)
    {
        //----------------------------------------------------
        // LONG PRESS + HOLD REPEAT
        //----------------------------------------------------

        if(buttons[i].pressed)
        {
            if(!buttons[i].longPressSent)
            {
                if(now - buttons[i].pressTime >= LONG_PRESS_TIME)
                {
                    buttons[i].longPressSent = true;

                    buttons[i].lastRepeatTime = now;

                    emitEvent(i, ButtonEvent::LONG_PRESS);
                }
            }
            else
            {
                if(now - buttons[i].lastRepeatTime >= HOLD_REPEAT_TIME)
                {
                    buttons[i].lastRepeatTime = now;

                    emitEvent(i, ButtonEvent::HOLD_REPEAT);
                }
            }
        }

        //----------------------------------------------------
        // CLICK
        //----------------------------------------------------

        if(buttons[i].waitingDoubleClick)
        {
            if(now - buttons[i].releaseTime >= DOUBLE_CLICK_TIME)
            {
                buttons[i].waitingDoubleClick = false;

                emitEvent(i, ButtonEvent::CLICK);
            }
        }
    }
}

void EventManager::onPress(uint8_t id)
{
    //----------------------------------------------------
    // ¿Es el segundo click?
    //----------------------------------------------------

    if(buttons[id].waitingDoubleClick)
    {
        buttons[id].waitingDoubleClick = false;

        emitEvent(id, ButtonEvent::DOUBLE_CLICK);
    }

    buttons[id].pressed = true;

    buttons[id].pressTime = millis();

    buttons[id].longPressSent = false;

    buttons[id].lastRepeatTime = 0;

    emitEvent(id, ButtonEvent::PRESS);
}

void EventManager::onRelease(uint8_t id)
{
    emitEvent(id, ButtonEvent::RELEASE);

    buttons[id].pressed = false;

    //----------------------------------------------------
    // Si hubo LONG_PRESS no existe CLICK
    //----------------------------------------------------

    if(buttons[id].longPressSent)
        return;

    buttons[id].releaseTime = millis();

    buttons[id].waitingDoubleClick = true;
}

void EventManager::emitEvent(uint8_t id, ButtonEvent event)
{
    if(listener != nullptr)
    {
        listener->handle(id, event);
    }
}

void EventManager::setListener(EventListener* listener)
{
    this->listener = listener;
}