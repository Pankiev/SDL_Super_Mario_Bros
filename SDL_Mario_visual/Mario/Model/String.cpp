
#include "String.h"

String::String(MarioGame& game, const char*text):String(game)
{
    loadString(text);
}

String::String(MarioGame& game):GameBase(game)
{
    setMoveSpeed(130.0f);
    existTimer_.setActionsPerSec(1.2f);
    existTimer_.reset();
}

void String::action()
{
    move(UP, game_.getTimeFactor());

    existTimer_.calculateTime();
    if(existTimer_.askForAction())
        die();
}

void String::loadString(const char* text)
{
    StringFactory* strFac = game_.getStringFactory();
    Object::setTexture(strFac->createText(text, FONT_MARIO, 10));
    queryTexture();
}
