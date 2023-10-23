#pragma once

#if defined(ARDUINO) && ARDUINO >= 100
#include "arduino.h"
#else
#include "WProgram.h"
#endif
#undef max
#undef min

struct Coordinate
{
    int x, y, width, height;
    Coordinate(int x, int y, int width, int height) : x(x), y(y), width(width), height(height){};
    bool isCoordinateExist(int, int, int, int);
};