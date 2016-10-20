
#include "PiranhaPlantGreen.h"
#include "../Controller/MarioGame.h"

PiranhaPlantGreen::PiranhaPlantGreen(MarioGame& game):PiranhaPlant(game)
{
    setTextures();
}

void PiranhaPlantGreen::setTextures()
{
    exist_.addTexture(game_.getTexture(TEXTURE_PIRANHA_PLANT_GREEN_1));
    exist_.addTexture(game_.getTexture(TEXTURE_PIRANHA_PLANT_GREEN_2));
}
