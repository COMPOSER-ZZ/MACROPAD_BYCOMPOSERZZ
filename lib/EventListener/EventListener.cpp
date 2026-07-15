#include "EventListener.h"

#include "ActionExecutor.h"
#include "MacroRunner.h"
#include "Profile.h"

void EventListener::setProfile(Profile* profile)
{
    this->profile = profile;
}

void EventListener::setExecutor(ActionExecutor* executor)
{
    this->executor = executor;
}

void EventListener::setMacroRunner(MacroRunner* macroRunner)
{
    this->macroRunner = macroRunner;
}

void EventListener::handle(uint8_t buttonID, ButtonEvent event)
{
    Serial.print("BTN ");
    Serial.print(buttonID);

    switch (event)
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

        case ButtonEvent::HOLD_REPEAT:
            Serial.println(" HOLD REPEAT");
            break;
    }

    if (profile == nullptr)
    {
        return;
    }

    const Action action = profile->getAction(buttonID, event);

    if (action.type == ActionType::MACRO)
    {
        if (macroRunner != nullptr)
        {
            macroRunner->start(profile->getMacro(action.macroId));
        }

        return;
    }

    if (executor != nullptr)
    {
        executor->execute(action);
    }
}