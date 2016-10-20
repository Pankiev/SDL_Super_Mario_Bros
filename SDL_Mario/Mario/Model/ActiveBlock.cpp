
#include "ActiveBlock.h"
#include "../Controller/MarioGame.h"
#include "DebrisRed.h"
#include "DebrisBlue.h"

ActiveBlock::ActiveBlock(MarioGame& game, int BLOCK_TYPE):Block(game, BLOCK_TYPE)
{
    hop_ = false;
    hopCurrentDir_ = UP;
    hopTimer_.setActionsPerSec(10.0f);
}

ActiveBlock::ActiveBlock(MarioGame& game):Block(game)
{
    hop_ = false;
    hopCurrentDir_ = UP;
    hopTimer_.setActionsPerSec(10.0f);
}
//q
void ActiveBlock::action()
{
    if(hop_)
    {
        hopTimer_.calculateTime();
        if(hopTimer_.askForAction())
        {
            if(hopCurrentDir_ == UP)
            {
                hopCurrentDir_ = DOWN;
            }
            else if(hopCurrentDir_ == DOWN)
            {
                hop_ = false;
                repositionObjectCollision(*game_.getCollsionMap(), initialColl_.x, initialShow_.y+2);
                rectShow_ = initialShow_;
            }
        }
        if(hop_)
            moveAnyway(*game_.getCollsionMap(), hopCurrentDir_, game_.getTimeFactor());
    }
}

void ActiveBlock::hop()
{
    if(!(hop_))
    {
        hop_ = true;
        hopTimer_.reset();
        hopCurrentDir_ = UP;
        initialColl_ = rectCollision_;
        initialShow_ = rectShow_;
    }
    hopStandingOnBlock();
}

void ActiveBlock::destroy()
{
    createDebris();
    game_.playSoundEfx(CHUNKSOUND_BLOCK_BREAK, PLAY_ONCE);
    die();
    hopStandingOnBlock();
}

void ActiveBlock::createDebris()
{
    game_.addToGame(createDebris(6.0f, LEFT));
    game_.addToGame(createDebris(4.0f, LEFT));
    game_.addToGame(createDebris(6.0f, RIGHT));
    game_.addToGame(createDebris(4.0f, RIGHT));
}

Debris* ActiveBlock::createDebris(float upwardForce, int horizontalMoveDirection)
{
    Debris* debris;
    if(currentTexture_ == game_.getTexture(TEXTURE_BRICK_2))
        debris = new DebrisBlue(game_, upwardForce, horizontalMoveDirection);
    else
        debris = new DebrisRed(game_, upwardForce, horizontalMoveDirection);

    debris->setShowingPosition(rectShow_.x, rectShow_.y);
    return debris;
}

void ActiveBlock::hopStandingOnBlock()
{
    GameBase* coll = (GameBase*)game_.getCollsionMap()->checkForSpace(1,UP,getCollisionRect());
    if(coll != nullptr && coll->isMob())
        ((Mob*)coll)->blockHopped();
}

void ActiveBlock::marioHit()
{
    if(!(hop_))
    {
        int marioType = game_.getMainChar()->getMarioType();
        if(marioType == MARIO_SMALL)
            hop();
        else
            destroy();
    }

    Block::marioHit();
}

bool ActiveBlock::isHopping()
{
    return hop_;
}

int ActiveBlock::getValue() const
{
    return VALUE_BLOCK;
}
