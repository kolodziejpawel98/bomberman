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

void debugFramework(String text, int textPosX = 50, int textPosY = 50, int fontSize = 1)
{
    gb.display.setFontSize(fontSize);
    gb.display.setCursor(textPosX, textPosY);
    gb.display.println(text);
}

void debugFramework(int number, int textPosX = 50, int textPosY = 50, int fontSize = 1)
{
    gb.display.setFontSize(fontSize);
    gb.display.setCursor(textPosX, textPosY);
    gb.display.println(number);
}

// zrobic wersje z pair template T