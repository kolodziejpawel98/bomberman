#pragma once

#if defined(ARDUINO) && ARDUINO >= 100
#include "arduino.h"
#else
#include "WProgram.h"
#endif
#undef max
#undef min
#include <Arduino.h>

const uint8_t SCREEN_WIDTH = 2 * 80;
const uint8_t SCREEN_HEIGHT = 2 * 64;

float playerX = 10;
float playerY = 10;
float playerSpeed = 3;
float playerSpeedX = 0;
float playerSpeedY = 0;
