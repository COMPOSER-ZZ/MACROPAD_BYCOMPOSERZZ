#ifndef INTERACTION_MANAGER_H
#define INTERACTION_MANAGER_H

#include <Arduino.h>

enum class InteractionMode
{
    CLICK,
    DOUBLE_CLICK,
    LONG_PRESS,
    HOLD_REPEAT
};

struct ButtonPersonality
{
    InteractionMode mode;
};

class InteractionManager
{
public:

    InteractionManager();

    ButtonPersonality getPersonality(uint8_t buttonID);

private:

    ButtonPersonality personalities[15];
};

#endif