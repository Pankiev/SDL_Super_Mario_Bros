
#include "LevelUpFlower.h"
#include "../Controller/MarioGame.h"

LevelUpFlower::LevelUpFlower(MarioGame& game):Mushroom(game)
{
    setMoveSpeed(100.0f);
    setTexture(TEXTURE_FLOWER_1);
    exist_.addTexture(game_.getTexture(TEXTURE_FLOWER_1));
    exist_.addTexture(game_.getTexture(TEXTURE_FLOWER_2));
    exist_.addTexture(game_.getTexture(TEXTURE_FLOWER_3));
    exist_.addTexture(game_.getTexture(TEXTURE_FLOWER_4));

    exist_.animateInit(15.0f);
}

void LevelUpFlower::action()
{
    BlockItem::action();
    exist_.animate();
    Object::setTexture(exist_.getTexture());
    if(!invincibilityMove_)
    {
        setMoveSpeed(0.0f);
    }
}

