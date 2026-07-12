#ifndef KEY_CODE_H
#define KEY_CODE_H

#include <Arduino.h>


  enum class KeyCode : uint16_t
{
    //========================
    // ESPECIAL
    //========================

    NONE = 0,

    //========================
    // LETRAS (1-26)
    //========================

    A = 1,
    B = 2,
    C = 3,
    D = 4,
    E = 5,
    F = 6,
    G = 7,
    H = 8,
    I = 9,
    J = 10,
    K = 11,
    L = 12,
    M = 13,
    N = 14,
    O = 15,
    P = 16,
    Q = 17,
    R = 18,
    S = 19,
    T = 20,
    U = 21,
    V = 22,
    W = 23,
    X = 24,
    Y = 25,
    Z = 26,

    //========================
    // NÚMEROS (27-36)
    //========================

    NUM_0 = 27,
    NUM_1 = 28,
    NUM_2 = 29,
    NUM_3 = 30,
    NUM_4 = 31,
    NUM_5 = 32,
    NUM_6 = 33,
    NUM_7 = 34,
    NUM_8 = 35,
    NUM_9 = 36,

    //========================
    // TECLAS PRINCIPALES (200)
    //========================

    ENTER      = 200,
    ESC        = 201,
    TAB        = 202,
    SPACE      = 203,
    BACKSPACE  = 204,
    CAPS_LOCK  = 205,

    //========================
    // NAVEGACIÓN (210)
    //========================

    INSERT      = 210,
    DELETE_KEY  = 211,
    HOME        = 212,
    END         = 213,
    PAGE_UP     = 214,
    PAGE_DOWN   = 215,

    ARROW_UP    = 216,
    ARROW_DOWN  = 217,
    ARROW_LEFT  = 218,
    ARROW_RIGHT = 219,

    //========================
    // MODIFICADORES (400)
    //========================

    LEFT_CTRL   = 400,
    LEFT_SHIFT  = 401,
    LEFT_ALT    = 402,
    LEFT_GUI    = 403,

    RIGHT_CTRL  = 404,
    RIGHT_SHIFT = 405,
    RIGHT_ALT   = 406,
    RIGHT_GUI   = 407,

    //========================
    // FUNCIONES (300)
    //========================

    F1  = 300,
    F2  = 301,
    F3  = 302,
    F4  = 303,
    F5  = 304,
    F6  = 305,
    F7  = 306,
    F8  = 307,
    F9  = 308,
    F10 = 309,
    F11 = 310,
    F12 = 311,
    F13 = 312,
    F14 = 313,
    F15 = 314,
    F16 = 315,
    F17 = 316,
    F18 = 317,
    F19 = 318,
    F20 = 319,
    F21 = 320,
    F22 = 321,
    F23 = 322,
    F24 = 323
};


#endif