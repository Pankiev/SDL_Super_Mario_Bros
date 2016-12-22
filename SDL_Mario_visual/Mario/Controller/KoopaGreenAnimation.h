#pragma once

#include "KoopaAnimation.h"

class KoopaGreenAnimation : public KoopaAnimation
{
public:

    KoopaGreenAnimation(AbstractMob& owner);

    void setTextures() override;
};
