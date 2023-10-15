#pragma once

#if defined(ARDUINO) && ARDUINO >= 100
#include "arduino.h"
#else
#include "WProgram.h"
#endif
#undef max
#undef min
#include <Arduino.h>

const uint8_t screen_width = 80;
const uint8_t screen_height = 64;

float player_x = 10;
float player_y = 10;
float player_speed = 7;

float player_speed_x = 0;
float player_speed_y = 0;
