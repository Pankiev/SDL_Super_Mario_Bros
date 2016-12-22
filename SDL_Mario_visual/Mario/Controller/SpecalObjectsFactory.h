
#pragma once

#include "MarioGame.h"

#define PLATFORM_ELEMENT_WIDTH 16

class SpecialObjectsFactory
{
public:

    SpecialObjectsFactory(MarioGame& game);

    void producePlatform(int length, int x, int y);

private:

    MarioGame& game_;
};
