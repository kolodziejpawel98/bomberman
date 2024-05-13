#include <Gamebuino-Meta.h>
#include "graphics.hpp"
#include "debug_framework.hpp"
#include "global_variables.hpp"
#include "input_handler.hpp"
// #include "playground.hpp"
#include "timer.h"
#include "weirdo_arduino.hpp"

Player player;

void setup()
{
    gb.begin();
    gb.setFrameRate(60);
    gb.display.setPalette(PALETTE);

    for (const auto &rock : playground::rocks)
    {
        collider::drawBlockingElement(rock.coordinate.x, rock.coordinate.y, rock.coordinate.width, rock.coordinate.height);
    }
    for (const auto &border : playground::borders)
    {
        collider::drawBlockingElement(border.x, border.y, border.width, border.height);
    }
}

void loop()
{
    while (!gb.update())
    {
    }
    gb.display.clear();

    gb.display.drawImage(0, 0, sprite::playgroundBackground);
    for (const auto &cell : playground::walkableCells)
    {
        if (cell.isDestroyableBlockPlacedOnCell)
        {
            gb.display.drawImage(cell.coordinate.x, cell.coordinate.y, sprite::block);
            collider::drawBlockingElement(cell.coordinate.x, cell.coordinate.y, cell.coordinate.width, cell.coordinate.height);
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
            printText("WTF F F F F !!!!", 100, 100);
            for (auto &cell : playground::allCells)
            {
                if (cell->isUndestroyableStonePlacedOnCell)
                {
                    cell->drawPlacehodler();
                }
            }
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