
#include "Debris.h"
#include "../Controller/MarioGame.h"

Debris::Debris(MarioGame& game, float upwardForce, int horizontalDirection):AbstractMob(game)
{
    setMoveSpeed(100.0f);
    gravityFactor_ = upwardForce;
    horizontalMoveDirection_ = horizontalDirection;
    imageFlipTimer_.setActionsPerSec(8.0f);
    imageFlipTimer_.reset();
    aliveTimer_.setActionsPerSec(0.5f);
    aliveTimer_.reset();
    setCollisionRect({0,0,0,0});
    setShowingRect(0,0,16,16);
}

void Debris::action()
{
    noCollGravityHandle();
    aliveTimer_.calculateTime();
    move(horizontalMoveDirection_, game_.getTimeFactor());
    if(aliveTimer_.askForAction())
        die();

    flipImage();
}

void Debris::flipImage()
{
    imageFlipTimer_.calculateTime();
    if(imageFlipTimer_.askForAction())
    {
        if(getFlipMode() == SDL_FLIP_NONE)
            setFlipMode(SDL_FLIP_HORIZONTAL);
        else
            setFlipMode(SDL_FLIP_NONE);
    }
}
