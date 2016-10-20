
#pragma once

#include "AbstractMob.h"
#include "../../Controller/Timer.h"

class Mob : public AbstractMob
{
public:

    Mob(MarioGame& game);
    virtual void action() override;
    virtual void die() override;
    bool isDying();
    virtual void marioTouch();
    virtual void touchedByMario();
    virtual void marioJumped()=0;
    virtual char identify() const override=0;
    virtual void blockHopped();
    virtual void otherMobTouch(Mob* otherMob){}
    virtual void anyObjectHorizontalMoveTouch();
    virtual bool isGravityActive() {return true;}
    void turnAround();

    void setCurrentMoveDirection(int currentDirection_);

protected:

    void objectCollsionHandle(Object* collsionObject);
    void dieFirstPart();

    Timer dieTimer_;
    int currentDirection_;
    bool dying_;
};
