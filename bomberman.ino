#include <Gamebuino-Meta.h>
#include "player.hpp"
#include "graphics.hpp"
#include "debug_framework.hpp"

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

    playground::collider.drawBlockingElement(62, 42, 2, 20);
    playground::collider.drawBlockingElement(62, 72, 20, 2);
    playground::collider.drawInteractiveElement(30, 30, 1, 1);

    // gb.display.setColor(WHITE);
    // gb.display.fillRect(heroMapCoordinates::x, heroMapCoordinates::y, heroMapCoordinates::width, heroMapCoordinates::height);
    // if (playground::collider.isInteractiveElementCollided(
    //         playerContactPoints[0].first,
    //         playerContactPoints[0].second,
    //         16,
    //         16) or
    //     playground::collider.isInteractiveElementCollided(
    //         playerContactPoints[1].first,
    //         playerContactPoints[1].second,
    //         16,
    //         16) or
    //     playground::collider.isInteractiveElementCollided(
    //         playerContactPoints[2].first,
    //         playerContactPoints[2].second,
    //         16,
    //         16) or
    //     playground::collider.isInteractiveElementCollided(
    //         playerContactPoints[3].first,
    //         playerContactPoints[3].second,
    //         16,
    //         16))
    // {
    //     debugFramework("XDDDDDDDD");
    //     debugFramework("punkty stykowe: ", 5, 5);
    //     debugFramework()
    //     // gb.display.setColor(BLACK);
    //     // gb.display.fillRect(0, 0, screenDimension::lowResWidth, screenDimension::lowResHeight);
    //     // menu.display();
    // }
    // else
    // {
    //     debugFramework("nope");
    // }

    if (playground::collider.isInteractiveElementCollided(
            playerContactPoints[0].first,
            playerContactPoints[0].second,
            10,
            14))
    {
        debugFramework("XDDDDDDDD");
        debugFramework("punkty stykowe: ", 5, 5);
        debugFramework(playerContactPoints[0].first, 5, 12);
        debugFramework(playerContactPoints[0].second, 17, 12);
    }
    else
    {
        debugFramework("nope");
    }

    // debugFramework(playerX, 90, 90);
    // debugFramework(playerY, 95, 95);
    debugFramework(playerContactPoints, 95, 95);
}