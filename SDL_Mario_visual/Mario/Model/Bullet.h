/*
#pragma once

#include "Mob.h"

class Bullet : public Mob
{
public:

    Bullet(MarioGame& game);

    void marioJumped() override;
    void action() override;
    void jump() override;
    void die() override;
    void anyObjectHorizontalMoveTouch() override;
    void otherMobTouch(Mob* otherMob) override;
    void createFirework();
    char identify() const override {return IDENTIFY_FIREBALL;}

private:

};
*/
