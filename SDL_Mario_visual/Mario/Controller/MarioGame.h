#pragma once

#include "../../List/List.h"
#include "../../List/List.hpp"

#include "../../Controller/Controller.h"
#include "../Model/Mario.h"
#include "Level1Factory.h"
#include "../View/Interface.h"

#define TRANSPARENT_PIC_COLOR 0xFF00FF

#define GAME_WIDTH 7168
#define GAME_HEIGHT 1000

#define CAMERA_WIDTH 500
#define CAMERA_HEIGHT 450

#define STARTING_TIME 400
#define STARTING_LIVES 3
#define STARTING_COINS 0
#define STARTING_POINTS 0

#define STAGE_OVERWORLD     0
#define STAGE_UNDERGROUND   1
#define STAGE_CASTLE        2
#define STAGE_UNDERWATER    3

#define LEVEL_1_1_PATH              "Levels/level1-1.txt"
#define LEVEL_1_1_UNDERGROUND_PATH  "Levels/level1-1_Underground.txt"
#define LEVEL_1_2_PATH              "Levels/level1-2.txt"
#define LEVEL_1_2_UNDERGROUND_PATH  "Levels/level1-2_Underground.txt"
#define LEVEL_1_3_PATH              "Levels/level1-3.txt"
#define LEVEL_1_4_PATH              "Levels/level1-4.txt"
#define LEVEL_UNDERGROUND_END_PATH  "Levels/UndergroundUpperGroundPlace.txt"

class MarioGame : public Controller
{
public:

	MarioGame();

	void run() override;
	Mario* getMainChar();
	void addToGame(GameBase* object);
	void action();
	void clearGarbage();
	void addToGarbage(Object* trash);
	void timeUpdate();
	void addPoints(int points);
	void addCoin();
	
	void moveToGarbageAll();
	void moveToGarbage(List<GameBase*>& list);
	void saveGame(const char* filePath);
	void loadGame(const char* filePath);
	void addLife();
	void timeHandle();
	void timesUpHandle();

	void produceGameObject(GameBase* gameObject, int posX, int posY);
	void freezeGameTimer();
	void activateGameTimer();

	void changeTimeToScore();
	void loadNextLevel();
	void nextLevel();
	void sameLevel();
	void newGame();
	void onMarioDeath();

	void loadCurrentStageType();

	StringFactory* getStringFactory();

	int getGameWidth();
	int getGameHeight();

	int* getCurrentStage();

	SDL_Rect getMarioCamera();
	bool isObjectInCamera(Object* object);
	bool isChangingTimeToScore();
	const char* createStageString();

	GameBase* createObjectByIdentify(char identificator);

	void clearActionInactives();//For debbuging
	Mario* copyMario();

	int getLives();

private:

	void initFields();
	void loadGameFromObjectField();
	const char* createCurrentLevelPath();

	void changeTimeToScoreHandle();
	void loadCollMap(FILE* file);
	void loadStageType(FILE* file);

	bool changingTimeToScore_;
	bool gameTimerActive_;
	int points_;
	int coins_;
	int lives_;
	Interface* text_;
	Mario* marioChar_;
	List<GameBase*> actionActives_;
	List<GameBase*> otherObjects_;
	List<Object*> garbage_;
	StringFactory* stringFactory_;
	int gameWidth_;
	int gameHeight_;
	int time_;
	int currentStage_[2];
	int currentStageType_;
	bool gameLoad_;
};
