#include "Profile.h"

namespace
{
    void setKeyAction(Action& action, KeyCode key)
    {
        action.type = ActionType::KEYBOARD_KEY;
        action.key = key;
    }
}

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
    setKeyAction(
        actions[0][eventToIndex(ButtonEvent::PRESS)],
        KeyCode::NUM_1
    );

    // BTN 2: CLICK.
    setKeyAction(
        actions[1][eventToIndex(ButtonEvent::CLICK)],
        KeyCode::NUM_2
    );

    // BTN 3: DOUBLE_CLICK.
    setKeyAction(
        actions[2][eventToIndex(ButtonEvent::DOUBLE_CLICK)],
        KeyCode::NUM_3
    );

    // BTN 4: LONG_PRESS.
    setKeyAction(
        actions[3][eventToIndex(ButtonEvent::LONG_PRESS)],
        KeyCode::NUM_4
    );

    // BTN 5: LONG_PRESS y HOLD_REPEAT.
    setKeyAction(
        actions[4][eventToIndex(ButtonEvent::LONG_PRESS)],
        KeyCode::NUM_5
    );

    setKeyAction(
        actions[4][eventToIndex(ButtonEvent::HOLD_REPEAT)],
        KeyCode::R
    );

    // BTN 6: CLICK o DOUBLE_CLICK.
    setKeyAction(
        actions[5][eventToIndex(ButtonEvent::CLICK)],
        KeyCode::NUM_6
    );

    setKeyAction(
        actions[5][eventToIndex(ButtonEvent::DOUBLE_CLICK)],
        KeyCode::D
    );

    // BTN 7: PRESS y RELEASE.
    setKeyAction(
        actions[6][eventToIndex(ButtonEvent::PRESS)],
        KeyCode::NUM_7
    );

    setKeyAction(
        actions[6][eventToIndex(ButtonEvent::RELEASE)],
        KeyCode::R
    );

    // BTN 8: CLICK o LONG_PRESS.
    setKeyAction(
        actions[7][eventToIndex(ButtonEvent::CLICK)],
        KeyCode::NUM_8
    );

    setKeyAction(
        actions[7][eventToIndex(ButtonEvent::LONG_PRESS)],
        KeyCode::L
    );

    // BTN 9: DOUBLE_CLICK lento.
    setKeyAction(
        actions[8][eventToIndex(ButtonEvent::DOUBLE_CLICK)],
        KeyCode::NUM_9
    );

    // BTN 10: LONG_PRESS lento.
    setKeyAction(
        actions[9][eventToIndex(ButtonEvent::LONG_PRESS)],
        KeyCode::NUM_0
    );

    // BTN 11: LONG_PRESS con repetición rápida.
    setKeyAction(
        actions[10][eventToIndex(ButtonEvent::LONG_PRESS)],
        KeyCode::H
    );

    setKeyAction(
        actions[10][eventToIndex(ButtonEvent::HOLD_REPEAT)],
        KeyCode::H
    );

    // BTN 12: PRESS y RELEASE.
    setKeyAction(
        actions[11][eventToIndex(ButtonEvent::PRESS)],
        KeyCode::A
    );

    setKeyAction(
        actions[11][eventToIndex(ButtonEvent::RELEASE)],
        KeyCode::C
    );

    // BTN 13: CLICK.
    setKeyAction(
        actions[12][eventToIndex(ButtonEvent::CLICK)],
        KeyCode::B
    );

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