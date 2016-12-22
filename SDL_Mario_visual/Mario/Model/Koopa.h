
#pragma once

#include "Mob.h"
#include "../../Model/ManyPicAnimation.h"
#include "../../Controller/Timer.h"

#define VALUE_KOOPA 200

#define IDENTIFY_KOOPA 'K'

class KoopaAnimation;

class Koopa : public Mob
{
public:

    Koopa(MarioGame& game, KoopaAnimation* animation);

    void marioJumped() override;
    void touchedByMario() override;
    virtual void action() override;
    void otherMobTouch(Mob* otherMob) override;
    void die() override;
    int getValue() const override;
    void revive();
    void jump() override;
    void addWings();
    const char* loadObject(const char* objectLine) override;
    void addAtEndSave(FILE* file) override;
    bool isInShellMode();

private:

    void animateReviveHandle();
    void specifyMoveDirection();

    bool shellMode_;
    bool reviving_;
    bool wings_;
    Timer reviveTimer_;
};
