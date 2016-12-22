
#pragma once

#include "Mob.h"
#include "../../Model/ManyPicAnimation.h"

#define IDENTIFY_BROWSER_SHOT '-'
#define BROWSER_SHOT_MOVE_SPEED 100.0f

class BrowserFireShoot : public Mob
{
public:

    BrowserFireShoot(MarioGame& game);
    void action() override;
    void marioJumped() override;
    void anyObjectHorizontalMoveTouch() override;
    bool isGravityActive() {return false;}
    char identify() const override {return IDENTIFY_BROWSER_SHOT;}

private:

    void setTextures();
    void animate();

    ManyPicAnimation exist_;
};

