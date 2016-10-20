
#include "GoombasBrownAnimation.h"
#include "MarioGame.h"

GoombasBrownAnimation::GoombasBrownAnimation(AbstractMob& owner):GoombasAnimation(owner)
{

}

void GoombasBrownAnimation::setTextures()
{
    MarioGame& game = owner_.getWorld();
    die_ = game.getTexture(TEXTURE_GOOMBAS1DEAD);

    walk_.addTexture(game.getTexture(TEXTURE_GOOMBAS1MOVE_1));
    walk_.addTexture(game.getTexture(TEXTURE_GOOMBAS1MOVE_2));

    walk_.animateInit(10.0f);
}
