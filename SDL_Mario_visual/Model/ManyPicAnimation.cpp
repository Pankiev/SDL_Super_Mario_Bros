
#include "ManyPicAnimation.h"

ManyPicAnimation::ManyPicAnimation()
{
    currentTexture_ = 0;
}

void ManyPicAnimation::addTexture(SDL_Texture* newTexture)
{
    textureSet_.push_back(newTexture);
}

void ManyPicAnimation::addTextures(SDL_Texture** newTextures, int texturesNo)
{
    for(int i=0; i<texturesNo; i++)
        textureSet_.push_back(newTextures[i]);
}

bool ManyPicAnimation::nextPicture()
{
    setTexture(textureSet_[currentTexture_]);

    if(currentTexture_++ >= textureSet_.size()-1)
    {
        currentTexture_ = 0;
        return true;
    }
    return false;
}

void ManyPicAnimation::resetAnimation()
{
    currentTexture_ = 0;
    nextPicture();
}

void ManyPicAnimation::animateInit(float picturesPerSec)
{
    pictureTimer_.setActionsPerSec(picturesPerSec);
}
