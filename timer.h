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

static int timeCounter = 0;

bool isTimeElapsed(int time)
{
    return (timeCounter >= time) ? true : (++timeCounter, false);
}