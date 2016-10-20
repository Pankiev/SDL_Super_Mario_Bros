
#include "BrowserAnimation.h"
#include "MarioGame.h"

BrowserAnimation::BrowserAnimation(AbstractMob& owner):AnimationSet(owner)
{

}

void BrowserAnimation::setTextures()
{
    MarioGame& game = owner_.getWorld();

    walk_.addTexture(game.getTexture(TEXTURE_BROWSER_MOVE_1));
    walk_.addTexture(game.getTexture(TEXTURE_BROWSER_MOVE_2));

    walk_.animateInit(7.5f);

    shotWalk_.addTexture(game.getTexture(TEXTURE_BROWSER_SHOT_MOVE_1));
    shotWalk_.addTexture(game.getTexture(TEXTURE_BROWSER_SHOT_MOVE_2));

    shotWalk_.animateInit(7.5f);
}

SDL_Texture* BrowserAnimation::animateShotWalk()
{
    shotWalk_.animate();
    return shotWalk_.getTexture();
}

SDL_Texture* BrowserAnimation::animateWalk()
{
    walk_.animate();
    return walk_.getTexture();
}
