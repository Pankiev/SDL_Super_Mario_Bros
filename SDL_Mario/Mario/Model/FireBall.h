
#pragma once

#include "Mob.h"
#include "../../Model/ManyPicAnimation.h"

#define IDENTIFY_FIREBALL 'f'

class FireBall : public Mob
{
public:

    FireBall(MarioGame& game);

    void marioTouch() override {}
    void marioJumped() override {}
    void action() override;
    void jump() override;
    void die() override;
    void anyObjectHorizontalMoveTouch() override;
    void otherMobTouch(Mob* otherMob) override;
    void createFirework();
    char identify() const override {return IDENTIFY_FIREBALL;}

private:

    void specifyMoveDirection();
    void animateInit();

    ManyPicAnimation exist_;

};
