
#include "GoombasBlue.h"
#include "../Controller/GoombasBlueAnimation.h"
#include "../Controller/MarioGame.h"

GoombasBlue::GoombasBlue(MarioGame& game)
:Goombas(game, new GoombasBlueAnimation(*this))
{
    setTexture(TEXTURE_GOOMBAS_BLUE_MOVE_1);
}
