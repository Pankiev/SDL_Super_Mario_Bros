#pragma once
#include "Mob.h"
#include "../../Controller/Timer.h"

#define MARIO_ID 2
#define MARIO_NAME "Mario"
#define IDENTIFY_MARIO 'M'

class MarioGame;

enum
{
    MARIO_SMALL = 0,
    MARIO_BIG = 1,
    MARIO_FIRE = 2,
};

class Mario : public Mob
{
public:

    Mario(MarioGame& game);
    void action() override;
    SDL_Rect calcCameraRect(int gameWidth, int gameHeight);
    Object* walk(int direction) override;
    void stand();
    void die() override;
    void jump() override;
    void grow();
    int getMarioType();
    void shrink();
    void shrinkHandle();
    void growHandle();
    void dyingHandle();
    void marioTouch() override{}
    void marioJumped() override{}
    bool isShrinking();
    bool isLevelingUp();
    void marioHit();
    void slideMove(int direction, float acceleration);
    Object* slideHandle(float maxSpeed, float deceleration);
    float getSlideFactor();
    void levelUp();
    void levelUpHandle();
    void transformFireMario();
    void transformFireMarioHandle();
    void invincibilityActivate();
    void invincibilityHandle();
    void shoot();
    char identify() const override {return IDENTIFY_MARIO;}
    bool isInvincible();
    void saveObject(std::ofstream& file) override {}
    void stopMoving();
    void squat();
    void standUp();
    bool isSquatting();
    void pipeEnter();
    void keepOutOfPipe();
    bool isPipeEnterAccepting();
    void levelEndSequence(int flagXPosition);
    void levelEndSequenceHandle();
    void flagWaitHandle();
    void levelEndMoveHandle();
    bool isLevelEnding();
    void resetCamera();
    void setMarioType(int MARIO_CONSTANT);

    void climbDown();
    void climbDownHandle();

private:

    bool mobCheck(Object* coll);
    SDL_Point calcFireBallStartingPos();

    SDL_Rect lastCamera_;
    int marioType_;
    bool lvlUping_;
    bool shrinking_;
    bool squatting_;
    Timer lvlUpTimer_;
    Timer shrinkTimer_;
    Timer dieWait_;
    Timer shootTimer_;
    Timer flagWaitTimer_;
    Timer levelEndMoveTimer_;
    Timer endWaitTimer_;
    bool endLevelWaiting_;
    bool flagWait_;
    bool levelEndMove_;
    bool invincible_;
    bool waitDie_;
    bool pipeEnter_;
    float slideFactor_;
    bool levelEnd_;
    bool climb_;

    bool invincibilityFastChunkSoundPlaying_;
};
