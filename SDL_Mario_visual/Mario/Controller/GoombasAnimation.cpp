
#include "GoombasAnimation.h"
#include "MarioGame.h"

GoombasAnimation::GoombasAnimation(AbstractMob& owner):AnimationSet(owner)
{
    die_ = nullptr;
}


SDL_Texture* GoombasAnimation::animateDie()
{
    return die_;
}

SDL_Texture* GoombasAnimation::animateWalk()
{
    walk_.animate();
    return walk_.getTexture();
}
