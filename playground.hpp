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
            gb.display.setColor(RED);
            gb.display.fillRect(coordinates.first, coordinates.second, width, height);
        }
    };
    std::vector<Rock> rocks = {
        Rock(std::make_pair(8, 9)),
        Rock(std::make_pair(40, 9)),
        Rock(std::make_pair(72, 9))};
}