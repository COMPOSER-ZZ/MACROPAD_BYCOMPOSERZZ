#include "ActionExecutor.h"

#include "EncyKEYpedia.h"

void ActionExecutor::setKeyboard(USBHIDKeyboard* keyboard)
{
    this->keyboard = keyboard;
}

void ActionExecutor::execute(const Action& action)
{
    if (keyboard == nullptr)
    {
        return;
    }

    switch (action.type)
    {
        case ActionType::KEYBOARD_KEY:
        {
            const KeyInfo* keyInfo = EncyKEYpedia::getInfo(action.key);

            if (keyInfo == nullptr || keyInfo->hidCode == 0)
            {
                return;
            }

            keyboard->pressRaw(keyInfo->hidCode);
            keyboard->releaseRaw(keyInfo->hidCode);

            break;
        }

        default:

            break;
    }
}