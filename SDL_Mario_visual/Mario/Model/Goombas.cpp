
#include "Goombas.h"
#include "../Controller/GoombasAnimation.h"
#include "../Controller/MarioGame.h"

Goombas::Goombas(MarioGame& game, GoombasAnimation* animation):Mob(game)
{
    animations_ = animation;
    animations_->setTextures();
    setTexture(TEXTURE_GOOMBAS1MOVE_1);
    setBothRects({0,0,32,32});
    setMoveSpeed(60.0f);
}

int Goombas::getValue() const
{
    return POINTS_GOOMBAS;
}

void Goombas::marioJumped()
{
    Object::setTexture(animations_->animateDie());
    dieFirstPart();
    setMoveSpeed(0);
    game_.playSoundEfx(CHUNKSOUND_STOMP, PLAY_ONCE);
}
