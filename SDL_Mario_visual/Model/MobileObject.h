#pragma once

#include "Object.h"

#define DEFAULT_MOVE_SPEED 300.0f

class CollisionMap;

class MobileObject : public Object
{
public:

    MobileObject(const char* name="Unnamed", int id=0, int layer=0);

    void setMoveSpeed(float speed);
    float getMoveSpeed() const;
    void move(int direction, float timeFactor);
    Object* move(CollisionMap& map, int direction, float timeFactor);
    Object* move(CollisionMap& map, int direction, int pixels);
    Object* moveAnyway(CollisionMap& map, int direction, float timeFactor);
    Object* moveAnyway(CollisionMap& map, int direction, int pixels);
    Object* repositionObjectCollision(CollisionMap& map, int x, int y);
    void goToPoint(CollisionMap& map, int x, int y, float timeFactor);
    void applyMoveToRects(int direction, int moveValue);

protected:

    int calcMoveValue(float floatMoveValue, int direction);
    int extractFloat();

    float moveSpeed_;
    float horizontalMove_;
    float verticalMove_;
    bool calcOnce_;
};
