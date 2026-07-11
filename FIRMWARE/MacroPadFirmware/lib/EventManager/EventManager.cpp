#include "EventManager.h"

void EventManager::begin() {
    for (int i = 0; i < NUM_BUTTONS; i++) {
        lastState[i] = false;
        pressTime[i] = 0;
        isHeld[i] = false;
    }
}

void EventManager::registerButton(int id, bool state) {

    unsigned long now = millis();

    // detect rising edge (pressed)
    if (state && !lastState[id]) {
        pressTime[id] = now;
        isHeld[id] = false;
        onPress(id);
    }

    // detect falling edge (released)
    if (!state && lastState[id]) {
        onRelease(id);
        isHeld[id] = false;
    }

    // long press detection
    if (state && !isHeld[id]) {
        if (now - pressTime[id] >= LONG_PRESS_MS) {
            isHeld[id] = true;
            Serial.print("BTN ");
            Serial.print(id + 1);
            Serial.println(" LONG PRESS");
        }
    }

    lastState[id] = state;
}

void EventManager::update() {
    // reservado para futuras expansiones (double click, combos, etc.)
}

void EventManager::onPress(int id) {
    Serial.print("BTN ");
    Serial.print(id + 1);
    Serial.println(" DOWN");
}

void EventManager::onRelease(int id) {
    Serial.print("BTN ");
    Serial.print(id + 1);
    Serial.println(" UP");
}