
#include <sstream>

#include "PointsString.h"

PointsString::PointsString(MarioGame& game, int points):String(game)
{
    std::ostringstream pointsString;
    pointsString << points;
    loadString(pointsString.str());
}
