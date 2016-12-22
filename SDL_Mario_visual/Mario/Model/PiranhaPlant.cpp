
#include "PiranhaPlant.h"
#include "../Controller/MarioGame.h"

PiranhaPlant::PiranhaPlant(MarioGame& game):Mob(game)
{
    setMoveSpeed(40.0f);
    setTexture(TEXTURE_PIRANHA_PLANT_GREEN_1);
    queryTexture();
    currentVerticalDirection_ = UP;
    initialColl_ = getShowingRect();
    waitForMoveTimer_.setActionsPerSec(0.5f);
    exist_.animateInit(10.0f);
    moving_ = true;
    once_ = true;
}

void PiranhaPlant::action()
{
    copyInitialRectOnce();

    animate();
    if(isMoving())
    {
        Object* collision = move();
        handleCollision(collision);
        stopMovingIfConditionsFulfilled();
    }
    else
        timeAction();

}

void PiranhaPlant::copyInitialRectOnce()
{
    if(once_)
    {
        once_ = false;
        initialColl_ = getCollisionRect();
        setCollisionRect(calcUnrelatedCenterPoint().x-5, rectCollision_.y, 10, rectCollision_.h);
    }
}

void PiranhaPlant::animate()
{
    exist_.animate();
    Object::setTexture(exist_.getTexture());
}


bool PiranhaPlant::isMoving()
{
    return moving_;
}

Object* PiranhaPlant::move()
{
    return MobileObject::moveAnyway(*game_.getCollsionMap(), currentVerticalDirection_, game_.getTimeFactor());
}

void PiranhaPlant::handleCollision(Object* collision)
{
    if(isMario(collision))
        ((Mario*)collision)->marioHit();
}

bool PiranhaPlant::isMario(Object* testedObject)
{
    return testedObject == game_.getMainChar();
}


void PiranhaPlant::stopMovingIfConditionsFulfilled()
{
    if(stopMovingConditionsFulfilled())
        stopMoving();
}


bool PiranhaPlant::stopMovingConditionsFulfilled()
{
    if(currentVerticalDirection_ == UP)
    {
        if(rectCollision_.y <= initialColl_.y-initialColl_.h-32)
            return true;
    }
    else if(currentVerticalDirection_ == DOWN)
    {
        if(rectCollision_.y >= initialColl_.y)
            return true;
    }

    return false;
}

void PiranhaPlant::stopMoving()
{
    moving_ = false;
    waitForMoveTimer_.reset();
}

void PiranhaPlant::timeAction()
{
    if(restartMovingConditionsFulfilled())
    {
        restartMoving();
        revertMoveDirection();
    }
}

bool PiranhaPlant::restartMovingConditionsFulfilled()
{
    float distanceFromMario =
    CollisionMap::calcDistanceBetweenPoints(calcUnrelatedCenterPoint(),
                                        game_.getMainChar()->calcUnrelatedCenterPoint());
    bool adequateDistanceFromMario = distanceFromMario > 100.0f;
    bool distanceOrDirection = (adequateDistanceFromMario || currentVerticalDirection_ == UP);
    waitForMoveTimer_.calculateTime();
    return waitForMoveTimer_.askForAction() && distanceOrDirection;
}

void PiranhaPlant::restartMoving()
{
    moving_ = true;
}

void PiranhaPlant::revertMoveDirection()
{
    if(currentVerticalDirection_ == UP)
        currentVerticalDirection_ = DOWN;
    else
        currentVerticalDirection_ = UP;
}

void PiranhaPlant::marioJumped()
{
    game_.getMainChar()->marioHit();
}

void PiranhaPlant::die()
{
    AbstractMob::die();
    game_.playSoundEfx(CHUNKSOUND_MOB_HIT);
}




