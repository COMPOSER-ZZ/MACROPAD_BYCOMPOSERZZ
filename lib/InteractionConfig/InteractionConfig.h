#ifndef INTERACTION_CONFIG_H
#define INTERACTION_CONFIG_H

#include <Arduino.h>

struct InteractionConfig
{
    bool enableClick = true;
    bool enableDoubleClick = true;
    bool enableLongPress = true;
    bool enableHoldRepeat = true;

    uint16_t longPressTime = 600;
    uint16_t doubleClickTime = 250;
    uint16_t repeatTime = 100;
};

#endif