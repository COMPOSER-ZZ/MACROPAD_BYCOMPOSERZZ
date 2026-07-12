#include "EventListener.h"


void EventListener::handle(uint8_t buttonID, ButtonEvent event)
{

    Serial.print("BTN ");
    Serial.print(buttonID);


    switch(event)
    {

        case ButtonEvent::PRESS:

            Serial.println(" PRESS");

            break;


        case ButtonEvent::RELEASE:

            Serial.println(" RELEASE");

            break;


        case ButtonEvent::CLICK:

            Serial.println(" CLICK");

            break;


        case ButtonEvent::DOUBLE_CLICK:

            Serial.println(" DOUBLE CLICK");

            break;


        case ButtonEvent::LONG_PRESS:

            Serial.println(" LONG PRESS");

            break;

    }

}