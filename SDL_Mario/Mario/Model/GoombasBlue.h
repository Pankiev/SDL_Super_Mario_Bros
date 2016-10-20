
#pragma once

#include "Goombas.h"

#define IDENTIFY_GOOMBAS_BLUE '4'

class GoombasBlue : public Goombas
{
public:

    GoombasBlue(MarioGame& game);

    char identify() const override {return IDENTIFY_GOOMBAS_BLUE;}
};
