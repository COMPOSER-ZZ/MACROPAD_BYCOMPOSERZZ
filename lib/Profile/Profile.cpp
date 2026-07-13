#include "Profile.h"

void Profile::begin()
{
    for (uint8_t button = 0; button < NUM_BUTTONS; button++)
    {
        interactionConfigs[button] = InteractionConfig();

        for (uint8_t event = 0; event < NUM_EVENTS; event++)
        {
            actions[button][event] = Action();
        }
    }

    InteractionConfig instantKeyConfig;
    instantKeyConfig.enableClick = false;
    instantKeyConfig.enableDoubleClick = false;
    instantKeyConfig.enableLongPress = false;
    instantKeyConfig.enableHoldRepeat = false;

    // Botones 1, 2 y 3: teclas instantáneas.
    interactionConfigs[0] = instantKeyConfig;
    interactionConfigs[1] = instantKeyConfig;
    interactionConfigs[2] = instantKeyConfig;

    actions[0][eventToIndex(ButtonEvent::PRESS)].type =
        ActionType::KEYBOARD_KEY;
    actions[0][eventToIndex(ButtonEvent::PRESS)].data[0] = '1';

    actions[1][eventToIndex(ButtonEvent::PRESS)].type =
        ActionType::KEYBOARD_KEY;
    actions[1][eventToIndex(ButtonEvent::PRESS)].data[0] = '4';

    actions[2][eventToIndex(ButtonEvent::PRESS)].type =
        ActionType::KEYBOARD_KEY;
    actions[2][eventToIndex(ButtonEvent::PRESS)].data[0] = '7';
}

Action Profile::getAction(uint8_t buttonID, ButtonEvent event) const
{
    if (!isValidButton(buttonID))
    {
        return Action();
    }

    return actions[buttonID][eventToIndex(event)];
}

InteractionConfig Profile::getInteractionConfig(uint8_t buttonID) const
{
    if (!isValidButton(buttonID))
    {
        return InteractionConfig();
    }

    return interactionConfigs[buttonID];
}

uint8_t Profile::eventToIndex(ButtonEvent event) const
{
    return static_cast<uint8_t>(event);
}

bool Profile::isValidButton(uint8_t buttonID) const
{
    return buttonID < NUM_BUTTONS;
}