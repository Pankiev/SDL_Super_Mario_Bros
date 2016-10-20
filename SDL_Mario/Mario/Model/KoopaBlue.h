#pragma once

#include "Koopa.h"

#define IDENTIFY_KOOPA_BLUE '2'

class KoopaBlue : public Koopa
{
public:

    KoopaBlue(MarioGame& game);

    char identify() const override {return IDENTIFY_KOOPA_BLUE;}

};
