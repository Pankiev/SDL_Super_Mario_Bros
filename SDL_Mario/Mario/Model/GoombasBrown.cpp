
#include "GoombasBrown.h"
#include "../Controller/GoombasBrownAnimation.h"

GoombasBrown::GoombasBrown(MarioGame& game):Goombas(game, new GoombasBrownAnimation(*this))
{

}
