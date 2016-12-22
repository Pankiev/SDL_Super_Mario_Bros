
#pragma once

#include "AnimationSet.h"
#include "../../Model/ManyPicAnimation.h"

class BrowserAnimation : public AnimationSet
{
public:

    BrowserAnimation(AbstractMob& owner);

    void setTextures();
    SDL_Texture* animateWalk() override;
    SDL_Texture* animateShotWalk();

private:

    ManyPicAnimation walk_;
    ManyPicAnimation shotWalk_;
};
