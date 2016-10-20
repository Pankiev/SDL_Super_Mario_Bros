
#pragma once

#include "../Model/GameBase.h"
#include "../../Model/ManyPicAnimation.h"

class InterfaceCoin : public GameBase
{
public:

    InterfaceCoin(MarioGame& game);
    void action() override;

private:

    void animateInit();
    ManyPicAnimation exist_;
};
