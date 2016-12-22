
#include "InterfaceCoin.h"
#include "../Controller/MarioGame.h"

InterfaceCoin::InterfaceCoin(MarioGame& game):GameBase(game)
{
    setTexture(TEXTURE_COIN_INTERFACE_1);
    queryTexture();
    animateInit();
    setLayer(5);
}

void InterfaceCoin::animateInit()
{
    exist_.addTexture(game_.getTexture(TEXTURE_COIN_INTERFACE_1));
    exist_.addTexture(game_.getTexture(TEXTURE_COIN_INTERFACE_1));
    exist_.addTexture(game_.getTexture(TEXTURE_COIN_INTERFACE_1));
    exist_.addTexture(game_.getTexture(TEXTURE_COIN_INTERFACE_2));
    exist_.addTexture(game_.getTexture(TEXTURE_COIN_INTERFACE_3));
    exist_.addTexture(game_.getTexture(TEXTURE_COIN_INTERFACE_2));

    exist_.animateInit(7.5f);
}

void InterfaceCoin::action()
{
    exist_.animate();
    Object::setTexture(exist_.getTexture());
}
