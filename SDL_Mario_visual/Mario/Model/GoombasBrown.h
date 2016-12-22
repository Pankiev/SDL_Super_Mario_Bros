#pragma once

#include "Goombas.h"

#define IDENTIFY_GOOMBAS_BROWN '3'

class GoombasBrown : public Goombas
{
public:

    GoombasBrown(MarioGame& game);

    char identify() const override {return IDENTIFY_GOOMBAS_BROWN;}
};
