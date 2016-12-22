
#include "HiddenUnkownBlock.h"
#include "../Controller/MarioGame.h"

HiddenUnknownBlock::HiddenUnknownBlock(MarioGame& game, AbstractMob* content)
:UnknownBlock(game, content)
{
    once_ = true;
    stopRendering();
}

void HiddenUnknownBlock::action()
{
    doOnce();

    if(askForActivate())
        activate();
}

void HiddenUnknownBlock::doOnce()
{
    if(once_)
    {
        once_ = false;
        activateRect_ = getShowingRect();
        activateRect_.y = activateRect_.y + activateRect_.h;
        activateRect_.h = 10;
        game_.getCollsionMap()->clearColl(getCollisionRect());
    }
}

bool HiddenUnknownBlock::askForActivate()
{
    Mario* mario = game_.getMainChar();
    CollisionMap* map = game_.getCollsionMap();
    SDL_Rect marioRect = mario->getCollisionRect();

    if( (map->isPointInRect({marioRect.x, marioRect.y}, activateRect_) ||
        map->isPointInRect({marioRect.x+marioRect.w-1, marioRect.y}, activateRect_) )
        && mario->getGravityFactor() > 0.0f)
        return true;

    return false;
}

void HiddenUnknownBlock::activate()
{
    game_.getMainChar()->setGravityFactor(0.0f);
    UnknownBlock::marioHit();
}
