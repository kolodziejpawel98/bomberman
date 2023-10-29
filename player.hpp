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
    int x; // remove player from variable names
    int y;
    int stepLength;
    int stepLengthX;
    int stepLengthY;
    int colliderX, colliderY, colliderWidht, colliderHeight;

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
