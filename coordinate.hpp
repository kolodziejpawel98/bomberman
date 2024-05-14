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
    uint8_t x, y, width, height;
    Coordinate(uint8_t x, uint8_t y, uint8_t width, uint8_t height) : x(x), y(y), width(width), height(height){};
    Coordinate(uint8_t x, uint8_t y) : x(x), y(y), width(16), height(16){};
    bool isCoordinateExist(uint8_t, uint8_t, uint8_t, uint8_t);
};