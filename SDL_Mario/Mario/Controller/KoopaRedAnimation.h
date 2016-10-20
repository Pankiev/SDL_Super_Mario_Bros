
#pragma once

#include "KoopaAnimation.h"

class KoopaRedAnimation : public KoopaAnimation
{
public:

    KoopaRedAnimation(AbstractMob& owner);

    void setTextures() override;
};

