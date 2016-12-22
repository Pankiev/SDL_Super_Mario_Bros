
#pragma once

#include "Mushroom.h"
#include "../../Model/ManyPicAnimation.h"

class LevelUpFlower : public Mushroom
{
public:

    LevelUpFlower(MarioGame& game);

    void action() override;

private:

    ManyPicAnimation exist_;

};
