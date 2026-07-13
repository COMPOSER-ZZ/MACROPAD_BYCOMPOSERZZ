#include "EventManager.h"

void EventManager::begin()
{
    for (uint8_t i = 0; i < NUM_BUTTONS; i++)
    {
        configs[i] = InteractionConfig();
        contexts[i] = ButtonContext();
    }
}

void EventManager::update()
{
    const unsigned long now = millis();

    for (uint8_t i = 0; i < NUM_BUTTONS; i++)
    {
        ButtonContext& context = contexts[i];
        const InteractionConfig& config = configs[i];

        switch (context.state)
        {
            case InteractionState::PRESSED:

                if (
                    config.enableLongPress &&
                    now - context.pressedAt >= config.longPressTime
                )
                {
                    context.state = InteractionState::LONG_HOLDING;
                    context.lastRepeatAt = now;

                    emitEvent(i, ButtonEvent::LONG_PRESS);
                }

                break;

            case InteractionState::LONG_HOLDING:

                if (
                    config.enableHoldRepeat &&
                    now - context.lastRepeatAt >= config.repeatTime
                )
                {
                    context.lastRepeatAt = now;

                    emitEvent(i, ButtonEvent::HOLD_REPEAT);
                }

                break;

            case InteractionState::WAIT_SECOND_CLICK:

                if (now - context.releasedAt >= config.doubleClickTime)
                {
                    context.state = InteractionState::IDLE;

                    if (config.enableClick)
                    {
                        emitEvent(i, ButtonEvent::CLICK);
                    }
                }

                break;

            default:

                break;
        }
    }
}

void EventManager::onPress(uint8_t id)
{
    if (!isValidButton(id))
    {
        return;
    }

    ButtonContext& context = contexts[id];

    switch (context.state)
    {
        case InteractionState::IDLE:

            context.state = InteractionState::PRESSED;
            context.pressedAt = millis();

            emitEvent(id, ButtonEvent::PRESS);

            break;

        case InteractionState::WAIT_SECOND_CLICK:

            context.state = InteractionState::SECOND_PRESSED;
            context.pressedAt = millis();

            emitEvent(id, ButtonEvent::PRESS);

            break;

        default:

            break;
    }
}

void EventManager::onRelease(uint8_t id)
{
    if (!isValidButton(id))
    {
        return;
    }

    ButtonContext& context = contexts[id];
    const InteractionConfig& config = configs[id];

    switch (context.state)
    {
        case InteractionState::PRESSED:

            emitEvent(id, ButtonEvent::RELEASE);

            if (config.enableDoubleClick)
            {
                context.state = InteractionState::WAIT_SECOND_CLICK;
                context.releasedAt = millis();
            }
            else
            {
                context.state = InteractionState::IDLE;

                if (config.enableClick)
                {
                    emitEvent(id, ButtonEvent::CLICK);
                }
            }

            break;

        case InteractionState::LONG_HOLDING:

            context.state = InteractionState::IDLE;

            emitEvent(id, ButtonEvent::RELEASE);

            break;

        case InteractionState::SECOND_PRESSED:

            context.state = InteractionState::IDLE;

            emitEvent(id, ButtonEvent::RELEASE);
            emitEvent(id, ButtonEvent::DOUBLE_CLICK);

            break;

        default:

            break;
    }
}

void EventManager::setListener(EventListener* listener)
{
    this->listener = listener;
}

void EventManager::setInteractionConfig(
    uint8_t id,
    const InteractionConfig& config
)
{
    if (!isValidButton(id))
    {
        return;
    }

    configs[id] = config;
}

bool EventManager::isValidButton(uint8_t id) const
{
    return id < NUM_BUTTONS;
}

void EventManager::emitEvent(uint8_t id, ButtonEvent event)
{
    if (listener != nullptr)
    {
        listener->handle(id, event);
    }
}