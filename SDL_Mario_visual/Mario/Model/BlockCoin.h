
#pragma once

#include "AbstractMob.h"
#include "../../Model/ManyPicAnimation.h"
#include "../../Controller/Timer.h"
#include "Coin.h"

#define IDENTIFY_BLOCK_COIN 'c'

class BlockCoin : public AbstractMob
{
public:

    BlockCoin(MarioGame& game);
    void action() override;
    char identify() const override {return IDENTIFY_BLOCK_COIN;}
    int getValue() const override;

private:

    void animateInit();
    void doOnce();

    ManyPicAnimation exist_;
    Timer existTimer_;
    bool once_;
};
