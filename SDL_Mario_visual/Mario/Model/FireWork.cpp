
#include "FireWork.h"
#include "../Controller/MarioGame.h"

FireWork::FireWork(MarioGame& game):GameBase(game)
{
    setTexture(TEXTURE_FIREWORK_1);
    queryTexture();
    setCollisionHeight(0);
    setCollisionWidth(0);

    fireworkAnim_.addTexture(game_.getTexture(TEXTURE_FIREWORK_1));
    fireworkAnim_.addTexture(game_.getTexture(TEXTURE_FIREWORK_2));
    fireworkAnim_.addTexture(game_.getTexture(TEXTURE_FIREWORK_3));

    fireworkAnim_.animateInit(15.0f);
    actionActivate();
}

void FireWork::action()
{
    if(fireworkAnim_.animate())
        die();

    Object::setTexture(fireworkAnim_.getTexture());
}
