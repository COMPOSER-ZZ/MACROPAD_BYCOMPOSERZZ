#ifndef ACTION_H
#define ACTION_H

#include <Arduino.h>

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

    uint8_t data[8] = {0};
};

#endif