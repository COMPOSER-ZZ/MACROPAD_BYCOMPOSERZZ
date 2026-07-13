#ifndef ACTION_H
#define ACTION_H

#include <Arduino.h>

#include "KeyCode.h"

enum class ActionType
{
    NONE,

    KEYBOARD_KEY,

    KEYBOARD_COMBINATION,

    MACRO,

    CHANGE_PROFILE
};

struct Action
{
    ActionType type = ActionType::NONE;

    KeyCode key = KeyCode::NONE;
};

#endif