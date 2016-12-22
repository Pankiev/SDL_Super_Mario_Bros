
#pragma once

#include "BlockItem.h"
#include "../../Model/ManyPicAnimation.h"

#define VALUE_STAR 1000
#define IDENTIFY_STAR 's'


class Star : public BlockItem
{
public:

    Star(MarioGame& game);

    void marioTouch() override;
    void action() override;
    void jump() override;
    int getValue() const override;
    char identify() const override {return IDENTIFY_STAR;}

private:

    void animateInit();
    ManyPicAnimation exist_;
};
