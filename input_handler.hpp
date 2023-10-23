#pragma once

#if defined(ARDUINO) && ARDUINO >= 100
#include "arduino.h"
#else
#include "WProgram.h"
#endif
#undef max
#undef min
#include <Arduino.h>
#include "global_variables.hpp"
#include "collider.hpp"

void drawSquare()
{
    gb.display.setColor(YELLOW);
    gb.display.fillRect(player.playerX, player.playerY, 16, 16);
}

void moveUp()
{
    gb.display.drawImage(player.playerX, player.playerY, sprite::animationWalkUp);
    player.playerSpeedY = -player.playerSpeed;
    // drawSquare();
}

void moveDown()
{
    gb.display.drawImage(player.playerX, player.playerY, sprite::animationWalkDown);
    player.playerSpeedY = player.playerSpeed;
    // drawSquare();
}

void moveLeft()
{
    gb.display.drawImage(player.playerX, player.playerY, sprite::animationWalkLeft);
    player.playerSpeedX = -player.playerSpeed;
    // drawSquare();
}

void moveRight()
{
    gb.display.drawImage(player.playerX, player.playerY, sprite::animationWalkRight);
    player.playerSpeedX = player.playerSpeed;
    // drawSquare();
}

void idle()
{
    gb.display.drawImage(player.playerX, player.playerY, sprite::animationIdle);
    // drawSquare();
}

void buttonListener()
{
    if (gb.buttons.repeat(BUTTON_LEFT, 0))
    {
        if (!collider::isBlockingElementColliding(
                player.playerX,
                player.playerY,
                16,
                16))
        {
            moveLeft();
        }
    }
    else if (gb.buttons.repeat(BUTTON_RIGHT, 0))
    {
        if (!collider::isBlockingElementColliding(
                player.playerX,
                player.playerY,
                16,
                16))
        {
            moveRight();
        }
    }
    else if (gb.buttons.repeat(BUTTON_UP, 0))
    {
        if (!collider::isBlockingElementColliding(
                player.playerX,
                player.playerY,
                16,
                16))
        {
            moveUp();
        }
    }
    else if (gb.buttons.repeat(BUTTON_DOWN, 0))
    {
        if (!collider::isBlockingElementColliding(
                player.playerX,
                player.playerY,
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

void playerMove()
{
    player.playerSpeedX = 0;
    player.playerSpeedY = 0;
    buttonListener();
    player.playerX += player.playerSpeedX;
    player.playerY += player.playerSpeedY;
}
