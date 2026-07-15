#ifndef MACRO_RUNNER_H
#define MACRO_RUNNER_H

#include <Arduino.h>

#include "Macro.h"

class ActionExecutor;

class MacroRunner
{
public:

    void setExecutor(ActionExecutor* executor);

    void start(const Macro* macro);

    void cancel();

    void update();

    bool isRunning() const;

private:

    ActionExecutor* executor = nullptr;

    const Macro* activeMacro = nullptr;

    uint8_t nextStepIndex = 0;

    unsigned long nextStepAt = 0;
};

#endif