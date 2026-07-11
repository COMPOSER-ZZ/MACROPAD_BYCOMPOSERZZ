#include "Button.h"

Button::Button(uint8_t pin)
{
    this->pin = pin;

    stableState = HIGH;
    lastReading = HIGH;

    pressedEvent = false;
    releasedEvent = false;

    lastDebounceTime = 0;
}

void Button::begin()
{
    pinMode(pin, INPUT_PULLUP);
}

void Button::update()
{
    bool reading = digitalRead(pin);

    // Si cambió la lectura física, reiniciamos el temporizador
    if (reading != lastReading)
    {
        lastDebounceTime = millis();
        lastReading = reading;
    }

    // Si la lectura permanece estable durante el tiempo de debounce
    if ((millis() - lastDebounceTime) >= debounceDelay)
    {
        // Solo actuamos si el estado estable realmente cambió
        if (stableState != reading)
        {
            stableState = reading;

            if (stableState == LOW)
            {
                pressedEvent = true;
            }
            else
            {
                releasedEvent = true;
            }
        }
    }
}

bool Button::isPressed()
{
    if (pressedEvent)
    {
        pressedEvent = false;
        return true;
    }

    return false;
}

bool Button::isReleased()
{
    if (releasedEvent)
    {
        releasedEvent = false;
        return true;
    }

    return false;
}