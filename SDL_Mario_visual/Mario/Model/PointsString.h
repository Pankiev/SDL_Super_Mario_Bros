
#pragma once

#include "../../Controller/Timer.h"
#include "../../View/StringFactory.h"
#include "String.h"

class PointsString : public String
{
public:

    PointsString(MarioGame& game, int points);
};

