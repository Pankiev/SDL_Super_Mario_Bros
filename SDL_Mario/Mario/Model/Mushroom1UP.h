
#pragma once

#include "Mushroom.h"

#define IDENTIFY_MUSHROOM_1UP 'h'

class Mushroom1UP : public Mushroom
{
public:

    Mushroom1UP(MarioGame& game);

    char identify() const override {return IDENTIFY_MUSHROOM_1UP;}
    int getValue() const override {return 0;}
    void marioTouch() override;

private:

    void add_1UP_Text();
};
