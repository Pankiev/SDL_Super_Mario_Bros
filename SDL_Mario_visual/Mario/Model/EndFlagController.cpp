
#include <cstdlib>

#include "EndFlagController.h"
#include "../Controller/MarioGame.h"
#include "../../StringUtilities.h"

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

void EndFlagController::saveObject(FILE* file)
{
	fprintf(file, "%c %d \n", identify(), flagXPosition_);
}

const char* EndFlagController::loadObject(const char* objectLine)
{
	char value[100] = { '\0' };
    int i = 0;
    for(; objectLine[i] != ' '; i++)
        value[i] = objectLine[i];
	value[i + 1] = '\0';
    flagXPosition_ = atoi(value);

	erase((char*)objectLine, 0, i);

    rectShow_.x = flagXPosition_;
    rectShow_.y = 600;

    return objectLine;
}
