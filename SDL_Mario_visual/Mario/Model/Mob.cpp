
#include "Mob.h"
#include "../Controller/MarioGame.h"

Mob::Mob(MarioGame& game):AbstractMob(game)
{
    currentDirection_ = LEFT;
    dying_ = false;
    dieTimer_.setActionsPerSec(1.0f);
    setLayer(5);
}

void Mob::action()
{
    movedByPlatform_ = false;
    if(!(dying_))
    {
        Object* coll = walk(currentDirection_);

        objectCollsionHandle(coll);

        if(!isAlive()) return;

        if(coll != nullptr)
            anyObjectHorizontalMoveTouch();

        if(isGravityActive())
        {
            coll = gravityHandle();
            objectCollsionHandle(coll);
        }
    }
    else
    {
        move(RIGHT, game_.getTimeFactor());
        noCollGravityHandle();
        dieTimer_.calculateTime();
        if(dieTimer_.askForAction())
            GameBase::die();
    }
}

void Mob::die()
{
    dieFirstPart();
    gravityFactor_ = 3.0f;
    setMoveSpeed(150.0f);
    setFlipMode(SDL_FLIP_VERTICAL);
    game_.playSoundEfx(CHUNKSOUND_MOB_HIT, PLAY_ONCE);
}

bool Mob::isDying()
{
    return dying_;
}

void Mob::dieFirstPart()
{
    dying_ = true;
    game_.getCollsionMap()->clearColl(getCollisionRect());
    setCollisionRect({0,0,0,0});
    dieTimer_.reset();
    createPointsObject();
}

void Mob::marioTouch()
{
    if(game_.getMainChar()->isInvincible())
        die();
    else
        game_.getMainChar()->marioHit();
}

void Mob::objectCollsionHandle(Object* collsionObject)
{
    if(collsionObject != nullptr)
    {
        if(collsionObject->getId() != BORDER_ID)
        {
            if(collsionObject->getId() == MARIO_ID)
                marioTouch();
            else if(((GameBase*)collsionObject)->isMob())
                otherMobTouch(dynamic_cast<Mob*>(collsionObject));
        }
        else
            GameBase::die();
    }
}

void Mob::touchedByMario()
{
    marioTouch();
}

void Mob::blockHopped()
{
    die();
}

void Mob::turnAround()
{
    if(currentDirection_ == LEFT)
    {
        currentDirection_ = RIGHT;
        setFlipMode(SDL_FLIP_HORIZONTAL);
    }
    else if(currentDirection_ == RIGHT)
    {
        currentDirection_ = LEFT;
        setFlipMode(SDL_FLIP_NONE);
    }
}

void Mob::anyObjectHorizontalMoveTouch()
{
    turnAround();
}

void Mob::setCurrentMoveDirection(int newDirection)
{
    currentDirection_ = newDirection;
}
