
#include "AnimatingUnknownBlock.h"
#include "../Controller/MarioGame.h"

AnimatingUnknownBlock::AnimatingUnknownBlock(MarioGame& game, AbstractMob* content)
:UnknownBlock(game, TEXTURE_UNKNOWN_BOX1_1)
{
    content_ = content;
    animationInit();
}

void AnimatingUnknownBlock::action()
{
    exist_.animate();
    Object::setTexture(exist_.getTexture());
}


void AnimatingUnknownBlock::animationInit()
{
    exist_.addTexture(game_.getTexture(TEXTURE_UNKNOWN_BOX1_1));
    exist_.addTexture(game_.getTexture(TEXTURE_UNKNOWN_BOX1_1));
    exist_.addTexture(game_.getTexture(TEXTURE_UNKNOWN_BOX1_1));
    exist_.addTexture(game_.getTexture(TEXTURE_UNKNOWN_BOX1_2));
    exist_.addTexture(game_.getTexture(TEXTURE_UNKNOWN_BOX1_3));
    exist_.addTexture(game_.getTexture(TEXTURE_UNKNOWN_BOX1_2));

    exist_.animateInit(7.5f);
}
