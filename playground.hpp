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

        Rock(int x, int y) : coordinate(x, y) {}

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
        bool isDestroyableBlockPlacedOnCell;
        bool isUndestroyableStonePlacedOnCell;
        bool xd = true;

        Cell(int x,
             int y,
             bool isDestroyableBlockPlacedOnCell = false,
             bool isUndestroyableStonePlacedOnCell = false) : coordinate(x, y, 16, 16),
                                                              centralPoint({x + 8, y + 8}),
                                                              isDestroyableBlockPlacedOnCell(isDestroyableBlockPlacedOnCell),
                                                              isUndestroyableStonePlacedOnCell(isUndestroyableStonePlacedOnCell)
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

        void drawBomb(const std::vector<std::shared_ptr<Cell>>::iterator &cell)
        { // TODO
            gb.display.drawImage(cell.centralPoint.first - 8, cell.centralPoint.second - 8, sprite::bomb);
        }
    };

    std::shared_ptr<Bomb> bomb = nullptr;

    std::vector<std::shared_ptr<Rock>>
        rocks = {
            std::make_shared<Rock>(8, 9),
            std::make_shared<Rock>(40, 9),
            std::make_shared<Rock>(72, 9),
            std::make_shared<Rock>(104, 9),
            std::make_shared<Rock>(136, 9),

            std::make_shared<Rock>(8, 41),
            std::make_shared<Rock>(40, 41),
            std::make_shared<Rock>(72, 41),
            std::make_shared<Rock>(104, 41),
            std::make_shared<Rock>(136, 41),

            std::make_shared<Rock>(8, 73),
            std::make_shared<Rock>(40, 73),
            std::make_shared<Rock>(72, 73),
            std::make_shared<Rock>(104, 73),
            std::make_shared<Rock>(136, 73),

            std::make_shared<Rock>(8, 105),
            std::make_shared<Rock>(40, 105),
            std::make_shared<Rock>(72, 105),
            std::make_shared<Rock>(104, 105),
            std::make_shared<Rock>(136, 105)};

    std::vector<std::shared_ptr<Coordinate>> borders = {
        std::make_shared<Coordinate>(0, 0, 160, 9),
        std::make_shared<Coordinate>(0, 9, 8, 119),
        std::make_shared<Coordinate>(8, 121, 152, 7),
        std::make_shared<Coordinate>(152, 9, 8, 112)};

    // std::vector<std::shared_ptr<Coordinate>> borddders = {
    //     std::make_shared<Coordinate>(0, 0, 160, 9),
    //     std::make_shared<Coordinate>(0, 9, 8, 119)};

    std::vector<std::shared_ptr<Cell>> walkableCells = {

        std::make_shared<Cell>(24, 9),
        std::make_shared<Cell>(56, 9),
        std::make_shared<Cell>(88, 9),
        std::make_shared<Cell>(120, 9),

        std::make_shared<Cell>(8, 25),
        std::make_shared<Cell>(24, 25),
        std::make_shared<Cell>(40, 25),
        std::make_shared<Cell>(56, 25),
        std::make_shared<Cell>(72, 25, true),
        std::make_shared<Cell>(88, 25, true),
        std::make_shared<Cell>(104, 25, true),
        std::make_shared<Cell>(120, 25, true),
        std::make_shared<Cell>(136, 25),

        std::make_shared<Cell>(24, 41),
        std::make_shared<Cell>(56, 41),
        std::make_shared<Cell>(88, 41),
        std::make_shared<Cell>(120, 41),

        std::make_shared<Cell>(8, 57),
        std::make_shared<Cell>(24, 57),
        std::make_shared<Cell>(40, 57),
        std::make_shared<Cell>(56, 57),
        std::make_shared<Cell>(72, 57),
        std::make_shared<Cell>(88, 57),
        std::make_shared<Cell>(104, 57),
        std::make_shared<Cell>(120, 57),
        std::make_shared<Cell>(136, 57),

        std::make_shared<Cell>(24, 73),
        std::make_shared<Cell>(56, 73, true),
        std::make_shared<Cell>(88, 73),
        std::make_shared<Cell>(120, 73),

        std::make_shared<Cell>(8, 89),
        std::make_shared<Cell>(24, 89),
        std::make_shared<Cell>(40, 89),
        std::make_shared<Cell>(56, 89),
        std::make_shared<Cell>(72, 89),
        std::make_shared<Cell>(88, 89),
        std::make_shared<Cell>(104, 89),
        std::make_shared<Cell>(120, 89),
        std::make_shared<Cell>(136, 89),

        std::make_shared<Cell>(24, 105),
        std::make_shared<Cell>(56, 105),
        std::make_shared<Cell>(88, 105),
        std::make_shared<Cell>(120, 105)};

    std::vector<std::shared_ptr<Cell>>::iterator findNearestCell(int playerXcoordinate, int playerYcoordinate)
    {
        auto iterator = std::min_element(walkableCells.begin(), walkableCells.end(), [&playerXcoordinate, &playerYcoordinate](const std::shared_ptr<Cell> &currentCell, const std::shared_ptr<Cell> &nextCell)
                                         { return currentCell->getDistanceToCentral(playerXcoordinate, playerYcoordinate) < nextCell->getDistanceToCentral(playerXcoordinate, playerYcoordinate); });
        return iterator;
    }

}