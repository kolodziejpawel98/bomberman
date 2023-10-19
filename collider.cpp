#include <Gamebuino-Meta.h>
#include "collider.hpp"

String colliderDebugLine = "";

void Collider::drawBlockingElement(int x, int y, int width, int height)
{
    gb.display.setColor(BLUE);
    gb.display.fillRect(x, y, width, height);
    if (!isBlockingElementExist(x, y, width, height))
    {
        addBlockingElement(x, y, width, height);
    }
}

void Collider::drawInteractiveElement(int x, int y, int width, int height)
{
    gb.display.setColor(RED);
    gb.display.fillRect(x, y, width, height);
    if (!isInteractiveElementExist(x, y, width, height))
    {
        addInteractiveElement(x, y, width, height);
    }
}

void Collider::addBlockingElement(int x, int y, int width, int height)
{
    blockingElements.push_back(std::make_shared<Coordinates>(x, y, width, height));
}

void Collider::addInteractiveElement(int x, int y, int width, int height)
{
    interactiveElements.push_back(std::make_shared<Coordinates>(x, y, width, height));
}

bool Collider::isBlockingElementCollided(int playerX, int playerY, int playerWidth, int playerHeight)
{
    for (auto it : blockingElements)
    {
        // colliderDebugLine = static_cast<String>(it->x);
        if (gb.collide.rectRect(playerX, playerY, playerWidth, playerHeight, it->x, it->y, it->width, it->height))
        {
            return true;
        }
    }
    return false;
}

bool Collider::isInteractiveElementCollided(int playerX, int playerY, int playerWidth, int playerHeight)
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

bool Collider::isBlockingElementExist(int x, int y, int width, int height)
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

bool Collider::isInteractiveElementExist(int x, int y, int width, int height)
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