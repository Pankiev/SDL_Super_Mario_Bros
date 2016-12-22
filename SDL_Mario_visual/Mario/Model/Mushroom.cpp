
#include "Mushroom.h"
#include"../Controller/MarioGame.h"

Mushroom::Mushroom(MarioGame& game):BlockItem(game)
{
    setTexture(TEXTURE_MUSHROOM);
    queryTexture();
    setMoveSpeed(130.0f);
}

void Mushroom::die()
{
    AbstractMob::die();
    game_.playSoundEfx(CHUNKSOUND_MARIO_GROW);
}

void Mushroom::marioTouch()
{
    game_.getMainChar()->levelUp();
    die();
}

void Mushroom::blockHopped()
{
    jump();
}

int Mushroom::getValue() const
{
    return POINTS_MUSHROOM;
}

void Mushroom::jump()
{
    if(!(isInAir()))
        gravityFactor_ = 3.25f;
}
