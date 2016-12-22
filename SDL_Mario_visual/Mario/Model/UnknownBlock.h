#pragma once

#include "ActiveBlock.h"
#include "../../Model/ManyPicAnimation.h"

#include "LevelUpFlower.h"

#define IDENTIFY_UNKNOWN_BLOCK 'u'

class UnknownBlock : public ActiveBlock
{
public:

    UnknownBlock(MarioGame& game, int TEXTURE_TYPE, AbstractMob* content = nullptr);
    UnknownBlock(MarioGame& game, AbstractMob* content = nullptr);

    void marioHit() override;
    virtual char identify() const override {return IDENTIFY_UNKNOWN_BLOCK;}
    std::string loadObject(std::string objectLine) override;
    void addAtEndSave(std::ofstream& file) override;

protected:

    AbstractMob* createContentByIdentify(char identification);
    BlockItem* defineContent();

    AbstractMob* content_;
};
