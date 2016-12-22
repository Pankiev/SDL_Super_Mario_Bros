#pragma once
#include "../../Model/MobileObject.h"
#include <fstream>

#define IDENTIFY_GAME_BASE 'g'

class MarioGame;

class GameBase : public MobileObject
{
public:

    GameBase(MarioGame& game);
    GameBase(MarioGame& game, int BLOCK_TYPE);

    bool isAlive();
    virtual void die();
    virtual bool isMob() const {return false;}
    virtual bool isBlock() const {return false;}
    virtual bool isMovingPlatform() const {return false;}
    virtual bool isActive() const {return false;}
    virtual bool isCollisionActive() const {return false;}
    virtual int getValue() const {return 0;}
    virtual char identify() const {return IDENTIFY_GAME_BASE;}
    virtual void action(){};
    void setTexture(int TEXTURE_CONSTANT);
    virtual void saveObject(FILE* file);
    virtual const char* loadObject(const char* objectLine);
    void addPoints();
    void actionActivate();
    bool isActionActive();
    void updateCollision();
    void clearItsCollision();
    bool wasMovedByPlatformInThisTurn();
    void justMovedByPlatform();

protected:


    void applyLoadValue(int LOAD_CONSTANT, int value);
    virtual void addAtEndSave(FILE* file){};

    MarioGame& game_;
    int defaultTexture_;
    bool isAlive_;
    bool actionActive_;
    bool movedByPlatform_;

private:

    bool isPipe(int TEXTURE_CONSTANT);
};
