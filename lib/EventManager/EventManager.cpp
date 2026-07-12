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


    emitEvent(id, ButtonEvent::PRESS);

}



void EventManager::onRelease(uint8_t id)
{

    emitEvent(id, ButtonEvent::RELEASE);


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

    if(listener)
    {

        listener->handle(id + 1, event);

    }

}



void EventManager::setListener(EventListener* listener)
{

    this->listener = listener;

}