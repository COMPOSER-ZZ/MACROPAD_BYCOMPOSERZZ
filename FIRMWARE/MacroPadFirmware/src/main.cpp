#include <Arduino.h>
#include "PinDefinitions.h"
#include "Button.h"
#include "EventManager.h"

// ------------------ BOTONES ------------------
Button btn1(Pins::BTN1);
Button btn2(Pins::BTN2);
Button btn3(Pins::BTN3);
Button btn4(Pins::BTN4);
Button btn5(Pins::BTN5);
Button btn6(Pins::BTN6);
Button btn7(Pins::BTN7);
Button btn8(Pins::BTN8);
Button btn9(Pins::BTN9);

Button* buttons[] = {
    &btn1, &btn2, &btn3,
    &btn4, &btn5, &btn6,
    &btn7, &btn8, &btn9
};

EventManager eventManager;

const int NUM_BUTTONS = 9;

// ------------------ SETUP ------------------
void setup() {
    Serial.begin(115200);

    for (int i = 0; i < NUM_BUTTONS; i++) {
        buttons[i]->begin();
    }

    eventManager.begin();

    Serial.println("Macropad listo.");
}

// ------------------ LOOP ------------------
void loop() {

    for (int i = 0; i < NUM_BUTTONS; i++) {
        buttons[i]->update();

        bool state = buttons[i]->isPressed(); 
        // IMPORTANTE: aquí usamos estado estable

        eventManager.registerButton(i, state);
    }

    eventManager.update();

    delay(5);
}