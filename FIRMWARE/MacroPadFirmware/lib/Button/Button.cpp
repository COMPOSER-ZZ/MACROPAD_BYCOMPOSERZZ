#include "Button.h"

Button::Button(uint8_t pin)
{
    this->pin = pin;

    lastState = HIGH;
    currentState = HIGH;
    pressedEvent = false;
    lastDebounceTime = 0;
}

void Button::begin()
{
    pinMode(pin, INPUT_PULLUP);
}

void Button::update()
{
    currentState = digitalRead(pin);

    if (lastState == HIGH && currentState == LOW)
    {
        pressedEvent = true;
    }

    lastState = currentState;
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