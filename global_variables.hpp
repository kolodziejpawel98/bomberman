#pragma once

#if defined(ARDUINO) && ARDUINO >= 100
#include "arduino.h"
#else
#include "WProgram.h"
#endif
#undef max
#undef min
#include <Arduino.h>
#include <vector>
#include <utility>

const uint8_t SCREEN_WIDTH = 2 * 80;
const uint8_t SCREEN_HEIGHT = 2 * 64;

float playerX = 10;
float playerY = 10;
float playerSpeed = 3;
float playerSpeedX = 0;
float playerSpeedY = 0;

namespace playground
{
    struct Rock
    {
        std::pair<unsigned short, unsigned short> coordinates; // top-left point of rock
        unsigned short width, height;

        Rock(const std::pair<unsigned short, unsigned short> coordinates,
             const unsigned short width = 16,
             const unsigned short height = 16)
            : coordinates(coordinates), width(width), height(height) {}

        void drawPlacehodler()
        {
        }
    };
    std::vector<Rock> rocks = {
        Rock(std::make_pair(8, 9)),
        Rock(std::make_pair(40, 9)),
        Rock(std::make_pair(72, 9))};
}