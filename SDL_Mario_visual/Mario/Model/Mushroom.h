
#pragma once

#include "BlockItem.h"
#include "../../Controller/Timer.h"

#define POINTS_MUSHROOM 1000
#define IDENTIFY_MUSHROOM 'q'

class Mushroom : public BlockItem
{
public:

    Mushroom(MarioGame& game);

    void die() override;
    virtual void marioTouch() override;
    void blockHopped() override;
    void jump() override;
    virtual int getValue() const override;
    virtual char identify() const override {return IDENTIFY_MUSHROOM;}

};
