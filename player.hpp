#pragma once

#if defined(ARDUINO) && ARDUINO >= 100
#include "arduino.h"
#else
#include "WProgram.h"
#endif
#undef max
#undef min
#include <Arduino.h>
#include <algorithm>
#include <utility>

class Player
{
public:
    uint8_t x;
    uint8_t y;
    uint8_t stepLength;
    uint8_t stepLengthX;
    uint8_t stepLengthY;
    uint8_t colliderX, colliderY, colliderWidht, colliderHeight;

    Player()
    {
        x = 24;
        y = 25;
        stepLength = 3;
        stepLengthX = 0;
        stepLengthY = 0;
        colliderX, colliderY = 0;
        colliderWidht = 8;
        colliderHeight = 6;
    }

    void updateCollider()
    {
        colliderX = x + 4;
        colliderY = y + 10;
    }
};
