
#include "AbstractMob.h"
#include "../Controller/MarioGame.h"
#include "PointsString.h"

AbstractMob::AbstractMob(MarioGame& game):GameBase(game)
{
    animations_ = nullptr;
    isAlive_ = true;
    gravityFactor_ = 0.0f;
    setName("Mob");
    invincibilityMove_ = false;
    invStopPoint_ = {0,0};
    invInitialColl_ = {0,0,0,0};
    invInitialObject_ = nullptr;
}

AbstractMob::~AbstractMob()
{
    if(animations_ != nullptr)
    {
        delete animations_;
        animations_ = nullptr;
    }
}

void AbstractMob::die()
{
    createPointsObject();
    GameBase::die();
}

bool AbstractMob::isInvincibleMoving()
{
    return invincibilityMove_;
}


void AbstractMob::setAnimations(AnimationSet* animations)
{
    animations_ = animations;
    animations_->setTextures();
}

void AbstractMob::action()
{
    gravityHandle();
}

Object* AbstractMob::gravityHandle()
{
    gravityFactor_-=8.0f*game_.getTimeFactor();
    CollisionMap* map = game_.getCollsionMap();
    Object* coll;
    float tempMoveSpeed = moveSpeed_;
    moveSpeed_ *= gravityFactor_;
    int moveDirection;

    if(gravityFactor_ <= 0.0f)
        moveDirection = DOWN;
    else
        moveDirection = UP;


    coll = move(*map, moveDirection, game_.getTimeFactor());
    if(coll != nullptr)
    {
        gravityFactor_ = 0.0f;
        touchObject(moveDirection);
    }

    moveSpeed_ = tempMoveSpeed;
    return coll;
}

void AbstractMob::jump()
{
    if(!(isInAir()))
        gravityFactor_ = 3.5f;
}

bool AbstractMob::isInAir()
{
    CollisionMap* map = game_.getCollsionMap();
    Object* coll = map->checkForSpace(1, DOWN, getCollisionRect());
    if(coll == nullptr)
        return true;

    return false;
}

Object* AbstractMob::walk(int direction)
{
    if(animations_ != nullptr && !(isInAir()))
        Object::setTexture(animations_->animateWalk());

    Object* coll = move(*game_.getCollsionMap(), direction, game_.getTimeFactor());

    if(coll != nullptr)
        touchObject(direction);

    return coll;
}

MarioGame& AbstractMob::getWorld()
{
    return game_;
}

void AbstractMob::noCollGravityHandle()
{
    gravityFactor_-=20.0f*game_.getTimeFactor();
    float tempMoveSpeed = moveSpeed_;
    moveSpeed_ *= gravityFactor_;

    if(gravityFactor_ <= 0.0f)
        move(DOWN, game_.getTimeFactor());
    else
        move(UP, game_.getTimeFactor());

    moveSpeed_ = tempMoveSpeed;
}

Object* AbstractMob::touchObject(int direction)
{
    CollisionMap* map = game_.getCollsionMap();
    Object* coll = nullptr;
    do
    {
        coll = move(*map, direction, 1);
    }while(coll == nullptr); // loop making object touch previously detected object
    return coll;
}

void AbstractMob::createPointsObject()
{
    if(getValue() > 0)
    {
        PointsString* p1 = new PointsString(game_, getValue());
        p1->setBothPosition(getShowingRect().x, getShowingRect().y);
        addPoints();
        game_.addToGame(p1);
    }
}

void AbstractMob::invincibilityMove(SDL_Point stopPoint)
{
    invincibilityMove_ = true;
    invStopPoint_ = stopPoint;
    invInitialColl_ = getCollisionRect();
    invInitialObject_ = game_.getCollsionMap()->getObjectInPosition(rectShow_.x + rectShow_.w/2, rectShow_.y + rectShow_.h/2);
    game_.getCollsionMap()->clearColl(getCollisionRect());
    setCollisionHeight(0);
    setCollisionWidth(0);
}

void AbstractMob::invincibilityMoveHandle()
{
    CollisionMap* map = game_.getCollsionMap();

    if(map->isPointInRect(invStopPoint_, getShowingRect()))
        stopInvincibleMoving();
    else
    {
        if(invStopPoint_.x > rectShow_.x)
            move(RIGHT, game_.getTimeFactor());
        else if(invStopPoint_.x < rectShow_.x)
            move(LEFT, game_.getTimeFactor());

        if(invStopPoint_.y > rectShow_.y)
            move(DOWN, game_.getTimeFactor());
        else if(invStopPoint_.y < rectShow_.y)
            move(UP, game_.getTimeFactor());
    }
}

float AbstractMob::getGravityFactor()
{
    return gravityFactor_;
}

void AbstractMob::setGravityFactor(float gravityFactor)
{
    gravityFactor_ = gravityFactor;
}

void AbstractMob::stopInvincibleMoving()
{
    CollisionMap* map = game_.getCollsionMap();
    invincibilityMove_ = false;
    setGravityFactor(0.0f);//weird
    setCollisionHeight(invInitialColl_.h);
    setCollisionWidth(invInitialColl_.w);
    setCollisionRect(getShowingRect());
    map->update(this);
    if(invInitialObject_ != nullptr)
        map->update(invInitialObject_);
}

AnimationSet* AbstractMob::getAnimation()
{
    return animations_;
}
