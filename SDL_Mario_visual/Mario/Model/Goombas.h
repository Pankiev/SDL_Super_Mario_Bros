#pragma once
#include "Mob.h"
#include "../Controller/GoombasAnimation.h"

#define POINTS_GOOMBAS 200

class Goombas : public Mob
{
public:

    Goombas(MarioGame& game, GoombasAnimation* animation);

    int getValue() const override;
    void marioJumped() override;
    char identify() const override=0;
};
