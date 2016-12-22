#pragma once

#include "GoombasAnimation.h"

class GoombasBrownAnimation : public GoombasAnimation
{
public:

    GoombasBrownAnimation(AbstractMob& owner);

    void setTextures() override;
};
