#include "EncyKEYpedia.h"

static const KeyInfo keyDatabase[] =
{

    {
        KeyCode::A,
        "A",
        KeyCategory::LETTER,
        0,
        false,
        true
    },

    {
        KeyCode::B,
        "B",
        KeyCategory::LETTER,
        0,
        false,
        true
    },

    {
        KeyCode::C,
        "C",
        KeyCategory::LETTER,
        0,
        false,
        true
    },

    {
        KeyCode::D,
        "D",
        KeyCategory::LETTER,
        0,
        false,
        true
    }

};

const KeyInfo* EncyKEYpedia::getInfo(KeyCode key)
{

    for(uint16_t i = 0; i < sizeof(keyDatabase)/sizeof(keyDatabase[0]); i++)
    {

        if(keyDatabase[i].code == key)
        {

            return &keyDatabase[i];

        }

    }

    return nullptr;

}

const char* EncyKEYpedia::getName(KeyCode key)
{

    const KeyInfo* info = getInfo(key);

    if(info != nullptr)
    {

        return info->name;

    }

    return "UNKNOWN";

}


