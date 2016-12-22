
#pragma once

#include "Mob.h"

class BlockItem : public Mob
{
public:

    BlockItem(MarioGame& game);

    virtual void action() override;
    virtual void marioJumped() override;
    virtual char identify() const override=0;
    void doOnce();

protected:

    bool doOnce_;
    Timer waitTimer_;
    bool active_;
};
