
#pragma once

#include "AbstractAnimation.h"

class SpriteSheetAnimation : public AbstractAnimation
{
public:

    SpriteSheetAnimation();

    void animateInit(SDL_Texture* pictureSet, int columnsNo, int rowsNo, float picturesPerSec);
    bool nextPicture() override; //returns true at end of set
    void resetAnimation() override;

private:

    int columnsNo_;
    int rowsNo_;
    int currentX_;
    int currentY_;
    SDL_Rect bounds_;
};
