
#include "KoopaRed.h"
#include "../Controller/KoopaRedAnimation.h"
#include "../Controller/MarioGame.h"

KoopaRed::KoopaRed(MarioGame& game):Koopa(game, new KoopaRedAnimation(*this))
{
    setTexture(TEXTURE_KOOPA3_WALK_1);
}

void KoopaRed::action()
{
    Koopa::action();
    if(!isInShellMode())
        turnAroundIfNearEdge();
}

void KoopaRed::turnAroundIfNearEdge()
{
    if(isNearEdge())
        turnAround();
}

bool KoopaRed::isNearEdge()
{
    if(currentDirection_ == LEFT)
        return isNearEdgeOnLeftSide();
    else
        return isNearEdgeOnRightSide();
}

bool KoopaRed::isNearEdgeOnLeftSide()
{
    if(game_.getCollsionMap()->getObjectInPosition
       (rectShow_.x, rectShow_.y+rectShow_.h+1) == nullptr)
        return true;
    return false;
}

bool KoopaRed::isNearEdgeOnRightSide()
{
    if(game_.getCollsionMap()->getObjectInPosition
       (rectShow_.x+rectShow_.w-1, rectShow_.y+rectShow_.h+1) == nullptr)
        return true;
    return false;
}
