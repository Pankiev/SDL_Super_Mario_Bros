
#include "MovingPlatform.h"

MovingPlatform::MovingPlatform(MarioGame& game, int platformLength):GameBase(game)
{
    platform_ = new MovingPlatformElement* [platformLength];
    for(int i=0; i<platformLength; i++)
        platform_[i] = new MovingPlatformElement(game);
}

MovingPlatform::~MovingPlatform()
{
    for(int i=0; i<platformLength_; i++)
        delete platform_[i];
    delete[] platform_;
}

void MovingPlatform::action()
{
    for(int i=0; i<platformLength_; i++)
        platform_[i]->action();
}

