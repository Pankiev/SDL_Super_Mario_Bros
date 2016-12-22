#pragma once

#include <vector>

#include "AbstractAnimation.h"

class ManyPicAnimation : public AbstractAnimation
{
public:

	ManyPicAnimation();

	void animateInit(float picturesPerSec);
	void addTexture(SDL_Texture* newTexture);
	void addTextures(SDL_Texture** newTextures, int texturesNo);
	bool nextPicture() override; //returns true at end of set
	void resetAnimation() override;

private:

	SDL_Texture* textureSet_[100];
	int texturesNumber_ = 0;
	unsigned int currentTexture_;
};
