#include <Gamebuino-Meta.h>
#include "player.hpp"
#include "graphics.hpp"

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

    gb.display.drawImage(0, 0, background);
    playerMove();
}