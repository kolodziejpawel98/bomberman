#pragma once

#if defined(ARDUINO) && ARDUINO >= 100
#include "arduino.h"
#else
#include "WProgram.h"
#endif
#undef max
#undef min
#include <Arduino.h>
#include <memory>
#include "global_variables.hpp"
#include "collider.hpp"
#include "playground.hpp"

void drawSquare()
{
    // gb.display.setColor(YELLOW);
    // gb.display.fillRect(player.colliderX, player.colliderY, player.colliderWidht, player.colliderHeight);
}

void moveUp()
{
    player.stepLengthY = -player.stepLength;
    drawSquare();
}

void moveDown()
{
    player.stepLengthY = player.stepLength;
    drawSquare();
}

void moveLeft()
{
    player.stepLengthX = -player.stepLength;
    drawSquare();
}

void moveRight()
{
    player.stepLengthX = player.stepLength;
    drawSquare();
}

void idle()
{
    gb.display.drawImage(player.x, player.y, sprite::animationIdle);
    drawSquare();
}

void buttonListener()
{
    if (gb.buttons.repeat(BUTTON_LEFT, 0))
    {
        if (!collider::isBlockingElementColliding(
                player.colliderX - player.stepLength,
                player.colliderY,
                player.colliderWidht,
                player.colliderHeight))
        {
            moveLeft();
        }
        gb.display.drawImage(player.x, player.y, sprite::animationWalkLeft);
    }
    else if (gb.buttons.repeat(BUTTON_RIGHT, 0))
    {
        if (!collider::isBlockingElementColliding(
                player.colliderX + player.stepLength,
                player.colliderY,
                player.colliderWidht,
                player.colliderHeight))
        {
            moveRight();
        }
        gb.display.drawImage(player.x, player.y, sprite::animationWalkRight);
    }
    else if (gb.buttons.repeat(BUTTON_UP, 0))
    {
        if (!collider::isBlockingElementColliding(
                player.colliderX,
                player.colliderY - player.stepLength,
                player.colliderWidht,
                player.colliderHeight))
        {
            moveUp();
        }
        gb.display.drawImage(player.x, player.y, sprite::animationWalkUp);
    }
    else if (gb.buttons.repeat(BUTTON_DOWN, 0))
    {
        if (!collider::isBlockingElementColliding(
                player.colliderX,
                player.colliderY + player.stepLength,
                player.colliderWidht,
                player.colliderHeight))
        {
            moveDown();
        }
        gb.display.drawImage(player.x, player.y, sprite::animationWalkDown);
    }
    else
    {
        idle();
    }

    if (gb.buttons.pressed(BUTTON_A))
    {
        playground::bomb = std::make_shared<playground::Bomb>(player.x, player.y);
    }
}

void playerMove()
{
    player.stepLengthX = 0;
    player.stepLengthY = 0;
    buttonListener();
    player.x += player.stepLengthX;
    player.y += player.stepLengthY;
    player.updateCollider();
}
