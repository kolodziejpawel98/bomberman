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
    // playerMove();
    debugFramework(playground::rocks[0].coordinates.first);
}