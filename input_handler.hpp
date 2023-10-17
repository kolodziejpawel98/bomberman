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

void moveUp()
{
    gb.display.drawImage(playerX, playerY, animationWalkUp);
    playerSpeedY = -playerSpeed;
}

void moveDown()
{
    gb.display.drawImage(playerX, playerY, animationWalkDown);
    playerSpeedY = playerSpeed;
}

void moveLeft()
{
    gb.display.drawImage(playerX, playerY, animationWalkLeft);
    playerSpeedX = -playerSpeed;
}

void moveRight()
{
    gb.display.drawImage(playerX, playerY, animationWalkRight);
    playerSpeedX = playerSpeed;
}

void idle()
{
    gb.display.drawImage(playerX, playerY, animationIdle);
}

void buttonListener()
{
    if (gb.buttons.repeat(BUTTON_LEFT, 0))
    {
        moveLeft();
    }
    else if (gb.buttons.repeat(BUTTON_RIGHT, 0))
    {
        moveRight();
    }
    else if (gb.buttons.repeat(BUTTON_UP, 0))
    {
        moveUp();
    }
    else if (gb.buttons.repeat(BUTTON_DOWN, 0))
    {
        moveDown();
    }
    else
    {
        idle();
    }
}
