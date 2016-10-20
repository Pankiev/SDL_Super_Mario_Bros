
#include "MoneyBlock.h"
#include "../Controller/MarioGame.h"
#include "BlockCoin.h"
#include "EmptyBlock.h"

MoneyBlock::MoneyBlock(MarioGame& game):MoneyBlock(game, TEXTURE_MARIO_BRICK_RED)
{

}

MoneyBlock::MoneyBlock(MarioGame& game, int BLOCK_TYPE):ActiveBlock(game, BLOCK_TYPE)
{
    popCoinsTimer_.setActionsPerSec(0.2f);
    resetTimer_ = true;
}


void MoneyBlock::marioHit()
{
    resetTimerOnce();
    if(!isHopping())
        hop();

    BlockCoin* b1 = new BlockCoin(game_);
    b1->setBothPosition(getShowingRect().x, getShowingRect().y);
    game_.addToGame(b1);

    popCoinsTimer_.calculateTime();
    if((popCoinsTimer_.askForAction()))
    {
        EmptyBlock* e1 = new EmptyBlock(game_);
        e1->setShowingRect(getShowingRect());
        e1->setCollisionRect(getCollisionRect());
        game_.addToGame(e1);
        die();
    }
    Block::marioHit();
}

void MoneyBlock::resetTimerOnce()
{
    if(resetTimer_)
    {
        resetTimer_ = false;
        popCoinsTimer_.reset();
    }
}
