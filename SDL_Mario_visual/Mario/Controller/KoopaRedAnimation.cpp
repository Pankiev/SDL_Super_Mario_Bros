

#include "KoopaRedAnimation.h"
#include "MarioGame.h"

KoopaRedAnimation::KoopaRedAnimation(AbstractMob& owner):KoopaAnimation(owner)
{

}

void KoopaRedAnimation::setTextures()
{
    MarioGame& game = owner_.getWorld();

    walk_.addTexture(game.getTexture(TEXTURE_KOOPA3_WALK_1));
    walk_.addTexture(game.getTexture(TEXTURE_KOOPA3_WALK_2));

    walk_.animateInit(15.0f);

    jump_.addTexture(game.getTexture(TEXTURE_KOOPA3_JUMP_1));
    jump_.addTexture(game.getTexture(TEXTURE_KOOPA3_JUMP_2));

    jump_.animateInit(15.0f);

    revive_.addTexture(game.getTexture(TEXTURE_KOOPA3_WALK_1));
    revive_.addTexture(game.getTexture(TEXTURE_KOOPA3_SHELL_MODE));

    revive_.animateInit(8.0f);

    shellMode_ = game.getTexture(TEXTURE_KOOPA3_SHELL_MODE);
}
