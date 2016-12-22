
#pragma once

#include "GameBase.h"
#include "../Controller/MarioGame.h"
#include "../../Controller/Timer.h"

#define IDENTIFY_PIPE_ENTER_CONTROLLER 'z'

class PipeEnterController : public GameBase
{
public:

    PipeEnterController(MarioGame& game, const SDL_Point& enterPoint = {0,0},
                        const SDL_Point& stopPoint = {0,0}, const SDL_Point& loadMarioPos = {0,0},
                        const char* levelLoadPath = LEVEL_1_1_PATH);

    void action() override;
    char identify() const override {return IDENTIFY_PIPE_ENTER_CONTROLLER;}
    bool isActive() const override {return true;}

    void setEnterPoint(const SDL_Point& point);
    void setStopPoint(const SDL_Point& point);
    void setLevelLoadPath(const char* loadPath);
    void setLevelLoadMarioPosition(const SDL_Point& point);

    const char* loadObject(const char* objectLine) override;
    void saveObject(std::ofstream& file) override;

private:

    bool pipeEnterConditionsFulfilled();

    bool pipeUsed_;

    const char* levelLoadPath_;
    SDL_Point levelLoadMarioPosition_;
    SDL_Point enterPoint_;
    SDL_Point stopPoint_;

    Timer goingIntoPipeTimer_;
};
