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
#include <unordered_set>
#include "collider.hpp"

const uint8_t SCREEN_WIDTH = 2 * 80;
const uint8_t SCREEN_HEIGHT = 2 * 64;

int playerX = 0; // top-left corner
int playerY = 0; // top-left corner
int playerSpeed = 3;
int playerSpeedX = 0;
int playerSpeedY = 0;

std::vector<std::pair<int, int>> playerContactPoints = {{playerX + 3, playerY + 2}, {playerX + 16, playerY}, {playerX, playerY + 16}, {playerX + 16, playerY + 16}}; // w [0] przesuniecie zeby bralo fragment ciala jako collidder

void updatePlayerContactPoints()
{
    playerContactPoints[0] = std::make_pair(playerX, playerY);
    playerContactPoints[1] = std::make_pair(playerX + 16, playerY);
    playerContactPoints[2] = std::make_pair(playerX, playerY + 16);
    playerContactPoints[3] = std::make_pair(playerX + 16, playerY + 16);
}

namespace playground
{
    Collider collider;

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