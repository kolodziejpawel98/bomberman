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

        Rock(uint8_t x, uint8_t y) : coordinate(x, y) {}

        void drawPlacehodler()
        {
            gb.display.setColor(RED);
            gb.display.fillRect(coordinate.x, coordinate.y, coordinate.width, coordinate.height);
        }
    };

    struct Cell
    {
        Coordinate coordinate;
        std::pair<uint8_t, uint8_t> centralPoint;
        bool isDestroyableBlockPlacedOnCell;
        bool isUndestroyableStonePlacedOnCell;
        std::vector<std::shared_ptr<Cell>> crossPatternNeighbors; // uint8_t

        Cell(uint8_t x,
             uint8_t y,
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
        Bomb(uint8_t x, uint8_t y) : coordinate(x, y) {}

        void drawBomb(const std::vector<std::shared_ptr<Cell>>::iterator &cell)
        {
            gb.display.drawImage(cell->get()->centralPoint.first - 8, cell->get()->centralPoint.second - 8, sprite::bomb);
        }

        void drawBlast(const std::vector<std::shared_ptr<Cell>>::iterator &cell, const Color blastColor)
        {
            gb.display.setColor(blastColor);
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
        // 1st row
        std::make_shared<Cell>(8, 9, false, true),    // 0
        std::make_shared<Cell>(24, 9, false, false),  // 1
        std::make_shared<Cell>(40, 9, false, true),   // 2
        std::make_shared<Cell>(56, 9, false, false),  // 3
        std::make_shared<Cell>(72, 9, false, true),   // 4
        std::make_shared<Cell>(88, 9, false, false),  // 5
        std::make_shared<Cell>(104, 9, false, true),  // 6
        std::make_shared<Cell>(120, 9, false, false), // 7
        std::make_shared<Cell>(136, 9, false, true),  // 8
        // 2nd row
        std::make_shared<Cell>(8, 25, false, false),  // 9
        std::make_shared<Cell>(24, 25, false, false), // 10
        std::make_shared<Cell>(40, 25, false, false), // 11
        std::make_shared<Cell>(56, 25, false, false), // 12
        std::make_shared<Cell>(72, 25, false, false), // 13
        std::make_shared<Cell>(88, 25, false, false), // 14
        std::make_shared<Cell>(104, 25, true, false), // 15
        std::make_shared<Cell>(120, 25, true, false), // 16
        std::make_shared<Cell>(136, 25, true, false), // 17
        // 3rd row
        std::make_shared<Cell>(8, 41, false, true),    // 18
        std::make_shared<Cell>(24, 41, false, false),  // 19
        std::make_shared<Cell>(40, 41, false, true),   // 20
        std::make_shared<Cell>(56, 41, false, false),  // 21
        std::make_shared<Cell>(72, 41, false, true),   // 22
        std::make_shared<Cell>(88, 41, false, false),  // 23
        std::make_shared<Cell>(104, 41, false, true),  // 24
        std::make_shared<Cell>(120, 41, false, false), // 25
        std::make_shared<Cell>(136, 41, false, true),  // 26
        // 4th row
        std::make_shared<Cell>(8, 57, false, false),   // 27
        std::make_shared<Cell>(24, 57, false, false),  // 28
        std::make_shared<Cell>(40, 57, false, false),  // 29
        std::make_shared<Cell>(56, 57, false, false),  // 30
        std::make_shared<Cell>(72, 57, true, false),   // 31
        std::make_shared<Cell>(88, 57, true, false),   // 32
        std::make_shared<Cell>(104, 57, true, false),  // 33
        std::make_shared<Cell>(120, 57, false, false), // 34
        std::make_shared<Cell>(136, 57, true, false),  // 35
        // 5th row
        std::make_shared<Cell>(8, 73, false, true),    // 36
        std::make_shared<Cell>(24, 73, false, false),  // 37
        std::make_shared<Cell>(40, 73, false, true),   // 38
        std::make_shared<Cell>(56, 73, false, false),  // 39
        std::make_shared<Cell>(72, 73, false, true),   // 40
        std::make_shared<Cell>(88, 73, false, false),  // 41
        std::make_shared<Cell>(104, 73, false, true),  // 42
        std::make_shared<Cell>(120, 73, false, false), // 43
        std::make_shared<Cell>(136, 73, false, true),  // 44
        // 6th row
        std::make_shared<Cell>(8, 89, false, false),   // 45
        std::make_shared<Cell>(24, 89, false, false),  // 46
        std::make_shared<Cell>(40, 89, false, false),  // 47
        std::make_shared<Cell>(56, 89, false, false),  // 48
        std::make_shared<Cell>(72, 89, true, false),   // 49
        std::make_shared<Cell>(88, 89, false, false),  // 50
        std::make_shared<Cell>(104, 89, false, false), // 51
        std::make_shared<Cell>(120, 89, true, false),  // 52
        std::make_shared<Cell>(136, 89, false, false), // 53
        // 7th row
        std::make_shared<Cell>(8, 105, false, true),    // 54
        std::make_shared<Cell>(24, 105, true, false),   // 55
        std::make_shared<Cell>(40, 105, false, true),   // 56
        std::make_shared<Cell>(56, 105, true, false),   // 57
        std::make_shared<Cell>(72, 105, false, true),   // 58
        std::make_shared<Cell>(88, 105, false, false),  // 59
        std::make_shared<Cell>(104, 105, false, true),  // 60
        std::make_shared<Cell>(120, 105, false, false), // 61
        std::make_shared<Cell>(136, 105, false, true)   // 62
    };

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
    {
        std::vector<std::shared_ptr<Cell>>::iterator iterator = std::min_element(cells.begin(),
                                                                                 cells.end(),
                                                                                 [&playerXcoordinate,
                                                                                  &playerYcoordinate](const std::shared_ptr<Cell> &currentCell,
                                                                                                      const std::shared_ptr<Cell> &nextCell)
                                                                                 { return currentCell->getDistanceToCentral(playerXcoordinate, playerYcoordinate) < nextCell->getDistanceToCentral(playerXcoordinate, playerYcoordinate) && !currentCell->isUndestroyableStonePlacedOnCell; });
        return iterator;
    }
}