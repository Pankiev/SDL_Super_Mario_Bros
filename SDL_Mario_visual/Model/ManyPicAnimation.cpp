
#include "ManyPicAnimation.h"

ManyPicAnimation::ManyPicAnimation()
{
	currentTexture_ = 0;
}

void ManyPicAnimation::addTexture(SDL_Texture* newTexture)
{
	textureSet_[texturesNumber_] = newTexture;
	texturesNumber_++;
}

void ManyPicAnimation::addTextures(SDL_Texture** newTextures, int texturesNo)
{
	for (int i = 0; i < texturesNo; i++)
		addTexture(newTextures[i]);
}

bool ManyPicAnimation::nextPicture()
{
	setTexture(textureSet_[currentTexture_]);

	if(currentTexture_++ >= texturesNumber_-1)
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
