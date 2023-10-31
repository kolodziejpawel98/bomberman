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
#include <vector>

void printText(String text, int textPosX = 50, int textPosY = 50, int fontSize = 1)
{
    gb.display.setFontSize(fontSize);
    gb.display.setCursor(textPosX, textPosY);
    gb.display.println(text);
}

void printNumber(int number, int textPosX = 50, int textPosY = 50, int fontSize = 1)
{
    gb.display.setFontSize(fontSize);
    gb.display.setCursor(textPosX, textPosY);
    gb.display.println(number);
}

void printPair(int x, int y, int textPosX = 50, int textPosY = 50, int fontSize = 1)
{
    gb.display.setFontSize(fontSize);
    printNumber(x, textPosX, textPosY + 7);
    printNumber(y, textPosX + 12, textPosY + 7);
}

void printTextAndPair(String text, int x, int y, int textPosX = 50, int textPosY = 50, int fontSize = 1)
{
    gb.display.setFontSize(fontSize);
    printText(text, textPosX, textPosY);
    printNumber(x, textPosX, textPosY + 7); // why + 7 ?
    printNumber(y, textPosX + 12, textPosY + 7);
}

void printPair(std::vector<std::pair<int, int>> &points, int textPosX = 50, int textPosY = 50, int fontSize = 1)
{
    int newLineStep = 0;
    gb.display.setFontSize(fontSize);
    gb.display.setCursor(textPosX, textPosY);

    for (const auto &point : points)
    {
        printNumber(point.first, textPosX, textPosY + newLineStep);
        printNumber(point.second, textPosX + 12, textPosY + newLineStep);
        newLineStep += 7;
    }
}

void drawDot(int x, int y)
{
    gb.display.setColor(RED);
    gb.display.fillRect(x, y, 1, 1);
}

// zrobic wersje z pair template T