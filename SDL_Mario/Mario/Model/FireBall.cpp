
#include "FireBall.h"
#include "FireWork.h"
#include "../Controller/MarioGame.h"

FireBall::FireBall(MarioGame& game):Mob(game)
{
    setTexture(TEXTURE_FIREBALL_1);
    queryTexture();
    setMoveSpeed(400.0f);
    animateInit();
    gravityFactor_ = -1.35f;
    specifyMoveDirection();
    actionActivate();
}

void FireBall::animateInit()
{
    exist_.addTexture(game_.getTexture(TEXTURE_FIREBALL_1));
    exist_.addTexture(game_.getTexture(TEXTURE_FIREBALL_2));
    exist_.addTexture(game_.getTexture(TEXTURE_FIREBALL_3));
    exist_.addTexture(game_.getTexture(TEXTURE_FIREBALL_4));

    exist_.animateInit(15.0f);
}

void FireBall::action()
{
    jump();
    Mob::action();
    exist_.animate();
    Object::setTexture(exist_.getTexture());

}

void FireBall::jump()
{
    if(!isInAir())
        gravityFactor_ = 1.55f;

    if(gravityFactor_ < -1.35f)
        gravityFactor_ = -1.35f;
}

void FireBall::die()
{
    dieFirstPart();
    createFirework();
    game_.playSoundEfx(CHUNKSOUND_BLOCK_HIT);
    GameBase::die();
}

void FireBall::createFirework()
{
    FireWork* firework = new FireWork(game_);
    firework->setShowingPosition(rectShow_.x - 5, rectShow_.y - 5);
    game_.addToGame(firework);
}

void FireBall::specifyMoveDirection()
{
    Mario* mario = game_.getMainChar();

    if(mario->getFlipMode() == SDL_FLIP_NONE)
        currentDirection_ = RIGHT;
    else
        currentDirection_ = LEFT;
}

void FireBall::anyObjectHorizontalMoveTouch()
{
    die();
}

void FireBall::otherMobTouch(Mob* otherMob)
{
    die();
    otherMob->die();
}
