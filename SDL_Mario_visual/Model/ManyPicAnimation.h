
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

    std::vector<SDL_Texture*> textureSet_;
    unsigned int currentTexture_;
};
