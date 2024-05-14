#include "coordinate.hpp"

bool Coordinate::isCoordinateExist(uint8_t x, uint8_t y, uint8_t width, uint8_t height)
{
    if (this->x == x && this->y == y && this->width == width && this->height == height)
    {
        return true;
    }
    else
        return false;
}