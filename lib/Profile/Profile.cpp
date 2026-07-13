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

    InteractionConfig pressOnly;
    pressOnly.enableClick = false;
    pressOnly.enableDoubleClick = false;
    pressOnly.enableLongPress = false;
    pressOnly.enableHoldRepeat = false;

    InteractionConfig clickOnly;
    clickOnly.enableClick = true;
    clickOnly.enableDoubleClick = false;
    clickOnly.enableLongPress = false;
    clickOnly.enableHoldRepeat = false;

    InteractionConfig doubleClickOnly;
    doubleClickOnly.enableClick = false;
    doubleClickOnly.enableDoubleClick = true;
    doubleClickOnly.enableLongPress = false;
    doubleClickOnly.enableHoldRepeat = false;

    InteractionConfig longPressOnly;
    longPressOnly.enableClick = false;
    longPressOnly.enableDoubleClick = false;
    longPressOnly.enableLongPress = true;
    longPressOnly.enableHoldRepeat = false;

    InteractionConfig longPressWithRepeat;
    longPressWithRepeat.enableClick = false;
    longPressWithRepeat.enableDoubleClick = false;
    longPressWithRepeat.enableLongPress = true;
    longPressWithRepeat.enableHoldRepeat = true;

    InteractionConfig clickAndDoubleClick;
    clickAndDoubleClick.enableClick = true;
    clickAndDoubleClick.enableDoubleClick = true;
    clickAndDoubleClick.enableLongPress = false;
    clickAndDoubleClick.enableHoldRepeat = false;

    InteractionConfig clickAndLongPress;
    clickAndLongPress.enableClick = true;
    clickAndLongPress.enableDoubleClick = false;
    clickAndLongPress.enableLongPress = true;
    clickAndLongPress.enableHoldRepeat = false;

    InteractionConfig slowDoubleClick = doubleClickOnly;
    slowDoubleClick.doubleClickTime = 500;

    InteractionConfig slowLongPress = longPressOnly;
    slowLongPress.longPressTime = 1200;

    InteractionConfig fastRepeat = longPressWithRepeat;
    fastRepeat.repeatTime = 50;

    // Configuración de interacción por botón.
    interactionConfigs[0] = pressOnly;
    interactionConfigs[1] = clickOnly;
    interactionConfigs[2] = doubleClickOnly;
    interactionConfigs[3] = longPressOnly;
    interactionConfigs[4] = longPressWithRepeat;
    interactionConfigs[5] = clickAndDoubleClick;
    interactionConfigs[6] = pressOnly;
    interactionConfigs[7] = clickAndLongPress;
    interactionConfigs[8] = slowDoubleClick;
    interactionConfigs[9] = slowLongPress;
    interactionConfigs[10] = fastRepeat;
    interactionConfigs[11] = pressOnly;
    interactionConfigs[12] = clickOnly;

    // BTN 1: PRESS.
    actions[0][eventToIndex(ButtonEvent::PRESS)].type =
        ActionType::KEYBOARD_KEY;
    actions[0][eventToIndex(ButtonEvent::PRESS)].data[0] = '1';

    // BTN 2: CLICK.
    actions[1][eventToIndex(ButtonEvent::CLICK)].type =
        ActionType::KEYBOARD_KEY;
    actions[1][eventToIndex(ButtonEvent::CLICK)].data[0] = '2';

    // BTN 3: DOUBLE_CLICK.
    actions[2][eventToIndex(ButtonEvent::DOUBLE_CLICK)].type =
        ActionType::KEYBOARD_KEY;
    actions[2][eventToIndex(ButtonEvent::DOUBLE_CLICK)].data[0] = '3';

    // BTN 4: LONG_PRESS.
    actions[3][eventToIndex(ButtonEvent::LONG_PRESS)].type =
        ActionType::KEYBOARD_KEY;
    actions[3][eventToIndex(ButtonEvent::LONG_PRESS)].data[0] = '4';

    // BTN 5: LONG_PRESS y HOLD_REPEAT.
    actions[4][eventToIndex(ButtonEvent::LONG_PRESS)].type =
        ActionType::KEYBOARD_KEY;
    actions[4][eventToIndex(ButtonEvent::LONG_PRESS)].data[0] = '5';

    actions[4][eventToIndex(ButtonEvent::HOLD_REPEAT)].type =
        ActionType::KEYBOARD_KEY;
    actions[4][eventToIndex(ButtonEvent::HOLD_REPEAT)].data[0] = 'r';

    // BTN 6: CLICK o DOUBLE_CLICK.
    actions[5][eventToIndex(ButtonEvent::CLICK)].type =
        ActionType::KEYBOARD_KEY;
    actions[5][eventToIndex(ButtonEvent::CLICK)].data[0] = '6';

    actions[5][eventToIndex(ButtonEvent::DOUBLE_CLICK)].type =
        ActionType::KEYBOARD_KEY;
    actions[5][eventToIndex(ButtonEvent::DOUBLE_CLICK)].data[0] = 'D';

    // BTN 7: PRESS y RELEASE.
    actions[6][eventToIndex(ButtonEvent::PRESS)].type =
        ActionType::KEYBOARD_KEY;
    actions[6][eventToIndex(ButtonEvent::PRESS)].data[0] = '7';

    actions[6][eventToIndex(ButtonEvent::RELEASE)].type =
        ActionType::KEYBOARD_KEY;
    actions[6][eventToIndex(ButtonEvent::RELEASE)].data[0] = 'R';

    // BTN 8: CLICK o LONG_PRESS.
    actions[7][eventToIndex(ButtonEvent::CLICK)].type =
        ActionType::KEYBOARD_KEY;
    actions[7][eventToIndex(ButtonEvent::CLICK)].data[0] = '8';

    actions[7][eventToIndex(ButtonEvent::LONG_PRESS)].type =
        ActionType::KEYBOARD_KEY;
    actions[7][eventToIndex(ButtonEvent::LONG_PRESS)].data[0] = 'L';

    // BTN 9: DOUBLE_CLICK lento.
    actions[8][eventToIndex(ButtonEvent::DOUBLE_CLICK)].type =
        ActionType::KEYBOARD_KEY;
    actions[8][eventToIndex(ButtonEvent::DOUBLE_CLICK)].data[0] = '9';

    // BTN 10: LONG_PRESS lento.
    actions[9][eventToIndex(ButtonEvent::LONG_PRESS)].type =
        ActionType::KEYBOARD_KEY;
    actions[9][eventToIndex(ButtonEvent::LONG_PRESS)].data[0] = '0';

    // BTN 11: LONG_PRESS con repetición rápida.
    actions[10][eventToIndex(ButtonEvent::LONG_PRESS)].type =
        ActionType::KEYBOARD_KEY;
    actions[10][eventToIndex(ButtonEvent::LONG_PRESS)].data[0] = 'H';

    actions[10][eventToIndex(ButtonEvent::HOLD_REPEAT)].type =
        ActionType::KEYBOARD_KEY;
    actions[10][eventToIndex(ButtonEvent::HOLD_REPEAT)].data[0] = '+';

    // BTN 12: PRESS y RELEASE.
    actions[11][eventToIndex(ButtonEvent::PRESS)].type =
        ActionType::KEYBOARD_KEY;
    actions[11][eventToIndex(ButtonEvent::PRESS)].data[0] = 'A';

    actions[11][eventToIndex(ButtonEvent::RELEASE)].type =
        ActionType::KEYBOARD_KEY;
    actions[11][eventToIndex(ButtonEvent::RELEASE)].data[0] = 'a';

    // BTN 13: CLICK.
    actions[12][eventToIndex(ButtonEvent::CLICK)].type =
        ActionType::KEYBOARD_KEY;
    actions[12][eventToIndex(ButtonEvent::CLICK)].data[0] = 'B';

    // BTN 14 y BTN 15 quedan sin acción intencionalmente.
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