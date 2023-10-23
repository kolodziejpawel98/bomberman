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
#include "coordinate.hpp"

namespace playground
{
    struct Rock
    {
        Coordinate coordinate;

        Rock(int x, int y, int width = 16, int height = 16) : coordinate(x, y, width, height) {}

        void drawPlacehodler()
        {
            gb.display.setColor(RED);
            gb.display.fillRect(coordinate.x, coordinate.y, coordinate.width, coordinate.height);
        }
    };

    std::vector<Rock> rocks = {
        Rock(8, 9),
        Rock(40, 9),
        Rock(72, 9)};
}