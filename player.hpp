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
    int playerX;
    int playerY;
    int playerSpeed;
    int playerSpeedX;
    int playerSpeedY;

    Player()
    {
        playerX = 0;
        playerY = 0;
        playerSpeed = 3;
        playerSpeedX = 0;
        playerSpeedY = 0;
    }
};
