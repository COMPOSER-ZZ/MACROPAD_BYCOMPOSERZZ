#include "Profile.h"

void Profile::begin()
{
    // Botón 1 -> tecla '1'
    actions[0].type = ActionType::KEYBOARD_KEY;
    actions[0].data[0] = '1';

    // Botón 2 -> tecla '4'
    actions[1].type = ActionType::KEYBOARD_KEY;
    actions[1].data[0] = '4';

    // Botón 3 -> tecla '7'
    actions[2].type = ActionType::KEYBOARD_KEY;
    actions[2].data[0] = '7';

    // Los demás se llenarán después.
}

Action Profile::getAction(uint8_t buttonID)
{
    return actions[buttonID];
}