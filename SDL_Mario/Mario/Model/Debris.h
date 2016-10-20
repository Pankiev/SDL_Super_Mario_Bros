
#pragma once

#include "AbstractMob.h"
#include "../../Model/AbstractAnimation.h"

#define IDENTIFY_DEBRIS 'd';

class Debris : public AbstractMob
{
public:

    Debris(MarioGame& game, float upwardForce = 3.0f, int horizontalDirection = RIGHT);

    void action() override;
    void flipImage();
    virtual void setLookout()=0;
    char identify() const override {return IDENTIFY_DEBRIS;}

private:

    int horizontalMoveDirection_;
    Timer aliveTimer_;
    Timer imageFlipTimer_;
};
