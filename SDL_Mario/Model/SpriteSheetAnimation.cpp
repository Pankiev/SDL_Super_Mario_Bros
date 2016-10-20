
#include "SpriteSheetAnimation.h"

SpriteSheetAnimation::SpriteSheetAnimation()
{
    columnsNo_ = 0;
    rowsNo_ = 0;
    currentX_ = 0;
    currentY_ = 0;
}

void SpriteSheetAnimation::animateInit(SDL_Texture* pictureSet,
                     int columnsNo, int rowsNo, float picturesPerSec)
{
    columnsNo_ = columnsNo;
    rowsNo_ = rowsNo;
    setTexture(pictureSet);
    SDL_QueryTexture(getTexture(), nullptr, nullptr, &bounds_.w, &bounds_.h);
    pictureTimer_.setActionsPerSec(picturesPerSec);
}

bool SpriteSheetAnimation::nextPicture()
{
    int imageWidth = bounds_.w/columnsNo_;
    int imageHeight = bounds_.h/rowsNo_;
    setImageSourceRect({(currentX_)*imageWidth, (currentY_)*imageHeight, imageWidth, imageHeight});

    if(++currentX_ >= columnsNo_)
    {
        currentX_ = 0;
        if(++currentY_ >= rowsNo_)
        {
            currentY_ = 0;
            return true;
        }
    }
    return false;
}

void SpriteSheetAnimation::resetAnimation()
{
    currentX_ = 0;
    currentY_ = 0;
    nextPicture();
}
