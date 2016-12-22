
#pragma once

#include "UnknownBlock.h"

#define IDENTIFY_ANIMATING_UNKNOWN_BLOCK 'p'

class AnimatingUnknownBlock : public UnknownBlock
{
public:

    AnimatingUnknownBlock(MarioGame& game, AbstractMob* content = nullptr);

    void action() override;
    char identify() const override {return IDENTIFY_ANIMATING_UNKNOWN_BLOCK;}

private:

    void animationInit();

    ManyPicAnimation exist_;
};
