
#pragma once

#include "ActiveBlock.h"

#define IDENTIFY_EMPTY_BLOCK 'e'

class EmptyBlock : public ActiveBlock
{
public:

    EmptyBlock(MarioGame& game);
    void action() override;
    virtual char identify() const override {return IDENTIFY_EMPTY_BLOCK;}

private:

    void hopOnce();
    bool hopOnce_;

};

