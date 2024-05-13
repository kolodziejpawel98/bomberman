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
        std::vector<std::shared_ptr<Cell>> crossPatternNeighbors; // uint8_t

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
        {
            gb.display.drawImage(cell->get()->centralPoint.first - 8, cell->get()->centralPoint.second - 8, sprite::bomb);
            drawBlast(cell);
        }

        void drawBlast(const std::vector<std::shared_ptr<Cell>>::iterator &cell)
        {
            gb.display.setColor(RED);
            for (auto &neighbor : cell->get()->crossPatternNeighbors)
            {
                gb.display.fillRect(neighbor->coordinate.x, neighbor->coordinate.y, neighbor->coordinate.width, neighbor->coordinate.height);
            }
        }
    };

    std::shared_ptr<Bomb> bomb = nullptr;
    std::vector<Coordinate> borders = {
        Coordinate(0, 0, 160, 9),
        Coordinate(0, 9, 8, 119),
        Coordinate(8, 121, 152, 7),
        Coordinate(152, 9, 8, 112)};

    std::vector<std::shared_ptr<Cell>> cells = {
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

    // cells[0]->crossPatternNeighbors.push_back(cells.at(1));

    void setCrossPatternNeighbors()
    {
        cells[1]->crossPatternNeighbors.push_back(cells[10]);
        cells[3]->crossPatternNeighbors.push_back(cells[12]);
        cells[5]->crossPatternNeighbors.push_back(cells[14]);
        cells[7]->crossPatternNeighbors.push_back(cells[16]);

        cells[9]->crossPatternNeighbors.push_back(cells[10]);
        cells[10]->crossPatternNeighbors.push_back(cells[1]);
        cells[10]->crossPatternNeighbors.push_back(cells[9]);
        cells[10]->crossPatternNeighbors.push_back(cells[19]);
        cells[10]->crossPatternNeighbors.push_back(cells[11]);

        cells[11]->crossPatternNeighbors.push_back(cells[10]);
        cells[11]->crossPatternNeighbors.push_back(cells[12]);

        cells[12]->crossPatternNeighbors.push_back(cells[3]);
        cells[12]->crossPatternNeighbors.push_back(cells[11]);
        cells[12]->crossPatternNeighbors.push_back(cells[21]);
        cells[12]->crossPatternNeighbors.push_back(cells[13]);

        cells[13]->crossPatternNeighbors.push_back(cells[12]);
        cells[13]->crossPatternNeighbors.push_back(cells[14]);
    }

    std::vector<std::shared_ptr<Cell>>::iterator findNearestCell(int playerXcoordinate, int playerYcoordinate)
    { // TODO!!!!!!!!!!!! now lambda takes every cell, but should takes only walkable cells!!!!!!
        std::vector<std::shared_ptr<Cell>>::iterator iterator = std::min_element(cells.begin(),
                                                                                 cells.end(),
                                                                                 [&playerXcoordinate, &playerYcoordinate](const std::shared_ptr<Cell> &currentCell, const std::shared_ptr<Cell> &nextCell)
                                                                                 { return currentCell->getDistanceToCentral(playerXcoordinate, playerYcoordinate) < nextCell->getDistanceToCentral(playerXcoordinate, playerYcoordinate); });
        return iterator;
    }

}