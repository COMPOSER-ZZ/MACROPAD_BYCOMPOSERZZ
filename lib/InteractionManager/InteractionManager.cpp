#include "InteractionManager.h"

InteractionManager::InteractionManager()
{
    // BTN1
    personalities[0].mode = InteractionMode::LONG_PRESS;

    // BTN2
    personalities[1].mode = InteractionMode::DOUBLE_CLICK;

    // BTN3
    personalities[2].mode = InteractionMode::HOLD_REPEAT;

    // Resto
    for(uint8_t i = 3; i < 15; i++)
    {
        personalities[i].mode = InteractionMode::CLICK;
    }
}

ButtonPersonality InteractionManager::getPersonality(uint8_t buttonID)
{
    return personalities[buttonID];
}