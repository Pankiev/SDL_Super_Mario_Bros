
#include "DebrisBlue.h"
#include "../Controller/MarioGame.h"

DebrisBlue::DebrisBlue(MarioGame& game, float upwardForce, int horizontalDirection)
:Debris(game, upwardForce, horizontalDirection)
{
    setLookout();
}

void DebrisBlue::setLookout()
{
    setTexture(TEXTURE_DEBRIS2);
}
