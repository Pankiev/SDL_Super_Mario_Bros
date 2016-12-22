#pragma once

#include "Object.h"
#include "../Controller/Timer.h"

class AbstractAnimation : public Object
{
public:

    AbstractAnimation();

    virtual bool animate();
    virtual bool nextPicture()=0; // returns true at end of set
    virtual void resetAnimation()=0;

protected:

    Timer pictureTimer_;
};
