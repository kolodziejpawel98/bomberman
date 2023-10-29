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

    // playground::rocks[0].drawPlacehodler();

    // collider::drawBlockingElement(62, 42, 2, 20);
    // collider::drawBlockingElement(62, 72, 20, 2);
    // collider::drawInteractiveElement(30, 30, 1, 1);

    playerMove();

    // if (collider::isInteractiveElementColliding(
    //         player.colliderX,
    //         player.colliderY,
    //         player.colliderWidht,
    //         player.colliderHeight))
    // {
    //     printText("!!!styk!!!");
    // }
    // else
    // {
    //     printText("nope");
    // }
}