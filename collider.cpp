#include <Gamebuino-Meta.h>
#include "collider.hpp"

std::vector<std::shared_ptr<Coordinates>> collider::blockingElements; // dodanie tego plus extern w .hpp rozwiazaniem errora multiple definition of blockingElements
std::vector<std::shared_ptr<Coordinates>> collider::interactiveElements;

void collider::drawBlockingElement(int x, int y, int width, int height)
{
    gb.display.setColor(DARKGRAY);
    gb.display.fillRect(x, y, width, height);

    if (!isBlockingElementExist(x, y, width, height))
    {
        saveBlockingElement(x, y, width, height);
    }
}

void collider::drawInteractiveElement(int x, int y, int width, int height)
{
    gb.display.setColor(LIGHTGREEN);
    gb.display.fillRect(x, y, width, height);

    if (!isInteractiveElementExist(x, y, width, height))
    {
        saveInteractiveElement(x, y, width, height);
    }
}

void collider::saveBlockingElement(int x, int y, int width, int height)
{
    blockingElements.push_back(std::make_shared<Coordinates>(x, y, width, height));
}

void collider::saveInteractiveElement(int x, int y, int width, int height)
{
    interactiveElements.push_back(std::make_shared<Coordinates>(x, y, width, height));
}

bool collider::isBlockingElementColliding(int playerX, int playerY, int playerWidth, int playerHeight)
{
    for (auto it : blockingElements)
    {
        if (gb.collide.rectRect(playerX, playerY, playerWidth, playerHeight, it->x, it->y, it->width, it->height))
        {
            return true;
        }
    }
    return false;
}

bool collider::isInteractiveElementColliding(int playerX, int playerY, int playerWidth, int playerHeight)
{
    for (auto it : interactiveElements)
    {
        if (gb.collide.rectRect(playerX, playerY, playerWidth, playerHeight, it->x, it->y, it->width, it->height))
        {
            return true;
        }
    }
    return false;
}

bool collider::isBlockingElementExist(int x, int y, int width, int height)
{
    auto iterator = std::find_if(
        blockingElements.begin(),
        blockingElements.end(),
        [&x, &y, &width, &height](std::shared_ptr<Coordinates> element)
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

bool collider::isInteractiveElementExist(int x, int y, int width, int height)
{
    auto iterator = std::find_if(
        interactiveElements.begin(),
        interactiveElements.end(),
        [&x, &y, &width, &height](std::shared_ptr<Coordinates> element)
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