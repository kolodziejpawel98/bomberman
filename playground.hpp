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
        std::pair<int, int> centralPoint;

        Cell(int x, int y, const std::pair<int, int> &centralPoint, int width = 16, int height = 16) : coordinate(x, y, width, height), centralPoint(centralPoint)
        {
        }

        void drawPlacehodler()
        {
            gb.display.setColor(RED);
            gb.display.fillRect(coordinate.x, coordinate.y, coordinate.width, coordinate.height);
        }

        float getDistanceToCentral(int playerX, int playerY)
        {
            int dx = centralPoint.first - playerX;
            int dy = centralPoint.second - playerY;
            return std::sqrt(dx * dx + dy * dy);
        }
    };

    struct Bomb
    {
        Coordinate coordinate;
        Bomb(int x, int y) : coordinate(x, y) {}

        void drawBomb()
        {
            gb.display.drawImage(coordinate.x, coordinate.y, sprite::bomb);
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

        Cell(24, 9, std::make_pair(32, 17)),
        Cell(56, 9, std::make_pair(64, 17)),
        Cell(88, 9, std::make_pair(96, 17)),
        Cell(120, 9, std::make_pair(128, 17)),

        Cell(8, 25, std::make_pair(16, 33)),
        Cell(24, 25, std::make_pair(32, 33)),
        Cell(40, 25, std::make_pair(48, 33)),
        Cell(56, 25, std::make_pair(64, 33)),
        Cell(72, 25, std::make_pair(80, 33)),
        Cell(88, 25, std::make_pair(96, 33)),
        Cell(104, 25, std::make_pair(112, 33)),
        Cell(120, 25, std::make_pair(128, 33)),
        Cell(136, 25, std::make_pair(144, 33)),

        Cell(24, 41, std::make_pair(32, 49)),
        Cell(56, 41, std::make_pair(64, 49)),
        Cell(88, 41, std::make_pair(96, 49)),
        Cell(120, 41, std::make_pair(128, 49)),

        Cell(8, 57, std::make_pair(16, 65)),
        Cell(24, 57, std::make_pair(32, 65)),
        Cell(40, 57, std::make_pair(48, 65)),
        Cell(56, 57, std::make_pair(64, 65)),
        Cell(72, 57, std::make_pair(80, 65)),
        Cell(88, 57, std::make_pair(96, 65)),
        Cell(104, 57, std::make_pair(112, 65)),
        Cell(120, 57, std::make_pair(128, 65)),
        Cell(136, 57, std::make_pair(144, 65)),

        Cell(24, 73, std::make_pair(32, 81)),
        Cell(56, 73, std::make_pair(64, 81)),
        Cell(88, 73, std::make_pair(96, 81)),
        Cell(120, 73, std::make_pair(128, 81)),

        Cell(8, 89, std::make_pair(16, 97)),
        Cell(24, 89, std::make_pair(32, 97)),
        Cell(40, 89, std::make_pair(48, 97)),
        Cell(56, 89, std::make_pair(64, 97)),
        Cell(72, 89, std::make_pair(80, 97)),
        Cell(88, 89, std::make_pair(96, 97)),
        Cell(104, 89, std::make_pair(112, 97)),
        Cell(120, 89, std::make_pair(128, 97)),
        Cell(136, 89, std::make_pair(144, 97)),

        Cell(24, 105, std::make_pair(32, 113)),
        Cell(56, 105, std::make_pair(64, 113)),
        Cell(88, 105, std::make_pair(96, 113)),
        Cell(120, 105, std::make_pair(128, 113))};

    int findNearestCell(int playerX, int playerY)
    {
        float nearestDistance = 999.0;
        int index = 0;
        int xd = 0;
        for (auto &cell : walkableCells)
        {
            if (cell.getDistanceToCentral(playerX, playerY) < nearestDistance)
            {
                nearestDistance = cell.getDistanceToCentral(playerX, playerY);
                xd = index;
            }
            index++;
        }
        return xd;
    }
}