
#include "KoopaAnimation.h"

KoopaAnimation::KoopaAnimation(AbstractMob& owner):AnimationSet(owner)
{
    shellMode_ = nullptr;
}

SDL_Texture* KoopaAnimation::animateWalk()
{
    walk_.animate();
    return walk_.getTexture();
}

SDL_Texture* KoopaAnimation::animateJump()
{
    jump_.animate();
    return jump_.getTexture();
}

SDL_Texture* KoopaAnimation::animateStand()
{
    return shellMode_;
}

SDL_Texture* KoopaAnimation::animateRevive()
{
    revive_.animate();
    return revive_.getTexture();
}

