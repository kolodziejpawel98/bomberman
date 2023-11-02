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

    struct Cell
    {
        Coordinate coordinate;

        Cell(int x, int y, int width = 16, int height = 16) : coordinate(x, y, width, height) {}

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

    std::vector<Cell> walkableCells = {

        Cell(24, 9), //?????? shared_ptr???
        Cell(56, 9),
        Cell(88, 9),
        Cell(120, 9),

        Cell(8, 25),
        Cell(24, 25),
        Cell(40, 25),
        Cell(56, 25),
        Cell(72, 25),
        Cell(88, 25),
        Cell(104, 25),
        Cell(120, 25),
        Cell(136, 25),

        Cell(24, 41),
        Cell(56, 41),
        Cell(88, 41),
        Cell(120, 41),

        Cell(8, 57),
        Cell(24, 57),
        Cell(40, 57),
        Cell(56, 57),
        Cell(72, 57),
        Cell(88, 57),
        Cell(104, 57),
        Cell(120, 57),
        Cell(136, 57),

        Cell(24, 73),
        Cell(56, 73),
        Cell(88, 73),
        Cell(120, 73),

        Cell(8, 89),
        Cell(24, 89),
        Cell(40, 89),
        Cell(56, 89),
        Cell(72, 89),
        Cell(88, 89),
        Cell(104, 89),
        Cell(120, 89),
        Cell(136, 89),

        Cell(24, 105),
        Cell(56, 105),
        Cell(88, 105),
        Cell(120, 105),
    };
}