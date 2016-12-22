
#include <cstdlib>

#include "../Controller/loadConstants.h"
#include "GameBase.h"
#include "../Controller/MarioGame.h"
#include "../../ApplicationError.h"
#include "../../StringUtilities.h"

GameBase::GameBase(MarioGame& game, int BLOCK_TYPE):GameBase(game)
{
    setTexture(BLOCK_TYPE);
    movedByPlatform_ = false;
}

GameBase::GameBase(MarioGame& game):MobileObject("Block"), game_(game)
{
    defaultTexture_ = -1;
    isAlive_ = true;
    actionActive_ = false;
    setLayer(0);
}

bool GameBase::isAlive()
{
    return isAlive_;
}

void GameBase::die()
{
    if(isCollisionActive())
        game_.getCollsionMap()->clearColl(getCollisionRect());

    isAlive_ = false;
    stopRendering();
}

void GameBase::setTexture(int TEXTURE_CONSTANT)
{
    if(isPipe(TEXTURE_CONSTANT))
        setLayer(20);

    defaultTexture_ = TEXTURE_CONSTANT;
    Object::setTexture(game_.getTexture(TEXTURE_CONSTANT));
}

void GameBase::saveObject(std::ofstream& file)
{
    file << identify() << ' ';
    file << defaultTexture_ << ' ';
    SDL_Rect rectShow = getShowingRect();
    SDL_Rect rectColl = getCollisionRect();
    file << rectShow.x << ' ' << rectShow.y << ' ' << rectShow.w << ' ' << rectShow. h << ' ';
    file << rectColl.x << ' ' << rectColl.y << ' ' << rectColl.w << ' ' << rectColl. h << ' ';
    addAtEndSave(file);
    file << '\n';
}

const char* GameBase::loadObject(const char* objectLine)
{
    int i = 0, counter = 0;
    for(; counter < 9; i++,counter++)
    {
        char value[100] = {'\0'};
        for(int valueIndex = 0; objectLine[i] != ' '; i++, valueIndex++)
            value[valueIndex] += objectLine[i];

		value[i + 1] = '\0';
        applyLoadValue(counter, atoi(value));
    }
	erase((char*)objectLine, 0, i);
    return objectLine;
}

void GameBase::applyLoadValue(int LOAD_CONSTANT, int value)
{
    switch(LOAD_CONSTANT)
    {
    case LOAD_TEXTURE:
        setTexture(value);
        break;
    case LOAD_SHOW_X:
        setShowingX(value);
        break;
    case LOAD_SHOW_Y:
        setShowingY(value);
        break;
    case LOAD_SHOW_WIDTH:
        setShowingWidth(value);
        break;
    case LOAD_SHOW_HEIGHT:
        setShowingHeight(value);
        break;
    case LOAD_COLL_X:
        setCollisionX(value);
        break;
    case LOAD_COLL_Y:
        setCollisionY(value);
        break;
    case LOAD_COLL_WIDTH:
        setCollisionWidth(value);
        break;
    case LOAD_COLL_HEIGHT:
        setCollisionHeight(value);
        break;
    default:
        printf("Bad Load constant, throwing exception.\n");
        throw *(new ApplicationError);
    }
}

void GameBase::addPoints()
{
    game_.addPoints(getValue());
}

bool GameBase::isActionActive()
{
    return actionActive_;
}

void GameBase::actionActivate()
{
    actionActive_ = true;
}

bool GameBase::isPipe(int TEXTURE_CONSTANT)
{
    if(TEXTURE_CONSTANT >= 37 && TEXTURE_CONSTANT <= 40)
        return true;
    if(TEXTURE_CONSTANT >= 109 && TEXTURE_CONSTANT <= 114)
        return true;

    return false;
}

void GameBase::updateCollision()
{
    game_.getCollsionMap()->update(this);
}

void GameBase::clearItsCollision()
{
    game_.getCollsionMap()->clearColl(getCollisionRect());
}

bool GameBase::wasMovedByPlatformInThisTurn()
{
    return movedByPlatform_;
}

void GameBase::justMovedByPlatform()
{
    movedByPlatform_ = true;
}
