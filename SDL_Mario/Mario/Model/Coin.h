
#pragma once

#include "GameBase.h"
#include "../../Model/ManyPicAnimation.h"

#define VALUE_COIN 200

#define IDENTIFY_COIN 'l'

class Coin : public GameBase
{
public:

    Coin(MarioGame& game);

    void action() override;
    bool isActive() const override {return true;}
    int getValue() const override {return VALUE_COIN;}
    char identify() const override {return IDENTIFY_COIN;}
    void die() override;

private:

    bool detectCollision();
    void animateInit();

    ManyPicAnimation exist_;
};
