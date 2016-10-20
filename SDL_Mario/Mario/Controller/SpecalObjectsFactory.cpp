
#include "SpecalObjectsFactory.h"
#include "../Model/MovingPlatformElement.h"

SpecialObjectsFactory::SpecialObjectsFactory(MarioGame& game):game_(game)
{

}

void SpecialObjectsFactory::producePlatform(int length, int x, int y)
{
    for(int i=length-1; i>=0; i--)
    {
        MovingPlatformElement* e1 = new MovingPlatformElement(game_);
        e1->setCurrentMoveDirection(UP);
        e1->setBothPosition(x + PLATFORM_ELEMENT_WIDTH*i, y);
        e1->updateCollision();
        game_.addToGame(e1);
    }
}
