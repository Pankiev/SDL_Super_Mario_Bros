
#include "PiranhaPlantBlue.h"
#include "../Controller/MarioGame.h"

PiranhaPlantBlue::PiranhaPlantBlue(MarioGame& game):PiranhaPlant(game)
{
    setTextures();
}

void PiranhaPlantBlue::setTextures()
{
    exist_.addTexture(game_.getTexture(TEXTURE_PIRANHA_PLANT_BLUE_1));
    exist_.addTexture(game_.getTexture(TEXTURE_PIRANHA_PLANT_BLUE_2));
}
