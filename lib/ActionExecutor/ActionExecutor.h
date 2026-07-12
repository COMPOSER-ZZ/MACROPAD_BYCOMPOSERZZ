#ifndef ACTION_EXECUTOR_H
#define ACTION_EXECUTOR_H

#include <Arduino.h>

#include "USBHIDKeyboard.h"

#include "Action.h"

class ActionExecutor
{
public:

    void setKeyboard(USBHIDKeyboard* keyboard);

    void execute(const Action& action);

private:

    USBHIDKeyboard* keyboard = nullptr;

};

#endif