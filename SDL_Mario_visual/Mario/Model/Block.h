
#pragma once

#include "GameBase.h"
#include "Debris.h"
#include "../../Controller/Timer.h"

#define BLOCK_WIDTH 32
#define BLOCK_HEIGHT 32

#define IDENTIFY_BLOCK 'b'

class Block : public GameBase
{
public:

    Block(MarioGame& game, int BLOCK_TYPE);
    Block(MarioGame& game);

    virtual void action() override {}
    bool isMob() const override {return false;}
    bool isBlock() const  override {return true;}
    virtual char identify() const override {return IDENTIFY_BLOCK;}
    virtual bool isActive() const override {return false;}
    bool isCollisionActive() const override {return true;}
    virtual void marioHit();

};
