
#pragma once

#include "PiranhaPlant.h"

#define IDENTIFY_PIRANHA_BLUE 'B'

class PiranhaPlantBlue : public PiranhaPlant
{
public:

    PiranhaPlantBlue(MarioGame& game);

    char identify() const override {return IDENTIFY_PIRANHA_BLUE;}

protected:

    void setTextures();
};
