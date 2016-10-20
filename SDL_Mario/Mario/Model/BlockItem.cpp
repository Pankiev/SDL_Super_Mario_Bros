
#include "BlockItem.h"
#include "../Controller/MarioGame.h"

BlockItem::BlockItem(MarioGame& game):Mob(game)
{
    doOnce_ = true;
    currentDirection_ = RIGHT;
    waitTimer_.setActionsPerSec(4.0f);
    active_ = false;
    stopRendering();
}

void BlockItem::action()
{
    doOnce();

    waitTimer_.calculateTime();

    if(active_)
    {
        if(invincibilityMove_)
            invincibilityMoveHandle();
        else
            Mob::action();
    }
    else if(waitTimer_.askForAction())
    {
        active_ = true;
        restartRendering();
        game_.addImage(this);
    }
}

void BlockItem::doOnce()
{
    if(doOnce_)
    {
        doOnce_ = false;
        invincibilityMove({rectShow_.x, rectShow_.y - getCollisionRect().h});
        game_.playSoundEfx(CHUNKSOUND_MUSHROOM_APPEAR);
        waitTimer_.reset();
    }
}

void BlockItem::marioJumped()
{
    marioTouch();
}
