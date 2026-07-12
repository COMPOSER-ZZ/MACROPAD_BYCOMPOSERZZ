#ifndef ENCYKEYPEDIA_H
#define ENCYKEYPEDIA_H

#include <Arduino.h>

#include "KeyCode.h"
#include "KeyInfo.h"

class EncyKEYpedia
{
public:

    static const char* getName(KeyCode key);

    static const KeyInfo* getInfo(KeyCode key);

};

#endif