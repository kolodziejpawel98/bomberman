#pragma once

#if defined(ARDUINO) && ARDUINO >= 100
#include "arduino.h"
#else
#include "WProgram.h"
#endif
#undef max
#undef min
#include <Arduino.h>
#include "debug_framework.hpp"
// #include "player.hpp"
#include "global_variables.hpp"
#include "graphics.hpp"

void drawSquare()
{
    gb.display.setColor(YELLOW);
    gb.display.fillRect(playerX, playerY, 16, 16);
    gb.display.setColor(RED);
    gb.display.fillRect(playerContactPoints[0].first, playerContactPoints[0].second, 1, 1);
    gb.display.fillRect(playerContactPoints[1].first - 1, playerContactPoints[1].second, 1, 1);
    gb.display.fillRect(playerContactPoints[2].first, playerContactPoints[2].second - 1, 1, 1);
    gb.display.fillRect(playerContactPoints[3].first - 1, playerContactPoints[3].second - 1, 1, 1);
}

void moveUp()
{
    gb.display.drawImage(playerX, playerY, sprite::animationWalkUp);
    playerSpeedY = -playerSpeed;
    // drawSquare();
}

void moveDown()
{
    gb.display.drawImage(playerX, playerY, sprite::animationWalkDown);
    playerSpeedY = playerSpeed;
    // drawSquare();
}

void moveLeft()
{
    gb.display.drawImage(playerX, playerY, sprite::animationWalkLeft);
    playerSpeedX = -playerSpeed;
    // drawSquare();
}

void moveRight()
{
    gb.display.drawImage(playerX, playerY, sprite::animationWalkRight);
    playerSpeedX = playerSpeed;
    // drawSquare();
}

void idle()
{
    gb.display.drawImage(playerX, playerY, sprite::animationIdle);
    // drawSquare();
}

void buttonListener()
{
    if (gb.buttons.repeat(BUTTON_LEFT, 0))
    {
        if (!playground::collider.isBlockingElementCollided(
                playerX,
                playerY,
                16,
                16))
        {
            moveLeft();
        }
    }
    else if (gb.buttons.repeat(BUTTON_RIGHT, 0))
    {
        if (!playground::collider.isBlockingElementCollided(
                playerX,
                playerY,
                16,
                16))
        {
            moveRight();
        }
    }
    else if (gb.buttons.repeat(BUTTON_UP, 0))
    {
        if (!playground::collider.isBlockingElementCollided(
                playerX,
                playerY,
                16,
                16))
        {
            moveUp();
        }
    }
    else if (gb.buttons.repeat(BUTTON_DOWN, 0))
    {
        if (!playground::collider.isBlockingElementCollided(
                playerX,
                playerY,
                16,
                16))
        {
            moveDown();
        }
    }
    else
    {
        idle();
    }
}