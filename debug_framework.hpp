#pragma once

#if defined(ARDUINO) && ARDUINO >= 100
#include "arduino.h"
#else
#include "WProgram.h"
#endif
#undef max
#undef min
#include <Arduino.h>
#include <string>

void debugFramework(String text, int textPosX = 50, int textPosY = 50)
{
    gb.display.setCursor(50, 50);
    gb.display.println(text);
}

void debugFramework(int number, int textPosX = 50, int textPosY = 50)
{
    gb.display.setCursor(50, 50);
    gb.display.println(number);
}