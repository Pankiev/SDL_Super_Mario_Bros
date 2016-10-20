
#pragma once

#include "../../Model/ManyPicAnimation.h"
#include "GameBase.h"

class MarioGame;

class FireWork : public GameBase
{
public:

    FireWork(MarioGame& game);

    void action() override;
    bool isActive() const override {return true;}

private:

    ManyPicAnimation fireworkAnim_;
};
