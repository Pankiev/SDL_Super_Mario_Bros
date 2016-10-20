
#pragma once

#include "KoopaAnimation.h"

class KoopaBlueAnimation : public KoopaAnimation
{
public:

    KoopaBlueAnimation(AbstractMob& owner);

    void setTextures() override;
};
