#pragma once

#include <SDL.h>

class AbstractMob;

class AnimationSet
{
public:

    AnimationSet(AbstractMob& owner);
    virtual ~AnimationSet(){};

    virtual SDL_Texture* animateWalk(){return nullptr;}
    virtual SDL_Texture* animateStand(){return nullptr;}
    virtual SDL_Texture* animateDie(){return nullptr;}
    virtual SDL_Texture* animateJump(){return nullptr;}
    virtual void setTextures()=0;

protected:

    AbstractMob& owner_;
};
