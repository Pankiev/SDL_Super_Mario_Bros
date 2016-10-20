
#include <cstdlib>

#include "EndFlagController.h"
#include "../Controller/MarioGame.h"

EndFlagController::EndFlagController(MarioGame& game, int flagXPosition):GameBase(game)
{
    flagUsed_ = false;
    flagXPosition_ = flagXPosition;
    rectShow_.x = flagXPosition;
    rectShow_.y = 600;
}

void EndFlagController::action()
{
    if(flagUsed_)
    {
        game_.getMainChar()->levelEndSequence(flagXPosition_);
        die();
    }
    else if(flagUseConditionsFulfilled())
        flagUsed_ = true;

}

bool EndFlagController::flagUseConditionsFulfilled()
{
    SDL_Rect marioRect = game_.getMainChar()->getShowingRect();

    int marioShowRightBorder = marioRect.x + marioRect.w - 1;

    if(marioShowRightBorder >= flagXPosition_)
        return true;

    return false;
}

void EndFlagController::setFlagXPosition(int flagXPosition)
{
    flagXPosition_ = flagXPosition;
}

void EndFlagController::saveObject(std::ofstream& file)
{
    file << identify() << ' ' << flagXPosition_ << ' ';
    file << '\n';
}

std::string EndFlagController::loadObject(std::string objectLine)
{
    std::string value;
    value.clear();
    int i = 0;
    for(; objectLine[i] != ' '; i++)
        value += objectLine[i];

    flagXPosition_ = atoi(value.c_str());

    objectLine.erase(0, i);

    rectShow_.x = flagXPosition_;
    rectShow_.y = 600;

    return objectLine;
}
