#include "ActionExecutor.h"

#include "EncyKEYpedia.h"

namespace
{
    const KeyInfo* getKeyInfo(KeyCode key)
    {
        return EncyKEYpedia::getInfo(key);
    }

    bool isModifier(KeyCode key)
    {
        const KeyInfo* keyInfo = getKeyInfo(key);

        return keyInfo != nullptr &&
               keyInfo->category == KeyCategory::MODIFIER;
    }

    bool pressKey(USBHIDKeyboard* keyboard, KeyCode key)
    {
        const KeyInfo* keyInfo = getKeyInfo(key);

        if (keyInfo == nullptr || keyInfo->hidCode == 0)
        {
            return false;
        }

        return keyboard->pressRaw(keyInfo->hidCode) != 0;
    }

    void releaseKey(USBHIDKeyboard* keyboard, KeyCode key)
    {
        const KeyInfo* keyInfo = getKeyInfo(key);

        if (keyInfo == nullptr || keyInfo->hidCode == 0)
        {
            return;
        }

        keyboard->releaseRaw(keyInfo->hidCode);
    }
}

void ActionExecutor::setKeyboard(USBHIDKeyboard* keyboard)
{
    this->keyboard = keyboard;
}

void ActionExecutor::execute(const Action& action)
{
    if (keyboard == nullptr)
    {
        return;
    }

    if (action.keyCount == 0 || action.keyCount > Action::MAX_KEYS)
    {
        return;
    }

    switch (action.type)
    {
        case ActionType::KEYBOARD_KEY:

            if (action.keyCount != 1)
            {
                return;
            }

            pressKey(keyboard, action.keys[0]);
            releaseKey(keyboard, action.keys[0]);

            break;

        case ActionType::KEYBOARD_COMBINATION:

            // Primero se presionan los modificadores:
            // Ctrl, Shift, Alt y GUI/Win.
            for (uint8_t i = 0; i < action.keyCount; i++)
            {
                if (isModifier(action.keys[i]))
                {
                    pressKey(keyboard, action.keys[i]);
                }
            }

            // Después se presionan las teclas normales.
            for (uint8_t i = 0; i < action.keyCount; i++)
            {
                if (!isModifier(action.keys[i]))
                {
                    pressKey(keyboard, action.keys[i]);
                }
            }

            // Primero se liberan las teclas normales.
            for (int8_t i = action.keyCount - 1; i >= 0; i--)
            {
                if (!isModifier(action.keys[i]))
                {
                    releaseKey(keyboard, action.keys[i]);
                }
            }

            // Por último se liberan los modificadores.
            for (int8_t i = action.keyCount - 1; i >= 0; i--)
            {
                if (isModifier(action.keys[i]))
                {
                    releaseKey(keyboard, action.keys[i]);
                }
            }

            // Protección adicional: ningún modificador debe quedar activo.
            keyboard->releaseAll();

            break;

        default:

            break;
    }
}