#include "MacroRunner.h"

#include "ActionExecutor.h"

void MacroRunner::setExecutor(ActionExecutor* executor)
{
    this->executor = executor;
}

void MacroRunner::start(const Macro* macro)
{
    cancel();

    if (
        macro == nullptr ||
        macro->steps == nullptr ||
        macro->stepCount == 0
    )
    {
        return;
    }

    activeMacro = macro;
    nextStepIndex = 0;
    nextStepAt = millis();
}

void MacroRunner::cancel()
{
    activeMacro = nullptr;
    nextStepIndex = 0;
    nextStepAt = 0;
}

void MacroRunner::update()
{
    if (executor == nullptr || activeMacro == nullptr)
    {
        return;
    }

    const unsigned long now = millis();

    if (static_cast<int32_t>(now - nextStepAt) < 0)
    {
        return;
    }

    if (nextStepIndex >= activeMacro->stepCount)
    {
        cancel();
        return;
    }

    const MacroStep& step = activeMacro->steps[nextStepIndex];

    executor->execute(step.action);

    nextStepIndex++;

    if (nextStepIndex >= activeMacro->stepCount)
    {
        cancel();
        return;
    }

    nextStepAt = now + step.delayAfterMs;
}

bool MacroRunner::isRunning() const
{
    return activeMacro != nullptr;
}