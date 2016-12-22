
#include "SdlString.h"
#include "../StringUtilities.h"

SdlString::SdlString(StringFactory* strFac, const char* message,
                     int FONT_CONSTANT, int fontSize, SDL_Color color)
{
    rectShow_.x = 0;
    rectShow_.y = 0;
    reloadText(strFac, message, FONT_CONSTANT, fontSize, color);
}

SdlString::~SdlString()
{
    freeTexture();
    stopRendering();
}

void SdlString::setTexture(SDL_Texture* text)
{
    freeTexture();
    Object::setTexture(text);
    SDL_QueryTexture(text, NULL, NULL, &rectShow_.w, &rectShow_.h);
}


void SdlString::reloadText(StringFactory* strFac, const char* message,
                     int FONT_CONSTANT, int fontSize, SDL_Color color)
{
    if(!(size(message) == 0) && strFac != nullptr)
    {
        setTexture(strFac->createText(message, FONT_CONSTANT, fontSize, color));
        render_ = true;
    }
}

void SdlString::freeTexture()
{
    if(getTexture() != nullptr)
    {
        SDL_DestroyTexture(getTexture());
        Object::setTexture(nullptr);
    }
}
