#include <Gamebuino-Meta.h>
#include "graphics.hpp"
#include "debug_framework.hpp"
#include "global_variables.hpp"
#include "input_handler.hpp"
#include "playground.hpp"

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

    playerMove();

    if (playground::bomb != nullptr)
    {
        playground::bomb->drawBomb(playground::walkableCells[playground::findNearestCell(player.x + 8, player.y + 8)].centralPoint.first, playground::walkableCells[playground::findNearestCell(player.x + 8, player.y + 8)].centralPoint.second);
        // collider::drawInteractiveElement(playground::bomb->coordinate.x, playground::bomb->coordinate.y, 16, 16);
        // printNumber(collider::isInteractiveElementColliding(playground::bomb->coordinate.x, playground::bomb->coordinate.y, player.x, player.y));
    }
    // printNumber(playground::findNearestCell(player.x + 8, player.y + 8));
    // drawDot(playground::walkableCells[playground::findNearestCell(player.x + 8, player.y + 8)].centralPoint.first, playground::walkableCells[playground::findNearestCell(player.x + 8, player.y + 8)].centralPoint.second);
}