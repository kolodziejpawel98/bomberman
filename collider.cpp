#include <Gamebuino-Meta.h>
#include "collider.hpp"

std::vector<std::shared_ptr<Coordinate>> collider::blockingElements; // dodanie tego plus extern w .hpp rozwiazaniem errora multiple definition of blockingElements
std::vector<std::shared_ptr<Coordinate>> collider::interactiveElements;

void collider::drawBlockingElement(uint8_t x, uint8_t y, uint8_t width, uint8_t height)
{
    // gb.display.setColor(DARKGRAY);
    // gb.display.fillRect(x, y, width, height);

    if (!isBlockingElementExist(x, y, width, height))
    {
        saveBlockingElement(x, y, width, height);
    }
}

void collider::drawInteractiveElement(uint8_t x, uint8_t y, uint8_t width, uint8_t height)
{
    gb.display.setColor(RED);
    gb.display.fillRect(x, y, width, height);

    if (!isInteractiveElementExist(x, y, width, height))
    {
        saveInteractiveElement(x, y, width, height);
    }
}

void collider::saveBlockingElement(uint8_t x, uint8_t y, uint8_t width, uint8_t height)
{
    blockingElements.push_back(std::make_shared<Coordinate>(x, y, width, height));
}

void collider::saveInteractiveElement(uint8_t x, uint8_t y, uint8_t width, uint8_t height)
{
    interactiveElements.push_back(std::make_shared<Coordinate>(x, y, width, height));
}

bool collider::isBlockingElementColliding(uint8_t x, uint8_t y, uint8_t playerWidth, uint8_t playerHeight)
{
    for (auto it : blockingElements)
    {
        if (gb.collide.rectRect(x, y, playerWidth, playerHeight, it->x, it->y, it->width, it->height))
        {
            return true;
        }
    }
    return false;
}

bool collider::isInteractiveElementColliding(uint8_t x, uint8_t y, uint8_t playerWidth, uint8_t playerHeight)
{
    for (auto it : interactiveElements)
    {
        if (gb.collide.rectRect(x, y, playerWidth, playerHeight, it->x, it->y, it->width, it->height))
        {
            return true;
        }
    }
    return false;
}

bool collider::isBlockingElementExist(uint8_t x, uint8_t y, uint8_t width, uint8_t height)
{
    auto iterator = std::find_if(
        blockingElements.begin(),
        blockingElements.end(),
        [&x, &y, &width, &height](std::shared_ptr<Coordinate> element)
        {
            return element->isCoordinateExist(x, y, width, height);
        });

    if (iterator != blockingElements.end())
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool collider::isInteractiveElementExist(uint8_t x, uint8_t y, uint8_t width, uint8_t height)
{
    auto iterator = std::find_if(
        interactiveElements.begin(),
        interactiveElements.end(),
        [&x, &y, &width, &height](std::shared_ptr<Coordinate> element)
        {
            return element->isCoordinateExist(x, y, width, height);
        });

    if (iterator != interactiveElements.end())
    {
        return true;
    }
    else
    {
        return false;
    }
}