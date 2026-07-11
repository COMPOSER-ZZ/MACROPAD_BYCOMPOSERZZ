#ifndef BUTTON_H
#define BUTTON_H

#include <Arduino.h>

class Button
{
private:
    uint8_t pin;

    bool stableState;      // Estado confirmado
    bool lastReading;      // Última lectura física

    bool pressedEvent;
    bool releasedEvent;

    unsigned long lastDebounceTime;
    static const unsigned long debounceDelay = 20;

public:
    Button(uint8_t pin);

    void begin();
    void update();

    bool isPressed();
    bool isReleased();
};

#endif