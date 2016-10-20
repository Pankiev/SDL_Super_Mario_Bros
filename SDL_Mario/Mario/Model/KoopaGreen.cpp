
#include "KoopaGreen.h"
#include "../Controller/KoopaGreenAnimation.h"

KoopaGreen::KoopaGreen(MarioGame& game):Koopa(game, new KoopaGreenAnimation(*this))
{

}
