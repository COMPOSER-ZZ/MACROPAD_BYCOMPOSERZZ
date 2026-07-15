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
    static constexpr uint8_t MAX_KEYS = 6;

    ActionType type;
    KeyCode keys[MAX_KEYS];
    uint8_t keyCount;
    uint8_t macroId;

    Action()
        : type(ActionType::NONE),
          keys{
              KeyCode::NONE,
              KeyCode::NONE,
              KeyCode::NONE,
              KeyCode::NONE,
              KeyCode::NONE,
              KeyCode::NONE
          },
          keyCount(0),
          macroId(0)
    {
    }
};

#endif