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
    void drawBlockingElement(uint8_t x, uint8_t y, uint8_t width, uint8_t height);
    void drawInteractiveElement(uint8_t x, uint8_t y, uint8_t width, uint8_t height);
    void saveInteractiveElement(uint8_t x, uint8_t y, uint8_t width, uint8_t height);
    void saveBlockingElement(uint8_t x, uint8_t y, uint8_t width, uint8_t height);
    bool isBlockingElementColliding(uint8_t x, uint8_t y, uint8_t playerWidth, uint8_t playerHeight);
    bool isInteractiveElementColliding(uint8_t x, uint8_t y, uint8_t playerWidth, uint8_t playerHeight);
    bool isBlockingElementExist(uint8_t x, uint8_t y, uint8_t width, uint8_t height);
    bool isInteractiveElementExist(uint8_t x, uint8_t y, uint8_t width, uint8_t height);

    extern std::vector<std::shared_ptr<Coordinate>> blockingElements;
    extern std::vector<std::shared_ptr<Coordinate>> interactiveElements;
}
