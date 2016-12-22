
#include "DebrisRed.h"
#include "../Controller/MarioGame.h"

DebrisRed::DebrisRed(MarioGame& game, float upwardForce, int horizontalDirection)
:Debris(game, upwardForce, horizontalDirection)
{
    setLookout();
}

void DebrisRed::setLookout()
{
    setTexture(TEXTURE_DEBRIS1);
}
