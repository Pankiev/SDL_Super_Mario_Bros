
#pragma once

#include "AnimationSet.h"
#include "../../Model/ManyPicAnimation.h"

class AbstractMob;

class GoombasAnimation : public AnimationSet
{
public:

    GoombasAnimation(AbstractMob& owner);

    SDL_Texture* animateWalk() override;
    SDL_Texture* animateDie() override;
    virtual void setTextures() override=0;

protected:

    ManyPicAnimation walk_;
    SDL_Texture* die_;
};
