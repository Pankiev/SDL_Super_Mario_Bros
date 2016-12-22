
#include "BrowserFireShot.h"
#include "../Controller/MarioGame.h"

BrowserFireShoot::BrowserFireShoot(MarioGame& game):Mob(game)
{
    setTexture(TEXTURE_BROWSER_FIRE_SHOT_1);
    queryTexture();
    setMoveSpeed(BROWSER_SHOT_MOVE_SPEED);
    setTextures();
}

void BrowserFireShoot::setTextures()
{
    exist_.addTexture(game_.getTexture(TEXTURE_BROWSER_FIRE_SHOT_1));
    exist_.addTexture(game_.getTexture(TEXTURE_BROWSER_FIRE_SHOT_2));

    exist_.animateInit(15.0f);
}

void BrowserFireShoot::marioJumped()
{
    Mario* mario = game_.getMainChar();
    mario->marioHit();
}

void BrowserFireShoot::anyObjectHorizontalMoveTouch()
{
    GameBase::die();
}

void BrowserFireShoot::action()
{
    Mob::action();
    animate();
}

void BrowserFireShoot::animate()
{
    exist_.animate();
    Object::setTexture(exist_.getTexture());
}
