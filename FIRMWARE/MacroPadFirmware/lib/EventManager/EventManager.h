#ifndef EVENT_MANAGER_H
#define EVENT_MANAGER_H

#include <Arduino.h>

class EventManager {
public:
    void begin();
    void update();

    void registerButton(int id, bool state);

    // callbacks
    void onPress(int id);
    void onRelease(int id);

private:
    static const int NUM_BUTTONS = 9;

    bool lastState[NUM_BUTTONS];
    unsigned long pressTime[NUM_BUTTONS];
    bool isHeld[NUM_BUTTONS];

    const unsigned long LONG_PRESS_MS = 600;
};

#endif