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

void debugFramework(std::vector<std::pair<int, int>> &points, int textPosX = 50, int textPosY = 50, int fontSize = 1)
{
    int newLineStep = 0;
    gb.display.setFontSize(fontSize);
    gb.display.setCursor(textPosX, textPosY);

    for (const auto &point : points)
    {
        debugFramework(point.first, textPosX, textPosY + newLineStep);
        debugFramework(point.second, textPosX + 12, textPosY + newLineStep);
        newLineStep += 7;
    }
}

// zrobic wersje z pair template T