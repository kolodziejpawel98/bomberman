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

    struct Bomb
    {
        Coordinate coordinate;
        Bomb(int x, int y) : coordinate(x, y) {}

        void drawBomb()
        {
            gb.display.drawImage(coordinate.x, coordinate.y, sprite::bomb);
            drawDot(coordinate.x, coordinate.y);
            // collider::drawBlockingElement(coordinate.x, coordinate.y, 1, 1);
        }
    };

    std::shared_ptr<Bomb> bomb = nullptr;

    std::vector<Rock> rocks = {
        Rock(8, 9),
        Rock(40, 9),
        Rock(72, 9),
        Rock(104, 9),
        Rock(136, 9),

        Rock(8, 41),
        Rock(40, 41),
        Rock(72, 41),
        Rock(104, 41),
        Rock(136, 41),

        Rock(8, 73),
        Rock(40, 73),
        Rock(72, 73),
        Rock(104, 73),
        Rock(136, 73),

        Rock(8, 105),
        Rock(40, 105),
        Rock(72, 105),
        Rock(104, 105),
        Rock(136, 105)};

    std::vector<Coordinate> borders = {
        Coordinate(0, 0, 160, 9),
        Coordinate(0, 9, 8, 119),
        Coordinate(8, 121, 152, 7),
        Coordinate(152, 9, 8, 112)};
}