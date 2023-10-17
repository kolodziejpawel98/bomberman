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

float player_x = 10;
float player_y = 10;
float player_speed = 7; // zrobic cos zeby przy krotkim nacisnieciu poruszalo sie troche a przydluzszym bardzo

float player_speed_x = 0;
float player_speed_y = 0;
