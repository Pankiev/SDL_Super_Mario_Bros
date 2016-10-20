#pragma once

#include "GoombasAnimation.h"

class GoombasBlueAnimation : public GoombasAnimation
{
public:

    GoombasBlueAnimation(AbstractMob& owner);

    void setTextures() override;
};
