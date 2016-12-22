#define _CRT_SECURE_NO_WARNINGS
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <string>

#include "../../List/ListIterator.h"
#include "../../List/ListIterator.hpp"
#include "MarioGame.h"
#include "MarioAnimation.h"
#include "../Model/GoombasBrown.h"
#include "../Model/GoombasBlue.h"
#include "../Model/KoopaGreen.h"
#include "../Model/KoopaBlue.h"
#include "../Model/KoopaRed.h"
#include "../Model/PiranhaPlantGreen.h"
#include "../Model/PiranhaPlantBlue.h"

#include "../Model/AnimatingUnknownBlock.h"
#include "../Model/HiddenUnkownBlock.h"
#include "../Model/BlockCoin.h"
#include "../Model/MoneyBlock.h"
#include "../Model/LevelUpFlower.h"
#include "../Model/Star.h"
#include "../Model/EmptyBlock.h"
#include "../Model/Mushroom1UP.h"
#include "../Model/Coin.h"
#include "../Model/PipeEnterController.h"
#include "../Model/EndFlagController.h"
#include "../Model/MovingPlatformElement.h"
#include "../Model/Browser.h"

#include "loadConstants.h"
#include "../../ApplicationError.h"
#include "../../StringUtilities.h"


MarioGame::MarioGame()
{
	srand(time(NULL));
	initFields();
	marioChar_ = nullptr;
	stringFactory_ = nullptr;
}

void MarioGame::initFields()
{
	gameWidth_ = GAME_WIDTH;
	gameHeight_ = GAME_HEIGHT;
	points_ = STARTING_POINTS;
	coins_ = STARTING_COINS;
	lives_ = STARTING_LIVES;
	time_ = STARTING_TIME;
	currentStageType_ = STAGE_OVERWORLD;

	gameTimer_.setActionsPerSec(2.5f);
	gameLoad_ = false;
	changingTimeToScore_ = false;
	currentStage_[0] = 1;
	currentStage_[1] = 1;
	gameTimerActive_ = true;
}

void MarioGame::run()
{
	SDL_init();
	createScreenSizedWindow("MarioGame");

	scaleImage(gameWidth_, gameHeight_);
	map_ = new CollisionMap(gameWidth_, gameHeight_);
	window_.setIcon(TEXTURE_MARIO_SMALL_MARIOSTAND_PATH);
	stringFactory_ = new StringFactory(window_.getRenderer());
	textures_.setTransparentColor(TRANSPARENT_PIC_COLOR);
	loadTextures();
	SDL_SetRenderDrawColor(getRenderer(), 92, 148, 252, 255);

	/*Object bg;
	bg.setTexture(textures_.getTexture(TEXTURE_UNDERGROUND_END_UP));
	bg.setBothPosition(0,320);
	bg.queryTexture();
	addImage(&bg);*/


	audio_.loadChunkSounds();
	audio_.setMusicVolume(20);
	audio_.setEfxVolume(50);

	text_ = new Interface(*this, *stringFactory_);
	text_->loadStrings();
	text_->addStrings();

	marioChar_ = new Mario(*this);
	freezeGameTimer();
	text_->showFirstScreen();

	//produceGameObject(new PiranhaPlantGreen(*this), 100, 600);

	gameTimer_.reset();
	while(!(isGameOver()))
	{
		timeHandle();
		handleControllers();
		action();
		text_->action();
		window_.renderClear();
		window_.renderPart(getMarioCamera());
		//debugRenderCollisionPoints(getMarioCamera());
		window_.showImage();
		clearGarbage();
	}

	moveToGarbageAll();
	clearGarbage();
	freeMemory();
	delete text_;
}

Mario* MarioGame::getMainChar()
{
	return marioChar_;
}

void MarioGame::addToGame(GameBase* object)
{
	if(object->isActive())
		actionActives_.push_back(object);
	else
		otherObjects_.push_back(object);

	window_.add(object);
}

void MarioGame::moveToGarbageAll()
{
	moveToGarbage(actionActives_);
	moveToGarbage(otherObjects_);
}

void MarioGame::moveToGarbage(List<GameBase*>& list)
{
	for(ListIterator<GameBase*> i = list.begin(); i != list.end();)
	{
		if((*i)->isAlive())
			(*i)->GameBase::die();
		addToGarbage(*i);
		i = list.erase(i);
	}
}

void MarioGame::addToGarbage(Object* trash)
{
	garbage_.push_back(trash);
}

int MarioGame::getGameWidth()
{
	return gameWidth_;
}

int MarioGame::getGameHeight()
{
	return gameHeight_;
}

SDL_Rect MarioGame::getMarioCamera()
{
	return marioChar_->calcCameraRect(gameWidth_, gameHeight_);
}

void MarioGame::action()
{
	for(ListIterator<GameBase*> i = actionActives_.begin(); i != actionActives_.end();)
	{
		if(gameLoad_)
		{
			gameLoad_ = false;
			break;
		}

		if((*i)->isActionActive())
		{
			if(!isObjectInCamera(*i))
				(*i)->GameBase::die();

			if((*i)->isAlive())
				(*i)->action();
			else
			{
				addToGarbage(*i);
				i = actionActives_.erase(i);
				continue;
			}

		}
		else if(isObjectInCamera(*i))
			(*i)->actionActivate();

		++i;
	}
}

void MarioGame::clearGarbage()
{
	if(garbage_.size() > 0)
	{
		for(ListIterator<Object*> i = garbage_.begin(); i != garbage_.end();)
		{
			delete (*i);
			i = garbage_.erase(i);
		}
	}
}

void MarioGame::saveGame(const char* filePath)
{
	FILE* file = fopen(filePath, "w");
	if(file != nullptr)
	{
		fprintf(file, "%d\n", gameWidth_);
		fprintf(file, "%d\n", currentStageType_);

		for(ListIterator<GameBase*> i = actionActives_.begin(); i != actionActives_.end(); ++i)
			(*i)->saveObject(file);

		for(ListIterator<GameBase*> i = otherObjects_.begin(); i != otherObjects_.end(); ++i)
			(*i)->saveObject(file);
		fclose(file);
	}	
}

void MarioGame::loadGame(const char* filePath)
{
	((GameBase*)marioChar_)->die();
	moveToGarbageAll();

	FILE* file = fopen(filePath, "r");

	char* line = new char[100];
	line[0] = NULL;
	if(file != NULL)
	{
		loadCollMap(file);
		map_->update(marioChar_);
		loadStageType(file);

		readLine(line, file);
		while(size(line) > 0)
		{
			GameBase* loadedObject = createObjectByIdentify(line[0]);
			if (loadedObject->identify() == IDENTIFY_MARIO)
				marioChar_ = (Mario*)loadedObject;

			erase((char*)line, 0, 2);
			loadedObject->loadObject(line);

			if(loadedObject->isCollisionActive())
				map_->update(loadedObject);

			addToGame(loadedObject);
			readLine(line, file);
		}
		fclose(file);
	}
	else
	{
		printf("Bad load: %s\n", filePath);
		throw *(new ApplicationError);
	}
}

void MarioGame::addPoints(int points)
{
	points_ += points;
	text_->pointsUpdate(points_);
}

int* MarioGame::getCurrentStage()
{
	return currentStage_;
}

void MarioGame::addCoin()
{
	if(++coins_ >= 100)
	{
		coins_ = 0;
		lives_++;
		playSoundEfx(CHUNKSOUND_LIVES_UP);
	}
	else
		playSoundEfx(CHUNKSOUND_COIN_TAKEN);

	text_->coinsUpdate(coins_);
}

StringFactory* MarioGame::getStringFactory()
{
	return stringFactory_;
}

void MarioGame::produceGameObject(GameBase* gameObject, int posX, int posY)
{
	gameObject->setBothPosition(posX, posY);
	if(gameObject->isCollisionActive())
		map_->update(gameObject);

	addToGame(gameObject);
}

bool MarioGame::isObjectInCamera(Object* object)
{
	SDL_Rect camera = getMarioCamera();
	SDL_Rect rectShow = object->getShowingRect();

	bool objectInCamera = ((map_->isPointInRect({rectShow.x-100, 500}, camera)) ||
			(map_->isPointInRect({rectShow.x + rectShow.w+99, 500}, camera)));

	return objectInCamera;
}

GameBase* MarioGame::createObjectByIdentify(char identificator)
{
	switch(identificator)
	{
	case IDENTIFY_GAME_BASE:                return new GameBase(*this);
	case IDENTIFY_BLOCK:                    return new Block(*this);
	case IDENTIFY_ACTIVE_BLOCK:             return new ActiveBlock(*this);
	case IDENTIFY_EMPTY_BLOCK:              return new EmptyBlock(*this);
	case IDENTIFY_GOOMBAS_BROWN:            return new GoombasBrown(*this);
	case IDENTIFY_GOOMBAS_BLUE:             return new GoombasBlue(*this);
	case IDENTIFY_KOOPA_GREEN:              return new KoopaGreen(*this);
	case IDENTIFY_KOOPA_RED:                return new KoopaRed(*this);
	case IDENTIFY_KOOPA_BLUE:               return new KoopaBlue(*this);
	case IDENTIFY_PIRANHA_GREEN:            return new PiranhaPlantGreen(*this);
	case IDENTIFY_PIRANHA_BLUE:             return new PiranhaPlantBlue(*this);

	case IDENTIFY_MONEY_BLOCK:              return new MoneyBlock(*this);
	case IDENTIFY_UNKNOWN_BLOCK:            return new UnknownBlock(*this);
	case IDENTIFY_ANIMATING_UNKNOWN_BLOCK:  return new AnimatingUnknownBlock(*this);
	case IDENTIFY_HIDDEN_UNKNOWN_BLOCK:     return new HiddenUnknownBlock(*this);
	case IDENTIFY_COIN:                     return new Coin(*this);
	case IDENTIFY_PIPE_ENTER_CONTROLLER:    return new PipeEnterController(*this);
	case IDENTIFY_END_FLAG_CONTROLLER:      return new EndFlagController(*this);
	case IDENTIFY_BROWSER:                  return new Browser(*this);
	case IDENTIFY_MOVING_PLATFORM_ELEMENT:  return new MovingPlatformElement(*this);
	case IDENTIFY_MARIO: return new Mario(*this);
	default:
		printf("CreateObjectByIdentify in MarioGame.cpp\n");
		throw *(new ApplicationError);
	}
}

void MarioGame::addLife()
{
	lives_++;
	playSoundEfx(CHUNKSOUND_LIVES_UP);
}

void MarioGame::loadCollMap(FILE* file)
{
	char line[100] = { NULL };
	readLine(line, file);
	gameWidth_ = atoi(line);

	delete map_;
	map_ = new CollisionMap(gameWidth_, gameHeight_);
}

void MarioGame::loadStageType(FILE* file)
{
	char line[100] = { NULL };
	readLine(line, file);
	currentStageType_ = atoi(line);

	loadCurrentStageType();
}

void MarioGame::loadCurrentStageType()
{
	haltAllSoundEfx();
	switch(currentStageType_)
	{
	case STAGE_OVERWORLD:
		SDL_SetRenderDrawColor(getRenderer(),92,148,252,255);
		playSoundEfx(CHUNKSOUND_MARIO_OVERWORLD, INFINITE_LOOP);
		break;
	case STAGE_UNDERGROUND:
		playSoundEfx(CHUNKSOUND_UNDERGROUND, INFINITE_LOOP);
		SDL_SetRenderDrawColor(getRenderer(),0,0,0,255);
		break;
	case STAGE_UNDERWATER:
		SDL_SetRenderDrawColor(getRenderer(),92,148,252,255);
		break;
	case STAGE_CASTLE:
		SDL_SetRenderDrawColor(getRenderer(),0,0,0,255);
		playSoundEfx(CHUNKSOUND_CASTLE, INFINITE_LOOP);
		break;
	default:
		printf("loadStageType\n");
		throw *(new ApplicationError);
	}
}

void MarioGame::clearActionInactives()//For debugging
{
	for(ListIterator<GameBase*> i = otherObjects_.begin(); i != otherObjects_.end();)
	{
		if(!((*i)->isAlive()))
			i = otherObjects_.erase(i);
		else
			++i;
	}
}

void MarioGame::timeUpdate()
{
	if(gameTimer_.askForAction())
		text_->timeUpdate(--time_);
}

void MarioGame::timeHandle()
{
	gameTimer_.calculateTime();
	if(gameTimerActive_)
	{
		timeUpdate();
		timesUpHandle();
	}

	if(changingTimeToScore_)
		changeTimeToScoreHandle();
}

void MarioGame::timesUpHandle()
{
	if(time_ < 0)
	{
		time_ = 0;
		if(!(marioChar_->isDying()))
			marioChar_->die();
	}
}

void MarioGame::newGame()
{
	initFields();
	sameLevel();
}

void MarioGame::moveToGarbageAllButMario()
{

}

Mario* MarioGame::copyMario()
{
	Mario* copiedMario = new Mario(*marioChar_);
	copiedMario->setAnimations(new MarioAnimation(*copiedMario));
	return copiedMario;
}

void MarioGame::freezeGameTimer()
{
	gameTimerActive_ = false;
}

void MarioGame::changeTimeToScore()
{
	changingTimeToScore_ = true;
	playSoundEfx(CHUNKSOUND_TIME_TO_SCORE, INFINITE_LOOP);
}

void MarioGame::changeTimeToScoreHandle()
{
	if(time_ > 0)
	{
		text_->timeUpdate(--time_);
		points_ += 10;
		text_->pointsUpdate(points_);
	}
	else
	{
		changingTimeToScore_ = false;
		haltSoundEfx(CHUNKSOUND_TIME_TO_SCORE);
	}
}

bool MarioGame::isChangingTimeToScore()
{
	return changingTimeToScore_;
}

void MarioGame::activateGameTimer()
{
	gameTimerActive_ = true;
}

void MarioGame::loadNextLevel()
{
	loadGameFromObjectField();
	time_ = 400;
	activateGameTimer();
}

void MarioGame::nextLevel()
{
	if(++currentStage_[1] > 4)
	{
		currentStage_[1] = 1;
		currentStage_[0]++;
	}

	sameLevel();
}

void MarioGame::onMarioDeath()
{
	lives_--;
	if (lives_ <= 0)
	{
		initFields();
		text_->showFirstScreen();
	}
	else
	{
		marioChar_->setBothPosition(100, 650);
		sameLevel();
	}
	marioChar_ = new Mario(*this);
}

void MarioGame::sameLevel()
{
	marioChar_ = copyMario();
	gameLoad_ = true;
	moveToGarbageAll();
	marioChar_->setBothPosition(100,650);
	marioChar_->resetCamera();
	marioChar_->stopMoving();
	marioChar_->restartRendering();
	marioChar_->setMoveSpeed(200.0f);
	text_->showInfoScreen();
}

int MarioGame::getLives()
{
	return lives_;
}

void MarioGame::loadGameFromObjectField()
{
	const char* currentLevelPath = createCurrentLevelPath();
	loadGame(createCurrentLevelPath());
	delete[] currentLevelPath;
}

const char* MarioGame::createCurrentLevelPath()
{
	char* currentLevelPath = new char[200];
	currentLevelPath[0] = NULL;
	strcat(currentLevelPath, "Levels/level");
	strcat(currentLevelPath, createStageString());
	strcat(currentLevelPath, ".txt");
	return currentLevelPath;
}

const char* MarioGame::createStageString()
{
	char* stageString = new char[4];
	stageString[0] = currentStage_[0] + 48;
	stageString[1] = '-';
	stageString[2] = currentStage_[1] + 48;
	stageString[3] = '\0';
	return stageString;
}
