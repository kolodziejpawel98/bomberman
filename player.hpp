#pragma once

#if defined(ARDUINO) && ARDUINO >= 100
#include "arduino.h"
#else
#include "WProgram.h"
#endif
#undef max
#undef min
#include <Arduino.h>
#include <algorithm>
#include "input_handler.hpp"
#include "global_variables.hpp"

void xd()
{
    player_speed_x = 0;
    player_speed_y = 0;
    buttonListener();
    player_x += player_speed_x;
    player_y += player_speed_y;
    // player_speed_x = std::min(max_speed, std::max(-max_speed, player_speed_x));
    // player_speed_y = std::min(max_speed, std::max(-max_speed, player_speed_y));

    gb.display.setColor(GREEN);
    gb.display.fillRect(player_x, player_y, 3, 3);
}