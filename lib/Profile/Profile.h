#ifndef PROFILE_H
#define PROFILE_H

#include <Arduino.h>
#include "Action.h"

class Profile
{
public:

    void begin();

    Action getAction(uint8_t buttonID);

private:

    Action actions[15];

};

#endif