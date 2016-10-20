
#include "Star.h"
#include "../Controller/MarioGame.h"

Star::Star(MarioGame& game):BlockItem(game)
{
    setMoveSpeed(120.0f);
    setTexture(TEXTURE_STAR_1);
    queryTexture();
    animateInit();
}

void Star::animateInit()
{
    exist_.addTexture(game_.getTexture(TEXTURE_STAR_1));
    exist_.addTexture(game_.getTexture(TEXTURE_STAR_2));
    exist_.addTexture(game_.getTexture(TEXTURE_STAR_3));
    exist_.addTexture(game_.getTexture(TEXTURE_STAR_4));

    exist_.animateInit(15.0f);
}

void Star::action()
{
    exist_.animate();
    Object::setTexture(exist_.getTexture());
    jump();
    BlockItem::action();
}

void Star::marioTouch()
{
    game_.getMainChar()->invincibilityActivate();
    AbstractMob::die();
    game_.playSoundEfx(CHUNKSOUND_MARIO_GROW);
}

void Star::jump()
{
    if(!isInAir())
        gravityFactor_ = 4.7f;
}

int Star::getValue() const
{
    return VALUE_STAR;
}
