#pragma once

#include "AnimationSet.h"
#include "../../Model/ManyPicAnimation.h"

class KoopaAnimation : public AnimationSet
{
public:

    KoopaAnimation(AbstractMob& owner);

    SDL_Texture* animateWalk();
    SDL_Texture* animateStand();
    SDL_Texture* animateJump();
    SDL_Texture* animateRevive();
    virtual void setTextures() override=0;

protected:

    ManyPicAnimation walk_;
    ManyPicAnimation jump_;
    ManyPicAnimation revive_;

    SDL_Texture* shellMode_;

};
