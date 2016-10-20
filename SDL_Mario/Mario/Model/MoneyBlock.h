
#pragma once

#include "ActiveBlock.h"
#include "../../Model/ManyPicAnimation.h"

#define IDENTIFY_MONEY_BLOCK 'm'

class MoneyBlock : public ActiveBlock
{
public:

    MoneyBlock(MarioGame& game);
    MoneyBlock(MarioGame& game, int BLOCK_TYPE);

    void marioHit() override;
    void resetTimerOnce();
    virtual char identify() const override {return IDENTIFY_MONEY_BLOCK;}

private:

    Timer popCoinsTimer_;
    bool resetTimer_;
};
