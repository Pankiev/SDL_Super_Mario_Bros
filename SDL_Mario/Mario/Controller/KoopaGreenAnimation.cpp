
#include "KoopaGreenAnimation.h"
#include "MarioGame.h"

KoopaGreenAnimation::KoopaGreenAnimation(AbstractMob& owner):KoopaAnimation(owner)
{

}

void KoopaGreenAnimation::setTextures()
{
    MarioGame& game = owner_.getWorld();

    walk_.addTexture(game.getTexture(TEXTURE_KOOPA1_WALK_1));
    walk_.addTexture(game.getTexture(TEXTURE_KOOPA1_WALK_2));

    walk_.animateInit(15.0f);

    jump_.addTexture(game.getTexture(TEXTURE_KOOPA1_JUMP_1));
    jump_.addTexture(game.getTexture(TEXTURE_KOOPA1_JUMP_2));

    jump_.animateInit(15.0f);

    revive_.addTexture(game.getTexture(TEXTURE_KOOPA1_WALK_1));
    revive_.addTexture(game.getTexture(TEXTURE_KOOPA1_SHELL_MODE));

    revive_.animateInit(8.0f);

    shellMode_ = game.getTexture(TEXTURE_KOOPA1_SHELL_MODE);
}
