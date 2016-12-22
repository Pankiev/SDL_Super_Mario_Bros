
#include "UnknownBlock.h"
#include "EmptyBlock.h"
#include "BlockCoin.h"
#include "Star.h"
#include "Mushroom1UP.h"
#include "../Controller/MarioGame.h"
#include "../../ApplicationError.h"
#include "../../StringUtilities.h"

UnknownBlock::UnknownBlock(MarioGame& game, int TEXTURE_TYPE, AbstractMob* content):
    ActiveBlock(game, TEXTURE_TYPE)
{
    content_ = content;
}

UnknownBlock::UnknownBlock(MarioGame& game, AbstractMob* content):ActiveBlock(game)
{
    content_ = content;
}

void UnknownBlock::marioHit()
{
    EmptyBlock* e1 = new EmptyBlock(game_);
    e1->setShowingRect(getShowingRect());
    e1->setCollisionRect(getCollisionRect());
    game_.addToGame(e1);
    die();
    Block::marioHit();

    if(content_ == nullptr)
        content_ = defineContent();

    content_->setShowingPosition(getShowingRect().x, getShowingRect().y);
    game_.addToGame(content_);
}

BlockItem* UnknownBlock::defineContent()
{
    Mario* mario = game_.getMainChar();

    if(mario->getMarioType() == MARIO_SMALL)
        return new Mushroom(game_);
    else
        return new LevelUpFlower(game_);
}

void UnknownBlock::addAtEndSave(std::ofstream& file)
{
    if(content_ != nullptr)
        file << content_->identify() << ' ';
}

const char* UnknownBlock::loadObject(const char* objectLine)
{
    objectLine = GameBase::loadObject(objectLine);
    if(size(objectLine) > 1)
    {
        content_ = createContentByIdentify(objectLine[0]);
        erase((char*)objectLine, 0, 2);
    }
    return objectLine;
}

AbstractMob* UnknownBlock::createContentByIdentify(char identification)
{
    switch(identification)
    {
        case IDENTIFY_BLOCK_COIN: return new BlockCoin(game_);
        case IDENTIFY_STAR: return new Star(game_);
        case IDENTIFY_MUSHROOM_1UP: return new Mushroom1UP(game_);
    default:
        throw *(new ApplicationError);
    }
}

