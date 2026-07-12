#include "EventListener.h"

#include "Profile.h"
#include "ActionExecutor.h"
void EventListener::setProfile(Profile* profile)
{
    this->profile = profile;
}

void EventListener::setExecutor(ActionExecutor* executor)
{
    this->executor = executor;
}

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

            if(profile != nullptr && executor != nullptr)
            {
                Action action = profile->getAction(buttonID - 1);

                executor->execute(action);
            }

            break;


        case ButtonEvent::DOUBLE_CLICK:

            Serial.println(" DOUBLE CLICK");

            break;


        case ButtonEvent::LONG_PRESS:

            Serial.println(" LONG PRESS");

            break;


        case ButtonEvent::HOLD_REPEAT:

            Serial.println(" HOLD REPEAT");

            break;

    }

}