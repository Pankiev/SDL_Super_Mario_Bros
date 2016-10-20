
#pragma once

#include "Mob.h"

#define IDENTIFY_BROWSER '5'
#define BROWSER_MOVE_SPEED 40.0f

class Browser : public Mob
{
public:

    Browser(MarioGame& game);

    void action() override;
    char identify() const override {return IDENTIFY_BROWSER;}
    void marioJumped() override;
    void jump() override;

private:

    bool allowToShoot();
    void shootAction();
    void shoot();
    bool allowToJump();
    void animateShotIfJustShot();
    void resetJustShotFlagIfTimerAllows();
    void turnSideToMario();
    void createFireShoot();
    bool allowToChangeMoveDirection();
    void changeMoveDirection();

    bool justShot_;

    Timer shootAnimationTimer_;
};
