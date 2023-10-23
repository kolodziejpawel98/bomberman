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
}

void moveUp()
{
    gb.display.drawImage(playerX, playerY, sprite::animationWalkUp);
    playerSpeedY = -playerSpeed;
    drawSquare();
}

void moveDown()
{
    gb.display.drawImage(playerX, playerY, sprite::animationWalkDown);
    playerSpeedY = playerSpeed;
    drawSquare();
}

void moveLeft()
{
    gb.display.drawImage(playerX, playerY, sprite::animationWalkLeft);
    playerSpeedX = -playerSpeed;
    drawSquare();
}

void moveRight()
{
    gb.display.drawImage(playerX, playerY, sprite::animationWalkRight);
    playerSpeedX = playerSpeed;
    drawSquare();
}

void idle()
{
    gb.display.drawImage(playerX, playerY, sprite::animationIdle);
    drawSquare();
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