
#include <cstdlib>

#include "Browser.h"
#include "BrowserFireShot.h"
#include "../Controller/MarioGame.h"
#include "../Controller/BrowserAnimation.h"

Browser::Browser(MarioGame& game):Mob(game)
{
    setTexture(TEXTURE_BROWSER_MOVE_1);
    queryTexture();
    justShot_ = false;
    setAnimations(new BrowserAnimation(*this));
    shootAnimationTimer_.setActionsPerSec(0.5f);
    setMoveSpeed(BROWSER_MOVE_SPEED);
    setLayer(100);
}

void Browser::marioJumped()
{
    game_.getMainChar()->marioHit();
}

void Browser::jump()
{
    if(!(isInAir()))
        gravityFactor_ = 5.5f;
}

void Browser::action()
{
    Mob::action();
    turnSideToMario();

    if(allowToShoot())
        shootAction();

    if(allowToJump())
        jump();

    animateShotIfJustShot();
    resetJustShotFlagIfTimerAllows();

    if(allowToChangeMoveDirection())
        changeMoveDirection();
}

void Browser::turnSideToMario()
{
    Mario* mario = game_.getMainChar();
    int marioXPosition = mario->getShowingRect().x;
    int browserXPosition = getShowingRect().x;

    if(marioXPosition > browserXPosition)
        setFlipMode(SDL_FLIP_HORIZONTAL);
    else
        setFlipMode(SDL_FLIP_NONE);

}

bool Browser::allowToShoot()
{
    return (!justShot_) && rand()%250 == 0;
}

void Browser::shootAction()
{
    shoot();
    shootAnimationTimer_.reset();
}

void Browser::shoot()
{
    justShot_ = true;
    createFireShoot();
    game_.playSoundEfx(CHUNKSOUND_BROWSER_FIRE);
}

void Browser::createFireShoot()
{
    BrowserFireShoot* fire = new BrowserFireShoot(game_);
    if(getFlipMode() == SDL_FLIP_NONE)
    {
        fire->setCurrentMoveDirection(LEFT);
        fire->setBothPosition(getCollisionRect().x, getCollisionRect().y);
    }
    else
    {
        fire->setCurrentMoveDirection(RIGHT);
        fire->setBothPosition(getCollisionRect().x + getCollisionRect().w, getCollisionRect().y);
    }
    game_.addToGame(fire);
}

bool Browser::allowToJump()
{
    return rand()%250 == 0;
}

void Browser::animateShotIfJustShot()
{
    if(justShot_)
        Object::setTexture(((BrowserAnimation*)animations_)->animateShotWalk());
}

void Browser::resetJustShotFlagIfTimerAllows()
{
    if(justShot_)
    {
        shootAnimationTimer_.calculateTime();
        if(shootAnimationTimer_.askForAction())
            justShot_ = false;
    }
}

bool Browser::allowToChangeMoveDirection()
{
    return rand()%150 == 0;
}

void Browser::changeMoveDirection()
{
    if(currentDirection_ == RIGHT)
        currentDirection_ = LEFT;
    else
        currentDirection_ = RIGHT;
}
