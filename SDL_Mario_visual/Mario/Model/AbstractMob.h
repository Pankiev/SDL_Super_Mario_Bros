
#pragma once

#include "GameBase.h"
#include "../Controller/AnimationSet.h"

class AbstractMob : public GameBase
{
public:

    AbstractMob(MarioGame& game);
    virtual ~AbstractMob();

    virtual void die() override;
    void setAnimations(AnimationSet* animations);
    AnimationSet* getAnimation();
    virtual void action();
    Object* gravityHandle();
    virtual void jump();
    virtual Object* walk(int direction);
    virtual char identify() const override=0;
    bool isInAir();
    bool isMob() const override {return true;}
    bool isBlock() const override {return false;}
    bool isActive() const override {return true;}
    bool isCollisionActive() const override {return true;}
    void noCollGravityHandle();
    void createPointsObject();
    void invincibilityMove(SDL_Point stopPoint);
    void invincibilityMoveHandle();
    bool isInvincibleMoving();
    void stopInvincibleMoving();
    float getGravityFactor();
    void setGravityFactor(float gravityFactor);

    MarioGame& getWorld();

protected:

    Object* touchObject(int direction);

    AnimationSet* animations_;
    float gravityFactor_;
    bool invincibilityMove_;
    SDL_Point invStopPoint_;
    SDL_Rect invInitialColl_;
    Object* invInitialObject_;
};
