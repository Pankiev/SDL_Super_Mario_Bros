#pragma once
#include <SDL.h>

#define SECOND 1.0f

class Timer
{
public:

    Timer();

    void calculateTime();
    float getInterval();
    bool askForAction();
    void setActionsPerSec(float fps);
    void reset();

private:

    float frameTime_;
    unsigned int prevTime_;
    unsigned int currentTime_;
    float deltaTime_;
    float currentAPS_;
};
