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
    Coordinate(int x, int y) : x(x), y(y), width(16), height(16){};
    bool isCoordinateExist(int, int, int, int);
};