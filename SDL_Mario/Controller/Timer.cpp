
#include "Timer.h"

Timer::Timer()
{
    frameTime_ = 0;
    deltaTime_ = 0;
    prevTime_ = 0;
    currentTime_ = 0;
}

void Timer::calculateTime()
{
    prevTime_ = currentTime_;
    currentTime_ = SDL_GetTicks();
    deltaTime_ = (currentTime_ - prevTime_)/1000.0f;
    frameTime_ += deltaTime_;
}

float Timer::getInterval()
{
    return deltaTime_;
}

bool Timer::askForAction()
{
    if(frameTime_ >= (float)(SECOND/currentAPS_))
    {
        frameTime_ = 0.0f;
        return true;
    }
    return false;
}

void Timer::setActionsPerSec(float fps)
{
    currentAPS_ = fps;
}

void Timer::reset()
{
    prevTime_ = currentTime_ = SDL_GetTicks();
    deltaTime_ = 0.0f;
    frameTime_ = 0.0f;
}
