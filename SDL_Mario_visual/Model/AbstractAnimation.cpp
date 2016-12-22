
#include "AbstractAnimation.h"

AbstractAnimation::AbstractAnimation():Object("Animation", 0, 10){}

bool AbstractAnimation::animate()
{
    pictureTimer_.calculateTime();
    if(pictureTimer_.askForAction())
        return nextPicture();

    return false;
}
