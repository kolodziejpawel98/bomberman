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
        // 1st row
        cells[1]->crossPatternNeighbors.push_back(cells[10]);
        cells[3]->crossPatternNeighbors.push_back(cells[12]);
        cells[5]->crossPatternNeighbors.push_back(cells[14]);
        cells[7]->crossPatternNeighbors.push_back(cells[16]);
        // 2nd row
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

        cells[14]->crossPatternNeighbors.push_back(cells[5]);
        cells[14]->crossPatternNeighbors.push_back(cells[13]);
        cells[14]->crossPatternNeighbors.push_back(cells[23]);
        cells[14]->crossPatternNeighbors.push_back(cells[15]);

        cells[15]->crossPatternNeighbors.push_back(cells[16]);
        cells[15]->crossPatternNeighbors.push_back(cells[14]);

        cells[16]->crossPatternNeighbors.push_back(cells[7]);
        cells[16]->crossPatternNeighbors.push_back(cells[15]);
        cells[16]->crossPatternNeighbors.push_back(cells[25]);
        cells[16]->crossPatternNeighbors.push_back(cells[17]);

        cells[17]->crossPatternNeighbors.push_back(cells[16]);
        // 3rd row
        cells[19]->crossPatternNeighbors.push_back(cells[10]);
        cells[19]->crossPatternNeighbors.push_back(cells[28]);
        cells[21]->crossPatternNeighbors.push_back(cells[12]);
        cells[21]->crossPatternNeighbors.push_back(cells[30]);
        cells[23]->crossPatternNeighbors.push_back(cells[14]);
        cells[23]->crossPatternNeighbors.push_back(cells[32]);
        cells[25]->crossPatternNeighbors.push_back(cells[16]);
        cells[25]->crossPatternNeighbors.push_back(cells[34]);
        // 4th row
        cells[27]->crossPatternNeighbors.push_back(cells[28]);

        cells[28]->crossPatternNeighbors.push_back(cells[19]);
        cells[28]->crossPatternNeighbors.push_back(cells[27]);
        cells[28]->crossPatternNeighbors.push_back(cells[37]);
        cells[28]->crossPatternNeighbors.push_back(cells[29]);

        cells[29]->crossPatternNeighbors.push_back(cells[28]);
        cells[29]->crossPatternNeighbors.push_back(cells[30]);

        cells[30]->crossPatternNeighbors.push_back(cells[21]);
        cells[30]->crossPatternNeighbors.push_back(cells[29]);
        cells[30]->crossPatternNeighbors.push_back(cells[39]);
        cells[30]->crossPatternNeighbors.push_back(cells[31]);

        cells[31]->crossPatternNeighbors.push_back(cells[30]);
        cells[31]->crossPatternNeighbors.push_back(cells[32]);

        cells[32]->crossPatternNeighbors.push_back(cells[23]);
        cells[32]->crossPatternNeighbors.push_back(cells[31]);
        cells[32]->crossPatternNeighbors.push_back(cells[41]);
        cells[32]->crossPatternNeighbors.push_back(cells[33]);

        cells[33]->crossPatternNeighbors.push_back(cells[32]);
        cells[33]->crossPatternNeighbors.push_back(cells[34]);

        cells[34]->crossPatternNeighbors.push_back(cells[25]);
        cells[34]->crossPatternNeighbors.push_back(cells[33]);
        cells[34]->crossPatternNeighbors.push_back(cells[43]);
        cells[34]->crossPatternNeighbors.push_back(cells[35]);

        cells[35]->crossPatternNeighbors.push_back(cells[34]);
        // 5th row
        cells[37]->crossPatternNeighbors.push_back(cells[28]);
        cells[37]->crossPatternNeighbors.push_back(cells[46]);
        cells[39]->crossPatternNeighbors.push_back(cells[48]);
        cells[39]->crossPatternNeighbors.push_back(cells[30]);
        cells[41]->crossPatternNeighbors.push_back(cells[50]);
        cells[41]->crossPatternNeighbors.push_back(cells[32]);
        cells[43]->crossPatternNeighbors.push_back(cells[52]);
        cells[43]->crossPatternNeighbors.push_back(cells[34]);
        // 6th row
        cells[45]->crossPatternNeighbors.push_back(cells[46]);

        cells[46]->crossPatternNeighbors.push_back(cells[37]);
        cells[46]->crossPatternNeighbors.push_back(cells[45]);
        cells[46]->crossPatternNeighbors.push_back(cells[55]);
        cells[46]->crossPatternNeighbors.push_back(cells[47]);

        cells[47]->crossPatternNeighbors.push_back(cells[46]);
        cells[47]->crossPatternNeighbors.push_back(cells[48]);

        cells[48]->crossPatternNeighbors.push_back(cells[39]);
        cells[48]->crossPatternNeighbors.push_back(cells[47]);
        cells[48]->crossPatternNeighbors.push_back(cells[57]);
        cells[48]->crossPatternNeighbors.push_back(cells[49]);

        cells[49]->crossPatternNeighbors.push_back(cells[48]);
        cells[49]->crossPatternNeighbors.push_back(cells[50]);

        cells[50]->crossPatternNeighbors.push_back(cells[41]);
        cells[50]->crossPatternNeighbors.push_back(cells[49]);
        cells[50]->crossPatternNeighbors.push_back(cells[59]);
        cells[50]->crossPatternNeighbors.push_back(cells[51]);

        cells[51]->crossPatternNeighbors.push_back(cells[50]);
        cells[51]->crossPatternNeighbors.push_back(cells[52]);

        cells[52]->crossPatternNeighbors.push_back(cells[43]);
        cells[52]->crossPatternNeighbors.push_back(cells[51]);
        cells[52]->crossPatternNeighbors.push_back(cells[61]);
        cells[52]->crossPatternNeighbors.push_back(cells[53]);

        cells[53]->crossPatternNeighbors.push_back(cells[52]);
        // 7th row
        cells[55]->crossPatternNeighbors.push_back(cells[46]);
        cells[57]->crossPatternNeighbors.push_back(cells[48]);
        cells[59]->crossPatternNeighbors.push_back(cells[50]);
        cells[61]->crossPatternNeighbors.push_back(cells[52]);
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