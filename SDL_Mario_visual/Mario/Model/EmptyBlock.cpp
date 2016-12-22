
#include "EmptyBlock.h"
#include "../Controller/MarioGame.h"

EmptyBlock::EmptyBlock(MarioGame& game):ActiveBlock(game, TEXTURE_EMPTY_BOX)
{
    hopOnce_ = true;
}

void EmptyBlock::action()
{
    hopOnce();

    //SDL_Rect rect1 = getShowingRect();
    //SDL_Rect rect2 = getCollisionRect();
    ActiveBlock::action();
    if(!(isHopping()))
    {
        Block* b1 = new Block(game_, TEXTURE_EMPTY_BOX);
        b1->setShowingRect(getShowingRect());
        b1->setCollisionRect(getCollisionRect());
        game_.addToGame(b1);
        die();
        game_.getCollsionMap()->update(b1);
    }
}

void EmptyBlock::hopOnce()
{
    if(hopOnce_)
    {
        hop();
        hopOnce_ = false;
    }
}
