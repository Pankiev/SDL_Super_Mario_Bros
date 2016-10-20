
#include <cstdlib>

#include "MovingPlatformElement.h"
#include "../Controller/MarioGame.h"

MovingPlatformElement::MovingPlatformElement(MarioGame& game):GameBase(game, TEXTURE_MOVING_PLATFORM)
{
    setMoveSpeed(DEFAULT_PLATROFM_MOVE_SPEED);
    queryTexture();
    moveAxis_ = PLATFORM_VERTICAL_MOVE;
    currentMoveDirection_ = UP;
    slideFactor_ = 0.0f;
    actionActivate();
}

void MovingPlatformElement::setCurrentMoveDirection(int newDirection)
{
    if(newDirection == UP || newDirection == DOWN)
        moveAxis_ = PLATFORM_VERTICAL_MOVE;
    else
        moveAxis_ = PLATFORM_HORIZONTAL_MOVE;

    currentMoveDirection_ = newDirection;
}

void MovingPlatformElement::action()
{
    Object* standingOnPlatform = game_.getCollsionMap()->checkForSpace(2, UP, getCollisionRect());
    Object* coll = move();
    while(coll != nullptr)
    {
        moveEncounteredObjects((GameBase*)coll);
        coll = move();
    }

    if(standingOnPlatform != nullptr);
        moveStandingOnPlatformObject((GameBase*)standingOnPlatform);

    if(moveAxis_ == PLATFORM_VERTICAL_MOVE && isOutOfVerticalPosition())
        repositionPlatform();

}

Object* MovingPlatformElement::move()
{
    return MobileObject::move(*game_.getCollsionMap(), currentMoveDirection_, 1);
}

void MovingPlatformElement::moveStandingOnPlatformObject(GameBase* object)
{
    if(!(object->wasMovedByPlatformInThisTurn()))
    {
        if(currentMoveDirection_ != DOWN)
            object->move(*game_.getCollsionMap(), currentMoveDirection_, 1);
        else
        {
            Object* coll = object->move(*game_.getCollsionMap(), currentMoveDirection_, 1);
            while(coll == nullptr || (!((GameBase*)coll)->isMovingPlatform()) )
                coll = object->move(*game_.getCollsionMap(), currentMoveDirection_, 1);
            object->moveAnyway(*game_.getCollsionMap(), currentMoveDirection_, 1);
        }
        object->justMovedByPlatform();
    }
}

void MovingPlatformElement::moveEncounteredObjects(GameBase* object)
{
    Object* coll = object->move(*game_.getCollsionMap(), currentMoveDirection_, 1);
    while(coll != nullptr)
        coll = ((GameBase*)coll)->move(*game_.getCollsionMap(), currentMoveDirection_, 1);
}

bool MovingPlatformElement::isOutOfVerticalPosition()
{
    if(currentMoveDirection_ == DOWN)
        return outOfLowerBoundary();
    else if(currentMoveDirection_ == UP)
        return outOfUpperBoundary();
    else
        throw *(new std::exception);
}

bool MovingPlatformElement::outOfUpperBoundary()
{
    SDL_Rect camera = game_.getMarioCamera();
    return rectShow_.y < camera.y - 100;
}

bool MovingPlatformElement::outOfLowerBoundary()
{
    SDL_Rect camera = game_.getMarioCamera();
    return rectShow_.y+rectShow_.h-1 > camera.y+camera.h-1 + 100;
}

void MovingPlatformElement::repositionPlatform()
{
    if(currentMoveDirection_ == UP)
        repositionPlatform(rectShow_.x, 850);
    else if(currentMoveDirection_ == DOWN)
        repositionPlatform(rectShow_.x, 300);
    else
        throw *(new std::exception);
}

void MovingPlatformElement::repositionPlatform(int x, int y)
{
    SDL_Rect showingRect = getShowingRect();
    showingRect.x = x;
    showingRect.y = y;
    repositionObjectCollision(*game_.getCollsionMap(), x, y);
    setBothRects(showingRect);
}

void MovingPlatformElement::revertMoveDirection()
{
    switch(currentMoveDirection_)
    {
        case LEFT:  currentMoveDirection_ = RIGHT; break;
        case RIGHT: currentMoveDirection_ = LEFT; break;
        case UP:    currentMoveDirection_ = DOWN; break;
        case DOWN:  currentMoveDirection_ = UP; break;
    }
}

void MovingPlatformElement::addAtEndSave(std::ofstream& file)
{
    file << currentMoveDirection_ << ' ';
}

std::string MovingPlatformElement::loadObject(std::string objectLine)
{
    objectLine = GameBase::loadObject(objectLine);
    setCurrentMoveDirection((int)(objectLine[0] - '0'));
    objectLine.erase(0, 2);
    return objectLine;
}

