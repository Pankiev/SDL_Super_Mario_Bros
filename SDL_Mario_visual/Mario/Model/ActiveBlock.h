#pragma once

#include "Block.h"

#define VALUE_BLOCK 50

#define IDENTIFY_ACTIVE_BLOCK 'a'

class ActiveBlock : public Block
{
public:

    ActiveBlock(MarioGame& game, int BLOCK_TYPE);
    ActiveBlock(MarioGame& game);

    virtual void action() override;
    virtual void hop();
    void destroy();
    void createDebris();
    virtual void marioHit() override;
    Debris* createDebris(float upwardForce, int horizontalMoveDirection);
    void hopStandingOnBlock();
    bool isActive() const override {return true;}
    bool isHopping();
    char identify() const override {return IDENTIFY_ACTIVE_BLOCK;}

    virtual int getValue() const override;

private:

    Timer hopTimer_;
    bool hop_;
    int hopCurrentDir_;
    SDL_Rect initialColl_;
    SDL_Rect initialShow_;
};
