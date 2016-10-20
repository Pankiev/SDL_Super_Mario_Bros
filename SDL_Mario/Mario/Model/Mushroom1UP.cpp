
#include "Mushroom1UP.h"
#include "../Controller/MarioGame.h"
#include "String.h"

Mushroom1UP::Mushroom1UP(MarioGame& game):Mushroom(game)
{
    setTexture(TEXTURE_MUSHROOM_1UP);
    queryTexture();
}

void Mushroom1UP::marioTouch()
{
    game_.addLife();
    add_1UP_Text();
    GameBase::die();
}

void Mushroom1UP::add_1UP_Text()
{
    String* p1 = new String(game_, "1UP");
    p1->setBothPosition(getShowingRect().x, getShowingRect().y);
    game_.addToGame(p1);
}
