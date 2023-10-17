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
    gb.display.drawImage(41, 41, animationIdle);
    gb.display.drawImage(81, 81, animationWalkDown);
    gb.display.drawImage(61, 61, animationWalkLeft);
    gb.display.drawImage(101, 101, animationWalkRight);
    gb.display.drawImage(121, 40, animationWalkUp);
}