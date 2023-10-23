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
#include "input_handler.hpp"
#include "global_variables.hpp"

void playerMove()
{
    playerSpeedX = 0;
    playerSpeedY = 0;
    buttonListener();
    playerX += playerSpeedX;
    playerY += playerSpeedY;
    updatePlayerContactPoints();
}