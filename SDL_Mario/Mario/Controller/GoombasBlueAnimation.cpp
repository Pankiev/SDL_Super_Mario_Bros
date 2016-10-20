
#include "GoombasBlueAnimation.h"
#include "MarioGame.h"

GoombasBlueAnimation::GoombasBlueAnimation(AbstractMob& owner):GoombasAnimation(owner)
{

}

void GoombasBlueAnimation::setTextures()
{
    MarioGame& game = owner_.getWorld();
    die_ = game.getTexture(TEXTURE_GOOMBAS_BLUE_DEAD);

    walk_.addTexture(game.getTexture(TEXTURE_GOOMBAS_BLUE_MOVE_1));
    walk_.addTexture(game.getTexture(TEXTURE_GOOMBAS_BLUE_MOVE_2));

    walk_.animateInit(10.0f);
}
