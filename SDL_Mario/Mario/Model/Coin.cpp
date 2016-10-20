
#include "Coin.h"
#include "../Controller/MarioGame.h"

Coin::Coin(MarioGame& game):GameBase(game, TEXTURE_COIN_1)
{
    animateInit();
    setCollisionRect(rectCollision_.x+5, rectCollision_.y+2, rectCollision_.w-12, rectCollision_.h-4);
}

void Coin::action()
{
    exist_.animate();
    Object::setTexture(exist_.getTexture());

    if(detectCollision())
    {
        game_.addCoin();
        die();
    }
}

bool Coin::detectCollision()
{
    SDL_Rect marioCollRect = game_.getMainChar()->getCollisionRect();
    SDL_Rect cr = getCollisionRect();
    CollisionMap* map = game_.getCollsionMap();

    bool collision =
       (map->isPointInRect({cr.x, cr.y},                marioCollRect) ||
        map->isPointInRect({cr.x+cr.w-1,cr.y},          marioCollRect) ||
        map->isPointInRect({cr.x,cr.y+cr.h-1},          marioCollRect) ||
        map->isPointInRect({cr.x+cr.w-1,cr.y+cr.h-1},   marioCollRect));

    return collision;
}

void Coin::animateInit()
{
    exist_.addTexture(game_.getTexture(TEXTURE_COIN_1));
    exist_.addTexture(game_.getTexture(TEXTURE_COIN_2));
    exist_.addTexture(game_.getTexture(TEXTURE_COIN_3));
    exist_.addTexture(game_.getTexture(TEXTURE_COIN_2));
    exist_.addTexture(game_.getTexture(TEXTURE_COIN_1));

    exist_.animateInit(7.5f);
}

void Coin::die()
{
    addPoints();
    GameBase::die();
}
