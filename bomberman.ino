#include <Gamebuino-Meta.h>
#include "graphics.hpp"
#include "debug_framework.hpp"
#include "global_variables.hpp"
#include "input_handler.hpp"
#include "timer.h"
#include "playground.hpp"

Player player;

void setup()
{
    gb.begin();
    gb.setFrameRate(60);
    gb.display.setPalette(PALETTE);

    for (const auto &block : playground::cells)
    {
        if (block->isUndestroyableStonePlacedOnCell)
            collider::drawBlockingElement(block->coordinate.x, block->coordinate.y, block->coordinate.width, block->coordinate.height);
    }
    for (const auto &border : playground::borders)
    {
        collider::drawBlockingElement(border.x, border.y, border.width, border.height);
    }
    playground::setCrossPatternNeighbors();
}

void loop()
{
    while (!gb.update())
    {
    }
    gb.display.clear();

    gb.display.drawImage(0, 0, sprite::playgroundBackground);
    for (const auto &cell : playground::cells)
    {
        if (cell->isDestroyableBlockPlacedOnCell)
        {
            gb.display.drawImage(cell->coordinate.x, cell->coordinate.y, sprite::block);
            collider::drawBlockingElement(cell->coordinate.x, cell->coordinate.y, cell->coordinate.width, cell->coordinate.height);
        }
    }

    playerMoveEngine();

    if (playground::bomb != nullptr)
    {
        static bool flag = false;
        static int x, y;
        if (!flag)
        {
            x = player.x + 8;
            y = player.y + 8;
            flag = true;
        }
        playground::bomb->drawBomb(playground::findNearestCell(x, y));
        printNumber(timeCounter, 100, 100);
        gb.sound.play("explosion.wav");

        if (isTimeElapsed(10))
        {
            printText("!!", 100, 100);
        }
        if (isTimeElapsed(20))
        {
            printText("!!!", 100, 100);
        }
        if (isTimeElapsed(60))
        {
            printText("!!!!!!", 100, 100);
        }
        if (isTimeElapsed(70))
        {
            playground::bomb.reset();
            timeCounter = 0;
            flag = false;
        }
    }
}