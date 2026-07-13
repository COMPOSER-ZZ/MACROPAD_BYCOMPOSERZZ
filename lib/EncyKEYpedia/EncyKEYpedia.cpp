#include "EncyKEYpedia.h"

static const KeyInfo keyDatabase[] =
{
    // Especial
    { KeyCode::NONE, "NONE", KeyCategory::SYSTEM, 0x00, false, false },

    // Letras: USB HID 0x04 a 0x1D
    { KeyCode::A, "A", KeyCategory::LETTER, 0x04, false, true },
    { KeyCode::B, "B", KeyCategory::LETTER, 0x05, false, true },
    { KeyCode::C, "C", KeyCategory::LETTER, 0x06, false, true },
    { KeyCode::D, "D", KeyCategory::LETTER, 0x07, false, true },
    { KeyCode::E, "E", KeyCategory::LETTER, 0x08, false, true },
    { KeyCode::F, "F", KeyCategory::LETTER, 0x09, false, true },
    { KeyCode::G, "G", KeyCategory::LETTER, 0x0A, false, true },
    { KeyCode::H, "H", KeyCategory::LETTER, 0x0B, false, true },
    { KeyCode::I, "I", KeyCategory::LETTER, 0x0C, false, true },
    { KeyCode::J, "J", KeyCategory::LETTER, 0x0D, false, true },
    { KeyCode::K, "K", KeyCategory::LETTER, 0x0E, false, true },
    { KeyCode::L, "L", KeyCategory::LETTER, 0x0F, false, true },
    { KeyCode::M, "M", KeyCategory::LETTER, 0x10, false, true },
    { KeyCode::N, "N", KeyCategory::LETTER, 0x11, false, true },
    { KeyCode::O, "O", KeyCategory::LETTER, 0x12, false, true },
    { KeyCode::P, "P", KeyCategory::LETTER, 0x13, false, true },
    { KeyCode::Q, "Q", KeyCategory::LETTER, 0x14, false, true },
    { KeyCode::R, "R", KeyCategory::LETTER, 0x15, false, true },
    { KeyCode::S, "S", KeyCategory::LETTER, 0x16, false, true },
    { KeyCode::T, "T", KeyCategory::LETTER, 0x17, false, true },
    { KeyCode::U, "U", KeyCategory::LETTER, 0x18, false, true },
    { KeyCode::V, "V", KeyCategory::LETTER, 0x19, false, true },
    { KeyCode::W, "W", KeyCategory::LETTER, 0x1A, false, true },
    { KeyCode::X, "X", KeyCategory::LETTER, 0x1B, false, true },
    { KeyCode::Y, "Y", KeyCategory::LETTER, 0x1C, false, true },
    { KeyCode::Z, "Z", KeyCategory::LETTER, 0x1D, false, true },

    // Números de la fila superior
    { KeyCode::NUM_1, "1", KeyCategory::NUMBER, 0x1E, false, true },
    { KeyCode::NUM_2, "2", KeyCategory::NUMBER, 0x1F, false, true },
    { KeyCode::NUM_3, "3", KeyCategory::NUMBER, 0x20, false, true },
    { KeyCode::NUM_4, "4", KeyCategory::NUMBER, 0x21, false, true },
    { KeyCode::NUM_5, "5", KeyCategory::NUMBER, 0x22, false, true },
    { KeyCode::NUM_6, "6", KeyCategory::NUMBER, 0x23, false, true },
    { KeyCode::NUM_7, "7", KeyCategory::NUMBER, 0x24, false, true },
    { KeyCode::NUM_8, "8", KeyCategory::NUMBER, 0x25, false, true },
    { KeyCode::NUM_9, "9", KeyCategory::NUMBER, 0x26, false, true },
    { KeyCode::NUM_0, "0", KeyCategory::NUMBER, 0x27, false, true },

    // Teclas principales
    { KeyCode::ENTER, "ENTER", KeyCategory::SYSTEM, 0x28, false, false },
    { KeyCode::ESC, "ESC", KeyCategory::SYSTEM, 0x29, false, false },
    { KeyCode::BACKSPACE, "BACKSPACE", KeyCategory::SYSTEM, 0x2A, false, false },
    { KeyCode::TAB, "TAB", KeyCategory::SYSTEM, 0x2B, false, false },
    { KeyCode::SPACE, "SPACE", KeyCategory::SYSTEM, 0x2C, false, true },
    { KeyCode::CAPS_LOCK, "CAPS LOCK", KeyCategory::SYSTEM, 0x39, false, false },

    // Navegación
    { KeyCode::INSERT, "INSERT", KeyCategory::NAVIGATION, 0x49, false, false },
    { KeyCode::DELETE_KEY, "DELETE", KeyCategory::NAVIGATION, 0x4C, false, false },
    { KeyCode::HOME, "HOME", KeyCategory::NAVIGATION, 0x4A, false, false },
    { KeyCode::END, "END", KeyCategory::NAVIGATION, 0x4D, false, false },
    { KeyCode::PAGE_UP, "PAGE UP", KeyCategory::NAVIGATION, 0x4B, false, false },
    { KeyCode::PAGE_DOWN, "PAGE DOWN", KeyCategory::NAVIGATION, 0x4E, false, false },
    { KeyCode::ARROW_UP, "ARROW UP", KeyCategory::NAVIGATION, 0x52, false, false },
    { KeyCode::ARROW_DOWN, "ARROW DOWN", KeyCategory::NAVIGATION, 0x51, false, false },
    { KeyCode::ARROW_LEFT, "ARROW LEFT", KeyCategory::NAVIGATION, 0x50, false, false },
    { KeyCode::ARROW_RIGHT, "ARROW RIGHT", KeyCategory::NAVIGATION, 0x4F, false, false },

    // Modificadores
    { KeyCode::LEFT_CTRL, "LEFT CTRL", KeyCategory::MODIFIER, 0xE0, false, false },
    { KeyCode::LEFT_SHIFT, "LEFT SHIFT", KeyCategory::MODIFIER, 0xE1, false, false },
    { KeyCode::LEFT_ALT, "LEFT ALT", KeyCategory::MODIFIER, 0xE2, false, false },
    { KeyCode::LEFT_GUI, "LEFT GUI", KeyCategory::MODIFIER, 0xE3, false, false },
    { KeyCode::RIGHT_CTRL, "RIGHT CTRL", KeyCategory::MODIFIER, 0xE4, false, false },
    { KeyCode::RIGHT_SHIFT, "RIGHT SHIFT", KeyCategory::MODIFIER, 0xE5, false, false },
    { KeyCode::RIGHT_ALT, "RIGHT ALT", KeyCategory::MODIFIER, 0xE6, false, false },
    { KeyCode::RIGHT_GUI, "RIGHT GUI", KeyCategory::MODIFIER, 0xE7, false, false },

    // Teclas de función
    { KeyCode::F1, "F1", KeyCategory::FUNCTION, 0x3A, false, false },
    { KeyCode::F2, "F2", KeyCategory::FUNCTION, 0x3B, false, false },
    { KeyCode::F3, "F3", KeyCategory::FUNCTION, 0x3C, false, false },
    { KeyCode::F4, "F4", KeyCategory::FUNCTION, 0x3D, false, false },
    { KeyCode::F5, "F5", KeyCategory::FUNCTION, 0x3E, false, false },
    { KeyCode::F6, "F6", KeyCategory::FUNCTION, 0x3F, false, false },
    { KeyCode::F7, "F7", KeyCategory::FUNCTION, 0x40, false, false },
    { KeyCode::F8, "F8", KeyCategory::FUNCTION, 0x41, false, false },
    { KeyCode::F9, "F9", KeyCategory::FUNCTION, 0x42, false, false },
    { KeyCode::F10, "F10", KeyCategory::FUNCTION, 0x43, false, false },
    { KeyCode::F11, "F11", KeyCategory::FUNCTION, 0x44, false, false },
    { KeyCode::F12, "F12", KeyCategory::FUNCTION, 0x45, false, false },
    { KeyCode::F13, "F13", KeyCategory::FUNCTION, 0x68, false, false },
    { KeyCode::F14, "F14", KeyCategory::FUNCTION, 0x69, false, false },
    { KeyCode::F15, "F15", KeyCategory::FUNCTION, 0x6A, false, false },
    { KeyCode::F16, "F16", KeyCategory::FUNCTION, 0x6B, false, false },
    { KeyCode::F17, "F17", KeyCategory::FUNCTION, 0x6C, false, false },
    { KeyCode::F18, "F18", KeyCategory::FUNCTION, 0x6D, false, false },
    { KeyCode::F19, "F19", KeyCategory::FUNCTION, 0x6E, false, false },
    { KeyCode::F20, "F20", KeyCategory::FUNCTION, 0x6F, false, false },
    { KeyCode::F21, "F21", KeyCategory::FUNCTION, 0x70, false, false },
    { KeyCode::F22, "F22", KeyCategory::FUNCTION, 0x71, false, false },
    { KeyCode::F23, "F23", KeyCategory::FUNCTION, 0x72, false, false },
    { KeyCode::F24, "F24", KeyCategory::FUNCTION, 0x73, false, false }
};

const KeyInfo* EncyKEYpedia::getInfo(KeyCode key)
{
    const uint16_t keyCount =
        sizeof(keyDatabase) / sizeof(keyDatabase[0]);

    for (uint16_t i = 0; i < keyCount; i++)
    {
        if (keyDatabase[i].code == key)
        {
            return &keyDatabase[i];
        }
    }

    return nullptr;
}

const char* EncyKEYpedia::getName(KeyCode key)
{
    const KeyInfo* info = getInfo(key);

    if (info != nullptr)
    {
        return info->name;
    }

    return "UNKNOWN";
}