#pragma once

#include "Koopa.h"

#define IDENTIFY_KOOPA_GREEN '1'

class KoopaGreen : public Koopa
{
public:

    KoopaGreen(MarioGame& game);

    char identify() const override {return IDENTIFY_KOOPA_GREEN;}
};
