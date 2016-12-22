
#include "KoopaBlue.h"
#include "../Controller/KoopaBlueAnimation.h"
#include "../Controller/MarioGame.h"

KoopaBlue::KoopaBlue(MarioGame& game):Koopa(game, new KoopaBlueAnimation(*this))
{
    setTexture(TEXTURE_KOOPA2_WALK_1);
}
