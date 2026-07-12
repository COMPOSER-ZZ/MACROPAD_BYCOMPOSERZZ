#include "ActionExecutor.h"

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

            keyboard->print((char)action.data[0]);

            break;

        default:

            break;
    }
}