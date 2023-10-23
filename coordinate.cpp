#include "coordinate.hpp"

bool Coordinate::isCoordinateExist(int x, int y, int width, int height)
{
    if (this->x == x && this->y == y && this->width == width && this->height == height)
    {
        return true;
    }
    else
        return false;
}