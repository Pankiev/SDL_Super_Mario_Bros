

#include "PointsString.h"

PointsString::PointsString(MarioGame& game, int points):String(game)
{
	char pointsString[15];
	_itoa_s(points, pointsString, 10);
	loadString(pointsString);
}
