
#pragma once

#include "Koopa.h"

#define IDENTIFY_KOOPA_RED '0'

class KoopaRed : public Koopa
{
public:

    KoopaRed(MarioGame& game);

    void action() override;
    char identify() const override {return IDENTIFY_KOOPA_RED;}

private:

    void turnAroundIfNearEdge();
    bool isNearEdge();
    bool isNearEdgeOnLeftSide();
    bool isNearEdgeOnRightSide();

};

