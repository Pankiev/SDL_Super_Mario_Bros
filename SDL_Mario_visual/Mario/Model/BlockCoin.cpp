
#include "BlockCoin.h"
#include "../Controller/MarioGame.h"

BlockCoin::BlockCoin(MarioGame& game):AbstractMob(game)
{
    animateInit();
    setTexture(TEXTURE_COIN_BOX_1);
    queryTexture();
    existTimer_.setActionsPerSec(2.9f);
    once_ = true;
    setMoveSpeed(400.0f);
    gravityFactor_ = 4.20f;
    setCollisionRect(1,1,0,0);
}

void BlockCoin::animateInit()
{
    exist_.addTexture(game_.getTexture(TEXTURE_COIN_BOX_1));
    exist_.addTexture(game_.getTexture(TEXTURE_COIN_BOX_2));
    exist_.addTexture(game_.getTexture(TEXTURE_COIN_BOX_3));
    exist_.addTexture(game_.getTexture(TEXTURE_COIN_BOX_4));

    exist_.animateInit(10.0f);
}

void BlockCoin::action()
{
    doOnce();

    exist_.animate();
    Object::setTexture(exist_.getTexture());

    noCollGravityHandle();

    existTimer_.calculateTime();
    if(existTimer_.askForAction())
        die();
}

void BlockCoin::doOnce()
{
    if(once_)
    {
        setShowingX(getShowingRect().x + 8);
        once_ = false;
        game_.addCoin();
        existTimer_.reset();
    }
}

int BlockCoin::getValue() const
{
    return VALUE_COIN;
}


