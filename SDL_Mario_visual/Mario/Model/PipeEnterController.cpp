
#include "PipeEnterController.h"
#include <cstdlib>

PipeEnterController::PipeEnterController(MarioGame& game,   const SDL_Point& enterPoint,
                                                            const SDL_Point& stopPoint,
                                                            const SDL_Point& loadMarioPos,
                                                std::string levelLoadPath):GameBase(game)
{
    enterPoint_ = enterPoint;
    stopPoint_ = stopPoint;
    levelLoadPath_ = levelLoadPath;
    levelLoadMarioPosition_ = loadMarioPos;
    pipeUsed_ = false;
    goingIntoPipeTimer_.setActionsPerSec(0.5f);
//    setTexture(TEXTURE_BRICK_3);
//    game_.addImage(this);
//    setLayer(10000);
    rectShow_.x = enterPoint_.x;
    rectShow_.y = enterPoint_.y;
}

void PipeEnterController::action()
{
    Mario* mario = game_.getMainChar();
    if(!(pipeUsed_))
    {
        if(pipeEnterConditionsFulfilled())
        {
            pipeUsed_ = true;
            game_.haltSoundEfx(CHUNKSOUND_MARIO_OVERWORLD);
            game_.playSoundEfx(CHUNKSOUND_PIPE_ENTER);
            game_.getMainChar()->invincibilityMove(stopPoint_);
            goingIntoPipeTimer_.reset();
        }
    }
    else
    {
        goingIntoPipeTimer_.calculateTime();
        if(goingIntoPipeTimer_.askForAction())
        {
            die();
            mario->resetCamera();
            mario->stopInvincibleMoving();
            mario->stopMoving();
            if(mario->getMarioType() != MARIO_SMALL)
                levelLoadMarioPosition_.y -= 32;

            mario->setBothPosition(levelLoadMarioPosition_.x, levelLoadMarioPosition_.y);
            game_.loadGame(levelLoadPath_);
        }
    }
}

bool PipeEnterController::pipeEnterConditionsFulfilled()
{
    Mario* mario = game_.getMainChar();
    SDL_Point marioFeetPoint = {mario->calcUnrelatedCenterPoint().x,
    mario->getShowingRect().y + mario->getShowingRect().h - 1};
    float distance = CollisionMap::calcDistanceBetweenPoints(enterPoint_, marioFeetPoint);
    bool conditionsFulfilled = (distance < 15.0f && !(mario->isInvincibleMoving()) && mario->isPipeEnterAccepting());

    return conditionsFulfilled;
}

void PipeEnterController::setEnterPoint(const SDL_Point& point)
{
    enterPoint_ = point;
}

void PipeEnterController::setStopPoint(const SDL_Point& point)
{
    stopPoint_ = point;
}

void PipeEnterController::setLevelLoadMarioPosition(const SDL_Point& point)
{
    levelLoadMarioPosition_ = point;
}

std::string PipeEnterController::loadObject(std::string objectLine)
{
    int i = 0, counter = 0;
    for(; counter < 7; i++,counter++)
    {
        std::string value;
        value.clear();
        for(; objectLine[i] != ' '; i++)
            value += objectLine[i];

        if(counter == 0)
            enterPoint_.x = atoi(value.c_str());
        else if(counter == 1)
            enterPoint_.y = atoi(value.c_str());
        else if(counter == 2)
            stopPoint_.x = atoi(value.c_str());
        else if(counter == 3)
            stopPoint_.y = atoi(value.c_str());
        else if(counter == 4)
            levelLoadMarioPosition_.x = atoi(value.c_str());
        else if(counter == 5)
            levelLoadMarioPosition_.y = atoi(value.c_str());
        else
            levelLoadPath_ = value;
    }
    objectLine.erase(0, i);

    rectShow_.x = enterPoint_.x;
    rectShow_.y = enterPoint_.y;

    return objectLine;
}

void PipeEnterController::saveObject(std::ofstream& file)
{
    file << identify() << ' ' << enterPoint_.x << ' ' << enterPoint_.y << ' ';
    file << stopPoint_.x << ' ' << stopPoint_.y << ' ';
    file << levelLoadMarioPosition_.x << ' ' << levelLoadMarioPosition_.y << ' ';
    file << levelLoadPath_.c_str() << ' ';
    file << '\n';
}
