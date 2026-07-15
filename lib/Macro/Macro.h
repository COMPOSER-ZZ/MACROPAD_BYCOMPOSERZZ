#ifndef MACRO_H
#define MACRO_H

#include <Arduino.h>

#include "Action.h"

struct MacroStep
{
    Action action;
    uint16_t delayAfterMs;

    MacroStep()
        : action(),
          delayAfterMs(0)
    {
    }

    MacroStep(
        const Action& stepAction,
        uint16_t stepDelayAfterMs
    )
        : action(stepAction),
          delayAfterMs(stepDelayAfterMs)
    {
    }
};
struct Macro
{
    const MacroStep* steps = nullptr;
    uint8_t stepCount = 0;
};

#endif