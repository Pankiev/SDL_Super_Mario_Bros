
#include "Mario.h"
#include "../Controller/MarioGame.h"
#include "../Controller/MarioAnimation.h"
#include "ActiveBlock.h"
#include "FireBall.h"
#include "../../ApplicationError.h"

Mario::Mario(MarioGame& game):Mob(game)
{
    setName(MARIO_NAME);
    setId(MARIO_ID);
    setLayer(11);
    setMoveSpeed(200.0f);
    setTexture(TEXTURE_MARIO_SMALL_MARIOSTAND);
    //setBothPosition(84, 708);
    setBothPosition(84, 400);
    queryTexture();
    lastCamera_ = {0,0,0,0};
    setAnimations(new MarioAnimation(*this));
    marioType_ = MARIO_SMALL;
    lvlUping_ = false;
    lvlUpTimer_.setActionsPerSec(1.2f);
    shrinkTimer_.setActionsPerSec(1.2f);
    dieTimer_.setActionsPerSec(0.25f);
    dieWait_.setActionsPerSec(1.0f);
    shootTimer_.setActionsPerSec(4.0f);
    flagWaitTimer_.setActionsPerSec(1.0f);
    levelEndMoveTimer_.setActionsPerSec(0.55f);
    endWaitTimer_.setActionsPerSec(0.75f);
    slideFactor_ = 0.0f;
    waitDie_ = false;
    shrinking_ = false;
    invincible_ = false;
    squatting_ = false;
    pipeEnter_ = false;
    levelEnd_ = false;
    climb_ = false;
    flagWait_ = false;
    levelEndMove_ = false;
    endLevelWaiting_ = false;
    invincibilityFastChunkSoundPlaying_ = false;
    actionActivate();
}

SDL_Rect Mario::calcCameraRect(int gameWidth, int gameHeight)
{
    SDL_Rect camera;
    camera.x = rectShow_.x - (CAMERA_WIDTH - rectShow_.w)/2;
    camera.y = 350;
    camera.w = CAMERA_WIDTH;
    camera.h = CAMERA_HEIGHT;

    if(camera.x < lastCamera_.x)
        camera.x = lastCamera_.x;

    if(camera.y < 0)
        camera.y = 0;

    if(camera.x + camera.w > gameWidth-12)
        camera.x -= (camera.x + camera.w - gameWidth+12);

    if(camera.y + camera.h > gameHeight)
        camera.y -= (camera.y + camera.h - gameHeight);

    lastCamera_ = camera;
    return camera;
}

void Mario::action()
{
    movedByPlatform_ = false;
    if(!(dying_))
    {
        GameBase* coll = nullptr;
        if(lvlUping_)
            levelUpHandle();
        else if(shrinking_)
            shrinkHandle();
        else if(invincibilityMove_)
            invincibilityMoveHandle();
        else
            coll = (GameBase*)gravityHandle();


        if(levelEnd_)
            levelEndSequenceHandle();
        else if(invincible_)
            invincibilityHandle();

        if(coll != nullptr)
        {
            if(coll->getId() == BORDER_ID)
                die();
            else
            {
                if(coll->isMob())
                {
                    ((Mob*)coll)->marioJumped();
                    gravityFactor_ = 1.2f;
                }
                else if(isInAir() && coll->isBlock())
                   ((Block*)coll)->marioHit();
            }
        }
        if(!(isInvincibleMoving()))
            slideHandle(1.5f, 2.0f);
    }
    else
        dyingHandle();
}

Object* Mario::walk(int direction)
{
    Object* coll = nullptr;
    if((direction != LEFT || rectCollision_.x >= lastCamera_.x) && !lvlUping_ && !shrinking_)
        coll = AbstractMob::walk(direction);

    if(mobCheck(coll))
        ((Mob*)coll)->touchedByMario();

    return coll;
}

void Mario::stand()
{
    Object::setTexture(animations_->animateStand());
}

void Mario::setMarioType(int MARIO_CONSTANT)
{
    marioType_ = MARIO_CONSTANT;
}

void Mario::die()
{
    dieFirstPart();
    gravityFactor_ = 8.0f;
    dieWait_.reset();
    waitDie_ = true;
    game_.haltAllSoundEfx();
    game_.playSoundEfx(CHUNKSOUND_MARIO_DEATH, PLAY_ONCE);
}

void Mario::jump()
{
    Object::setTexture(animations_->animateJump());
    Mob::jump();
    if(!(isInAir()))
    {
        if(marioType_ == MARIO_SMALL)
            game_.playSoundEfx(CHUNKSOUND_MARIO_SMALLJUMP, PLAY_ONCE);
        else
            game_.playSoundEfx(CHUNKSOUND_MARIO_BIGJUMP, PLAY_ONCE);
    }
}

void Mario::grow()
{
    marioType_ = MARIO_BIG;
    lvlUping_ = true;
    lvlUpTimer_.reset();
    game_.getCollsionMap()->clearColl(getCollisionRect());
}

void Mario::shrink()
{
    marioType_ = MARIO_SMALL;
    squatting_ = false;
    shrinking_ = true;
    shrinkTimer_.reset();
    game_.getCollsionMap()->clearColl(getCollisionRect());
    game_.playSoundEfx(CHUNKSOUND_MARIO_SHRINK);
}

int Mario::getMarioType()
{
    return marioType_;
}

void Mario::growHandle()
{
    Object::setTexture(((MarioAnimation*)animations_)->animateGrow());
    SDL_Rect temp = getShowingRect();
    queryTexture();
    rectShow_.y -= rectShow_.h-temp.h;
    rectShow_.w -= rectShow_.w-temp.w;
    lvlUpTimer_.calculateTime();
    if(lvlUpTimer_.askForAction())
    {
        lvlUping_ = false;
        setCollisionRect(getShowingRect());
        game_.getCollsionMap()->update(this);
    }
}

void Mario::shrinkHandle()
{
    Object::setTexture(((MarioAnimation*)animations_)->animateShrink());
    SDL_Rect temp = getShowingRect();
    queryTexture();
    rectShow_.y -= rectShow_.h-temp.h;
    rectShow_.w -= rectShow_.w-temp.w;
    shrinkTimer_.calculateTime();
    if(shrinkTimer_.askForAction())
    {
        shrinking_ = false;
        setCollisionRect(getShowingRect());
        game_.getCollsionMap()->update(this);
    }
}

void Mario::dyingHandle()
{
    setMoveSpeed(100.0f);
    Object::setTexture(((MarioAnimation*)animations_)->animateDie());

    if(waitDie_)
    {
        dieWait_.calculateTime();
        if(dieWait_.askForAction())
            waitDie_ = false;
    }
    else
    {
        noCollGravityHandle();
        dieTimer_.calculateTime();
        if(dieTimer_.askForAction())
        {
            //AbstractMob::die();
            //game_.gameOver();
            game_.onMarioDeath();
        }
    }
}

bool Mario::isShrinking()
{
    return shrinking_;
}

bool Mario::isLevelingUp()
{
    return lvlUping_;
}

void Mario::marioHit()
{
    if(!shrinking_)
    {
        if(marioType_ == MARIO_SMALL)
            die();
        else
            shrink();
    }
}

bool Mario::mobCheck(Object* coll)
{
    if(coll != nullptr && coll->getId() != BORDER_ID
       && ((GameBase*)coll)->isMob())
        return true;
    return false;
}

void Mario::slideMove(int direction, float acceleration)
{
    if(direction == LEFT)
        slideFactor_ -= acceleration*game_.getTimeFactor();
    else if(direction == RIGHT)
        slideFactor_ += acceleration*game_.getTimeFactor();
    else
    {
        printf("Something went wrong!\n");
        throw *(new ApplicationError);
    }
}

Object* Mario::slideHandle(float maxSpeed, float deceleration)
{
    float tempMoveSpeed = moveSpeed_;
    Object* coll = nullptr;

    if(slideFactor_ < -0.1f)
    {
        if(slideFactor_ <= -maxSpeed)
            slideFactor_ = -maxSpeed;

        slideFactor_ += deceleration*game_.getTimeFactor();
        moveSpeed_ *= slideFactor_;
        coll = walk(LEFT);
    }
    else if(slideFactor_ > 0.1f)
    {
        if(slideFactor_ >= maxSpeed)
            slideFactor_ = maxSpeed;

        slideFactor_ -= deceleration*game_.getTimeFactor();
        moveSpeed_ *= slideFactor_;
        coll = walk(RIGHT);
    }

    if(coll != nullptr && !(invincible_))
        slideFactor_ = 0.0f;

    moveSpeed_ = tempMoveSpeed;

    return coll;
}

float Mario::getSlideFactor()
{
    return slideFactor_;
}

void Mario::levelUp()
{
    if(marioType_ == MARIO_SMALL)
        grow();
    else if(marioType_ == MARIO_BIG)
        transformFireMario();
}

void Mario::levelUpHandle()
{
    if(getMarioType() == MARIO_BIG)
        growHandle();
    else if(getMarioType() == MARIO_FIRE)
        transformFireMarioHandle();
}

void Mario::transformFireMario()
{
    marioType_ = MARIO_FIRE;
    lvlUping_ = true;
    lvlUpTimer_.reset();
    game_.getCollsionMap()->clearColl(getCollisionRect());
}

void Mario::transformFireMarioHandle()
{
    Object::setTexture(((MarioAnimation*)animations_)->animateTransformFire());
    lvlUpTimer_.calculateTime();
    if(lvlUpTimer_.askForAction())
    {
        lvlUping_ = false;
        game_.getCollsionMap()->update(this);
    }
}

void Mario::invincibilityActivate()
{
    invincible_ = true;
    game_.haltAllSoundEfx();
    game_.playSoundEfx(CHUNKSOUND_INVINCIBILITY, 2);
}

void Mario::invincibilityHandle()
{
    if(!(game_.isChunkSoundPlaying(CHUNKSOUND_INVINCIBILITY))
        && !(invincibilityFastChunkSoundPlaying_))
    {
        game_.playSoundEfx(CHUNKSOUND_INVINCIBILITY_FAST, 0);
        invincibilityFastChunkSoundPlaying_ = true;
    }
    if(invincibilityFastChunkSoundPlaying_ && !(game_.isChunkSoundPlaying(CHUNKSOUND_INVINCIBILITY_FAST)))
    {
        invincibilityFastChunkSoundPlaying_ = false;
        invincible_ = false;
        game_.loadCurrentStageType();
    }
}

void Mario::shoot()
{
    if(getMarioType() == MARIO_FIRE)
    {
        shootTimer_.calculateTime();
        if(shootTimer_.askForAction())
        {
            FireBall* fireBall = new FireBall(game_);
            SDL_Point fireBallPos = calcFireBallStartingPos();
            fireBall->setBothPosition(fireBallPos.x, fireBallPos.y);
            game_.getCollsionMap()->update(fireBall);
            game_.addToGame(fireBall);
            game_.playSoundEfx(CHUNKSOUND_FIREBALL);
        }
    }
}

SDL_Point Mario::calcFireBallStartingPos()
{
    if(getFlipMode() == SDL_FLIP_NONE)
        return {rectShow_.x + rectShow_.w+10, rectShow_.y};
    else
        return {rectShow_.x - rectShow_.w-7, rectShow_.y};
}

bool Mario::isInvincible()
{
    return invincible_;
}

void Mario::stopMoving()
{
    setGravityFactor(0.0f);
    slideFactor_ = 0.0f;
}

void Mario::squat()
{
    if(marioType_ != MARIO_SMALL && !squatting_)
    {
        game_.getCollsionMap()->clearColl(getCollisionRect());
        setBothRects({getShowingRect().x, getShowingRect().y+32, getShowingRect().w, getShowingRect().h-32});
        game_.getCollsionMap()->update(this);
        squatting_ = true;
    }
}

void Mario::standUp()
{
    if(getMarioType() != MARIO_SMALL && isSquatting()
       && game_.getCollsionMap()->checkForSpace(32, UP, getCollisionRect()) == nullptr)
    {
        setBothRects({getShowingRect().x, getShowingRect().y-32, getShowingRect().w, getShowingRect().h+32});
        game_.getCollsionMap()->update(this);
        squatting_ = false;
    }
}

bool Mario::isSquatting()
{
    return squatting_;
}

void Mario::pipeEnter()
{
    pipeEnter_ = true;
}

void Mario::keepOutOfPipe()
{
    pipeEnter_ = false;
}

bool Mario::isPipeEnterAccepting()
{
    return pipeEnter_;
}

void Mario::levelEndSequence(int flagXPosition)
{
    levelEnd_ = true;
    climb_ = true;
    stopMoving();
    setMoveSpeed(100.0f);
    invincibilityMove({flagXPosition, 704});
    game_.haltAllSoundEfx();
    game_.playSoundEfx(CHUNKSOUND_LEVEL_END);
    game_.freezeGameTimer();
}

void Mario::levelEndSequenceHandle()
{
    if(climb_)
        climbDownHandle();
    else if(flagWait_)
        flagWaitHandle();
    else if(levelEndMove_)
        levelEndMoveHandle();
    else if(!(game_.isChangingTimeToScore()) && !endLevelWaiting_)
    {
        endWaitTimer_.reset();
        endLevelWaiting_ = true;
    }
    else if(endLevelWaiting_)
    {
        endWaitTimer_.calculateTime();
        if(endWaitTimer_.askForAction())
        {
            endLevelWaiting_ = false;
            levelEnd_ = false;
            game_.nextLevel();
        }
    }

}

void Mario::climbDownHandle()
{
    Object::setTexture(((MarioAnimation*)animations_)->animateClimb());
    invincibilityMoveHandle();
    if(!(isInvincibleMoving()))
    {
        climb_ = false;
        game_.getCollsionMap()->clearColl(getCollisionRect());
        setBothPosition(getShowingRect().x+16, getShowingRect().y);
        setFlipMode(SDL_FLIP_HORIZONTAL);
        flagWaitTimer_.reset();
        flagWait_ = true;
    }
}

void Mario::flagWaitHandle()
{
    switch(getMarioType())
    {
        case MARIO_SMALL: setTexture(TEXTURE_MARIO_SMALL_CLIMB_1); break;
        case MARIO_BIG: setTexture(TEXTURE_MARIO_BIG_CLIMB_1); break;
        case MARIO_FIRE: setTexture(TEXTURE_MARIO_FIRE_CLIMB_1); break;
    }
    flagWaitTimer_.calculateTime();
    if(flagWaitTimer_.askForAction())
    {
        flagWait_ = false;
        levelEndMoveTimer_.reset();
        levelEndMove_ = true;
        setFlipMode(SDL_FLIP_NONE);
    }
}

void Mario::levelEndMoveHandle()
{
    levelEndMoveTimer_.calculateTime();
    if(levelEndMoveTimer_.askForAction())
    {
        stopRendering();
        game_.changeTimeToScore();
        levelEndMove_ = false;
    }
    else
        walk(RIGHT);
}

bool Mario::isLevelEnding()
{
    return levelEnd_;
}

void Mario::resetCamera()
{
    lastCamera_ = {0,0,0,0};
}
