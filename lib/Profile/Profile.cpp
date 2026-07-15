#include "Profile.h"

namespace
{
    Action makeKeyAction(KeyCode key)
    {
        Action action;

        action.type = ActionType::KEYBOARD_KEY;
        action.keys[0] = key;
        action.keyCount = 1;

        return action;
    }

    void setKeyAction(Action& action, KeyCode key)
    {
        action = makeKeyAction(key);
    }

    void setCombinationAction(
        Action& action,
        const KeyCode* keys,
        uint8_t keyCount
    )
    {
        action = Action();

        if (
            keys == nullptr ||
            keyCount == 0 ||
            keyCount > Action::MAX_KEYS
        )
        {
            return;
        }

        action.type = ActionType::KEYBOARD_COMBINATION;
        action.keyCount = keyCount;

        for (uint8_t i = 0; i < keyCount; i++)
        {
            action.keys[i] = keys[i];
        }
    }

    void setMacroAction(Action& action, uint8_t macroId)
    {
        action = Action();
        action.type = ActionType::MACRO;
        action.macroId = macroId;
    }

    const MacroStep helloMacroSteps[] =
    {
        { makeKeyAction(KeyCode::H), 120 },
        { makeKeyAction(KeyCode::O), 120 },
        { makeKeyAction(KeyCode::L), 120 },
        { makeKeyAction(KeyCode::A), 120 },
        { makeKeyAction(KeyCode::ENTER), 0 }
    };
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

    macros[0].steps = helloMacroSteps;
    macros[0].stepCount =
        sizeof(helloMacroSteps) / sizeof(helloMacroSteps[0]);

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
    interactionConfigs[4] = pressOnly;
    interactionConfigs[5] = clickAndDoubleClick;
    interactionConfigs[6] = pressOnly;
    interactionConfigs[7] = clickAndLongPress;
    interactionConfigs[8] = slowDoubleClick;
    interactionConfigs[9] = slowLongPress;
    interactionConfigs[10] = fastRepeat;
    interactionConfigs[11] = pressOnly;
    interactionConfigs[12] = clickOnly;
    interactionConfigs[13] = pressOnly;
    interactionConfigs[14] = pressOnly;

    // BTN1: PRESS.
    setKeyAction(
        actions[0][eventToIndex(ButtonEvent::PRESS)],
        KeyCode::NUM_1
    );

    // BTN2: CLICK.
    setKeyAction(
        actions[1][eventToIndex(ButtonEvent::CLICK)],
        KeyCode::NUM_2
    );

    // BTN3: DOUBLE_CLICK.
    setKeyAction(
        actions[2][eventToIndex(ButtonEvent::DOUBLE_CLICK)],
        KeyCode::NUM_3
    );

    // BTN4: LONG_PRESS.
    setKeyAction(
        actions[3][eventToIndex(ButtonEvent::LONG_PRESS)],
        KeyCode::NUM_4
    );

    // BTN5: Ctrl + Win + Flecha izquierda.
    const KeyCode switchDesktopLeft[] =
    {
        KeyCode::LEFT_CTRL,
        KeyCode::LEFT_GUI,
        KeyCode::ARROW_LEFT
    };

    setCombinationAction(
        actions[4][eventToIndex(ButtonEvent::PRESS)],
        switchDesktopLeft,
        sizeof(switchDesktopLeft) / sizeof(switchDesktopLeft[0])
    );

    // BTN6: CLICK o DOUBLE_CLICK.
    setKeyAction(
        actions[5][eventToIndex(ButtonEvent::CLICK)],
        KeyCode::NUM_6
    );

    setKeyAction(
        actions[5][eventToIndex(ButtonEvent::DOUBLE_CLICK)],
        KeyCode::D
    );

    // BTN7: PRESS y RELEASE.
    setKeyAction(
        actions[6][eventToIndex(ButtonEvent::PRESS)],
        KeyCode::NUM_7
    );

    setKeyAction(
        actions[6][eventToIndex(ButtonEvent::RELEASE)],
        KeyCode::R
    );

    // BTN8: CLICK o LONG_PRESS.
    setKeyAction(
        actions[7][eventToIndex(ButtonEvent::CLICK)],
        KeyCode::NUM_8
    );

    setKeyAction(
        actions[7][eventToIndex(ButtonEvent::LONG_PRESS)],
        KeyCode::L
    );

    // BTN9: DOUBLE_CLICK lento.
    setKeyAction(
        actions[8][eventToIndex(ButtonEvent::DOUBLE_CLICK)],
        KeyCode::NUM_9
    );

    // BTN10: LONG_PRESS lento.
    setKeyAction(
        actions[9][eventToIndex(ButtonEvent::LONG_PRESS)],
        KeyCode::NUM_0
    );

    // BTN11: LONG_PRESS con repetición rápida.
    setKeyAction(
        actions[10][eventToIndex(ButtonEvent::LONG_PRESS)],
        KeyCode::H
    );

    setKeyAction(
        actions[10][eventToIndex(ButtonEvent::HOLD_REPEAT)],
        KeyCode::H
    );

    // BTN12: PRESS y RELEASE.
    setKeyAction(
        actions[11][eventToIndex(ButtonEvent::PRESS)],
        KeyCode::A
    );

    setKeyAction(
        actions[11][eventToIndex(ButtonEvent::RELEASE)],
        KeyCode::C
    );

    // BTN13: CLICK.
    setKeyAction(
        actions[12][eventToIndex(ButtonEvent::CLICK)],
        KeyCode::B
    );

    // BTN14: macro "hola" + Enter.
    setMacroAction(
        actions[13][eventToIndex(ButtonEvent::PRESS)],
        0
    );

    // BTN15: Ctrl + Win + Flecha derecha.
    const KeyCode switchDesktopRight[] =
    {
        KeyCode::LEFT_CTRL,
        KeyCode::LEFT_GUI,
        KeyCode::ARROW_RIGHT
    };

    setCombinationAction(
        actions[14][eventToIndex(ButtonEvent::PRESS)],
        switchDesktopRight,
        sizeof(switchDesktopRight) / sizeof(switchDesktopRight[0])
    );
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

const Macro* Profile::getMacro(uint8_t macroId) const
{
    if (macroId >= NUM_MACROS)
    {
        return nullptr;
    }

    return &macros[macroId];
}

uint8_t Profile::eventToIndex(ButtonEvent event) const
{
    return static_cast<uint8_t>(event);
}

bool Profile::isValidButton(uint8_t buttonID) const
{
    return buttonID < NUM_BUTTONS;
}