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
#include <memory>
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
        std::vector<std::pair<int, int>> crossNeighbors;

        Cell(int x,
             int y,
             bool isDestroyableBlockPlacedOnCell = false,
             bool isUndestroyableStonePlacedOnCell = false) : coordinate(x, y, 16, 16),
                                                              centralPoint({x + 8, y + 8}),
                                                              isDestroyableBlockPlacedOnCell(isDestroyableBlockPlacedOnCell),
                                                              isUndestroyableStonePlacedOnCell(isUndestroyableStonePlacedOnCell)
        {
        }

        Cell(int x,
             int y,
             std::vector<std::pair<int, int>> crossNeighbors,
             bool isDestroyableBlockPlacedOnCell = false,
             bool isUndestroyableStonePlacedOnCell = false) : coordinate(x, y, 16, 16),
                                                              centralPoint({x + 8, y + 8}),
                                                              crossNeighbors(crossNeighbors),
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

        void drawBomb(const std::vector<Cell>::iterator &cell)
        {
            gb.display.drawImage(cell->centralPoint.first - 8, cell->centralPoint.second - 8, sprite::bomb);
        }
    };

    std::shared_ptr<Bomb> bomb = nullptr;

    std::vector<Rock>
        rocks = {
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

    std::vector<std::shared_ptr<Cell>> allCells = {
        std::make_shared<Cell>(8, 9, false, true),
        std::make_shared<Cell>(24, 9, false, false),
        std::make_shared<Cell>(40, 9, false, true),
        std::make_shared<Cell>(56, 9, false, false),
        std::make_shared<Cell>(72, 9, false, true),
        std::make_shared<Cell>(88, 9, false, false),
        std::make_shared<Cell>(104, 9, false, true),
        std::make_shared<Cell>(120, 9, false, false),
        std::make_shared<Cell>(136, 9, false, true),

        std::make_shared<Cell>(8, 25, false, false),
        std::make_shared<Cell>(24, 25, false, false),
        std::make_shared<Cell>(40, 25, false, false),
        std::make_shared<Cell>(56, 25, false, false),
        std::make_shared<Cell>(72, 25, false, false),
        std::make_shared<Cell>(88, 25, false, false),
        std::make_shared<Cell>(104, 25, false, false),
        std::make_shared<Cell>(120, 25, false, false),
        std::make_shared<Cell>(136, 25, false, false),

        std::make_shared<Cell>(8, 41, false, true),
        std::make_shared<Cell>(24, 41, false, false),
        std::make_shared<Cell>(40, 41, false, true),
        std::make_shared<Cell>(56, 41, false, false),
        std::make_shared<Cell>(72, 41, false, true),
        std::make_shared<Cell>(88, 41, false, false),
        std::make_shared<Cell>(104, 41, false, true),
        std::make_shared<Cell>(120, 41, false, false),
        std::make_shared<Cell>(136, 41, false, true),

        std::make_shared<Cell>(8, 57, false, false),
        std::make_shared<Cell>(24, 57, false, false),
        std::make_shared<Cell>(40, 57, false, false),
        std::make_shared<Cell>(56, 57, false, false),
        std::make_shared<Cell>(72, 57, false, false),
        std::make_shared<Cell>(88, 57, false, false),
        std::make_shared<Cell>(104, 57, false, false),
        std::make_shared<Cell>(120, 57, false, false),
        std::make_shared<Cell>(136, 57, false, false),

        std::make_shared<Cell>(8, 73, false, true),
        std::make_shared<Cell>(24, 73, false, false),
        std::make_shared<Cell>(40, 73, false, true),
        std::make_shared<Cell>(56, 73, false, false),
        std::make_shared<Cell>(72, 73, false, true),
        std::make_shared<Cell>(88, 73, false, false),
        std::make_shared<Cell>(104, 73, false, true),
        std::make_shared<Cell>(120, 73, false, false),
        std::make_shared<Cell>(136, 73, false, true),

        std::make_shared<Cell>(8, 89, false, false),
        std::make_shared<Cell>(24, 89, false, false),
        std::make_shared<Cell>(40, 89, false, false),
        std::make_shared<Cell>(56, 89, false, false),
        std::make_shared<Cell>(72, 89, false, false),
        std::make_shared<Cell>(88, 89, false, false),
        std::make_shared<Cell>(104, 89, false, false),
        std::make_shared<Cell>(120, 89, false, false),
        std::make_shared<Cell>(136, 89, false, false),

        std::make_shared<Cell>(8, 105, false, true),
        std::make_shared<Cell>(24, 105, false, false),
        std::make_shared<Cell>(40, 105, false, true),
        std::make_shared<Cell>(56, 105, false, false),
        std::make_shared<Cell>(72, 105, false, true),
        std::make_shared<Cell>(88, 105, false, false),
        std::make_shared<Cell>(104, 105, false, true),
        std::make_shared<Cell>(120, 105, false, false),
        std::make_shared<Cell>(136, 105, false, true)};

    // auto findNearestCell(int playerXcoordinate, int playerYcoordinate)
    // {
    //     auto iterator = std::min_element(walkableCells.begin(), walkableCells.end(), [&playerXcoordinate, &playerYcoordinate](Cell &currentCell, Cell &nextCell)
    //                                      { return currentCell.getDistanceToCentral(playerXcoordinate, playerYcoordinate) < nextCell.getDistanceToCentral(playerXcoordinate, playerYcoordinate); });
    //     return iterator;
    // }

}