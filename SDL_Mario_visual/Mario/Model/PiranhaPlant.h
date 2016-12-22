#pragma once

#include "Mob.h"
#include "../../Model/ManyPicAnimation.h"

#define VALUE_PIRANHA_PLANT 100

class PiranhaPlant : public Mob
{
public:

    PiranhaPlant(MarioGame& game);

    void action() override;
    int getValue() const override {return VALUE_PIRANHA_PLANT;}
    void marioJumped() override;
    void die() override;

protected:

    virtual void setTextures()=0;
    ManyPicAnimation exist_;

private:

    Object* move();

    void copyInitialRectOnce();
    bool isMario(Object* testedObject);
    void animate();
    void handleCollision(Object* collision);
    bool isMoving();
    void timeAction();
    void stopMovingIfConditionsFulfilled();
    bool stopMovingConditionsFulfilled();
    void stopMoving();
    bool restartMovingConditionsFulfilled();
    void restartMoving();
    void revertMoveDirection();

    bool once_;
    SDL_Rect initialColl_;
    bool moving_;
    Timer waitForMoveTimer_;
    int currentVerticalDirection_;
};
