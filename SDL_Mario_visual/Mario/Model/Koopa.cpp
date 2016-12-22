
#include "../Controller/MarioGame.h"
#include "../Controller/KoopaAnimation.h"
#include "Koopa.h"
#include "Mario.h"
#include "../../StringUtilities.h"

Koopa::Koopa(MarioGame& game, KoopaAnimation* animation):Mob(game)
{
    setAnimations(animation);
    setTexture(TEXTURE_KOOPA1_WALK_1);
    queryTexture();
    setMoveSpeed(60.0f);
    reviveTimer_.setActionsPerSec(0.2f);
    shellMode_ = false;
    reviving_ = false;
    wings_ = false;
}

void Koopa::marioJumped()
{
    if(wings_)
    {
        wings_ = false;
        game_.playSoundEfx(CHUNKSOUND_STOMP);
        gravityFactor_= -1.0f;
    }
    else if(!(shellMode_))
    {
        shellMode_ = true;
        reviveTimer_.reset();
        setMoveSpeed(330.0f);
        currentDirection_ = DIRECTION_NONE;
        Object::setTexture(animations_->animateStand());
        CollisionMap* map = game_.getCollsionMap();
        map->clearColl(getCollisionRect());
        queryTexture();
        setBothPosition(rectShow_.x, rectShow_.y+15);
        map->update(this);
        game_.playSoundEfx(CHUNKSOUND_STOMP);
    }
    else
    {
        if(currentDirection_ != DIRECTION_NONE)
        {
            currentDirection_ = DIRECTION_NONE;
            game_.playSoundEfx(CHUNKSOUND_STOMP);
        }
        else
        {
            specifyMoveDirection();
            game_.playSoundEfx(CHUNKSOUND_MOB_HIT);
        }

        reviving_ = false;
        reviveTimer_.reset();
    }
    createPointsObject();
}

int Koopa::getValue() const
{
    return VALUE_KOOPA;
}

void Koopa::action()
{
    Mob::action();

    if(wings_)
    {
        jump();
        Object::setTexture(animations_->animateJump());
    }
    else if(reviving_)
        animateReviveHandle();
    else if(shellMode_)
        Object::setTexture(animations_->animateStand());

    if(shellMode_ && currentDirection_ == DIRECTION_NONE)
    {
        reviveTimer_.calculateTime();
        if(reviveTimer_.askForAction())
        {
            if(reviving_)
                revive();
            else
            {
                reviving_ = true;
                setFlipMode(SDL_FLIP_HORIZONTAL);
                reviveTimer_.setActionsPerSec(0.4f);
            }
        }
    }
}

void Koopa::touchedByMario()
{
    if(shellMode_)
    {
        if(currentDirection_ == DIRECTION_NONE)
        {
            specifyMoveDirection();
            game_.playSoundEfx(CHUNKSOUND_MOB_HIT);
            createPointsObject();
        }
        reviving_ = false;
    }
    else
        Mob::marioTouch();
}

void Koopa::specifyMoveDirection()
{
    Mario* mario = game_.getMainChar();
    if(mario->getShowingRect().x <= getShowingRect().x)
        currentDirection_ = RIGHT;
    else
        currentDirection_ = LEFT;
}

void Koopa::otherMobTouch(Mob* otherMob)
{
    if(shellMode_ && otherMob != this)
    {
        otherMob->die();
        turnAround();
    }
}

void Koopa::die()
{
    Mob::die();
    Object::setTexture(animations_->animateDie());
    queryTexture();
}

void Koopa::revive()
{
    shellMode_ = false;
    reviving_ = false;
    setMoveSpeed(60.0f);
    currentDirection_ = RIGHT;
    game_.getCollsionMap()->clearColl(getCollisionRect());
    setTexture(TEXTURE_KOOPA1_WALK_1);
    queryTexture();
    setBothPosition(getCollisionRect().x, getCollisionRect().y-20);
    game_.getCollsionMap()->update(this);
}

void Koopa::animateReviveHandle()
{
    static SDL_Texture* previous = nullptr;
    Object::setTexture(((KoopaAnimation*)animations_)->animateRevive());
    queryTexture();
    SDL_Rect rectShow = getShowingRect();
    if(previous != getTexture())
    {
        if(getTexture() == game_.getTexture(TEXTURE_KOOPA1_WALK_1))
            setShowingRect({rectShow.x, rectShow.y-20, rectShow.w, rectShow.h});
        else
            setShowingRect({rectShow.x, rectShow.y+20, rectShow.w, rectShow.h});
    }

    previous = getTexture();
}

void Koopa::jump()
{
    if(!(isInAir()))
        gravityFactor_ = 5.5f;
}

void Koopa::addWings()
{
    wings_ = true;
}

const char* Koopa::loadObject(const char* objectLine)
{
    objectLine = GameBase::loadObject(objectLine);
    if(objectLine[0] == '1')
        addWings();
	erase((char*)objectLine, 0, 2);
    return objectLine;
}

void Koopa::addAtEndSave(std::ofstream& file)
{
    file << wings_ << ' ';
}

bool Koopa::isInShellMode()
{
    return shellMode_;
}
