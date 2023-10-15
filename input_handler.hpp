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

void moveUp()
{
    debugFramework("u");
    player_speed_y = -player_speed;
}

void moveDown()
{
    debugFramework("d");
    player_speed_y = player_speed;
}

void moveLeft()
{
    debugFramework("l");
    player_speed_x = -player_speed;
}

void moveRight()
{
    debugFramework("r");
    player_speed_x = player_speed;
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
}
