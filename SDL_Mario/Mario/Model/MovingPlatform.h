
#pragma once

#include "GameBase.h"

#define PLATFORM_DEFAULT_LENGHT 3

#include "MovingPlatformElement.h"

class MovingPlatform : public GameBase
{
public:

    MovingPlatform(MarioGame& game, int platformLength = PLATFORM_DEFAULT_LENGHT);
    ~MovingPlatform();

    bool isActive() const {return true;}
    bool isCollisionActive() const {return true;}
    void action() override;
    void repositionWholePlatform(int x, int y);

private:

    MovingPlatformElement** platform_;
    int platformLength_;
};
