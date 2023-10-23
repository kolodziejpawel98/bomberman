#pragma once

#if defined(ARDUINO) && ARDUINO >= 100
#include "arduino.h"
#else
#include "WProgram.h"
#endif
#undef max
#undef min
#include <utility>
#include <string>
#include <memory>
#include <vector>
#include <algorithm>
#include "global_variables.hpp"
#include "coordinate.hpp"

namespace collider
{
    void drawBlockingElement(int x, int y, int width, int height);
    void drawInteractiveElement(int x, int y, int width, int height);
    void saveInteractiveElement(int x, int y, int width, int height);
    void saveBlockingElement(int x, int y, int width, int height);
    bool isBlockingElementColliding(int playerX, int playerY, int playerWidth, int playerHeight);
    bool isInteractiveElementColliding(int playerX, int playerY, int playerWidth, int playerHeight);
    bool isBlockingElementExist(int x, int y, int width, int height);
    bool isInteractiveElementExist(int x, int y, int width, int height);

    extern std::vector<std::shared_ptr<Coordinate>> blockingElements;
    extern std::vector<std::shared_ptr<Coordinate>> interactiveElements;
}
