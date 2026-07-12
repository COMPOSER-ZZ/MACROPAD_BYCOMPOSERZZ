#ifndef KEY_INFO_H
#define KEY_INFO_H

#include <Arduino.h>
#include "KeyCode.h"

enum class KeyCategory
{
    LETTER,
    NUMBER,
    SYMBOL,
    FUNCTION,
    NAVIGATION,
    MODIFIER,
    NUMPAD,
    SYSTEM,
    MULTIMEDIA,
    MOUSE
};

struct KeyInfo
{
    KeyCode code;

    const char* name;

    KeyCategory category;

    uint8_t hidCode;

    bool requiresShift;

    bool printable;
};

#endif