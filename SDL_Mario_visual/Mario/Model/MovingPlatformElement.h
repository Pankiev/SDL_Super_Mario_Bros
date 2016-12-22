
#pragma once

#include "GameBase.h"

#define DEFAULT_PLATROFM_MOVE_SPEED 100.0f

#define PLATFORM_HORIZONTAL_MOVE 0
#define PLATFORM_VERTICAL_MOVE 1

#define IDENTIFY_MOVING_PLATFORM_ELEMENT 'r'

class MovingPlatformElement : public GameBase
{
public:

    MovingPlatformElement(MarioGame& game);

    bool isActive() const {return true;}
    bool isCollisionActive() const {return true;}
    void action() override;
    char identify() const override {return IDENTIFY_MOVING_PLATFORM_ELEMENT;}
    bool isMovingPlatform() const override {return true;}

    void setCurrentMoveDirection(int newDirection);

    const char* loadObject(const char* objectLine);

private:


    Object* move();
    void moveStandingOnPlatformObject(GameBase* object);
    void moveEncounteredObjects(GameBase* object);
    bool isOutOfVerticalPosition();
    void repositionPlatform();
    void repositionPlatform(int x, int y);
    bool outOfUpperBoundary();
    bool outOfLowerBoundary();
    void revertMoveDirection();

    void addAtEndSave(FILE* file);

    int moveAxis_;
    int currentMoveDirection_;
    float slideFactor_;
};
