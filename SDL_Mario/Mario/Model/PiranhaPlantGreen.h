#pragma once

#include "PiranhaPlant.h"

#define IDENTIFY_PIRANHA_GREEN 'P'

class PiranhaPlantGreen : public PiranhaPlant
{
public:

    PiranhaPlantGreen(MarioGame& game);

    char identify() const override {return IDENTIFY_PIRANHA_GREEN;}

protected:

    void setTextures() override;
};
