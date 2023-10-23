#include <Gamebuino-Meta.h>
#include "graphics.hpp"
#include "debug_framework.hpp"
#include "global_variables.hpp"
#include "input_handler.hpp"

Player player;

void setup()
{
    gb.begin();
    gb.setFrameRate(60);
    gb.display.setPalette(PALETTE);
}

void loop()
{
    while (!gb.update())
    {
    }
    gb.display.clear();

    // gb.display.drawImage(0, 0, sprite::playgroundBackground);
    playerMove();
    // playground::rocks[0].drawPlacehodler();

    // collider::drawBlockingElement(62, 42, 2, 20);
    // collider::drawBlockingElement(62, 72, 20, 2);
    collider::drawInteractiveElement(30, 30, 1, 1);

    if (collider::isInteractiveElementColliding(
            player.playerX,
            player.playerY,
            16,
            16))
    {
        printTextAndPair("punkty stykowe: ", player.playerX, player.playerY, 5, 5);
    }
    else
    {
        printText("nope");
    }

    // debugFramework(playerContactPoints, 95, 95);
}