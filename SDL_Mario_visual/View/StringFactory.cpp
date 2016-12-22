
#include "StringFactory.h"
#include "../ApplicationError.h"

StringFactory::StringFactory(SDL_Renderer* renderer)
{
    renderer_ = renderer;
    font_ = nullptr;
    currentFont_ = -1;
    currentFontSize_ = -1;
    color_ = {255,255,255,255};
}

StringFactory::~StringFactory()
{
    if(font_ != nullptr)
    {
        TTF_CloseFont(font_);
        font_ = nullptr;
    }
}

SDL_Texture* StringFactory::createText(const char* text, int FONT_CONSTANT, int fontSize, SDL_Color color)
{
    color_ = color;
    if(currentFont_ != FONT_CONSTANT || currentFontSize_ != fontSize)
    {
        if(font_ != nullptr)
        {
            TTF_CloseFont(font_);
            font_ = nullptr;
        }
        currentFont_ = FONT_CONSTANT;
        currentFontSize_  = fontSize;
        loadFont(currentFont_, currentFontSize_);
    }
    SDL_Texture* ret = createTextTexture(text);
    SDL_SetTextureColorMod(ret, color.r,color.g,color.b);
    return ret;
}

void StringFactory::loadFont(int FONT_CONSTANT, int fontSize)
{
    const char* fontpath = getFontPath(FONT_CONSTANT);
    font_ = TTF_OpenFont(fontpath, fontSize);
    if(font_ == NULL)
    {
        printf("Font opening error: %s\n", TTF_GetError());
        throw *(new ApplicationError);
    }
}

const char* StringFactory::getFontPath(int FONT_CONSTANT)
{
    switch(FONT_CONSTANT)
    {
    case FONT_BATMFA :
        return FONT_BATMFA_PATH;
    case FONT_MARIO :
        return FONT_MARIO_PATH;
    default:
        printf("Make more font constants!");
        throw *(new ApplicationError);
    }
}

SDL_Texture* StringFactory::createTextTexture(const char* text)
{
    SDL_Surface* textSurface = TTF_RenderText_Solid(font_, text, color_);
    if(textSurface == NULL)
    {
        printf("TTF_RenderText error: %s\n", TTF_GetError());
        throw *(new ApplicationError);
    }

    SDL_Texture* textTexture = SDL_CreateTextureFromSurface(renderer_, textSurface);
    if(textTexture == NULL)
    {
        printf("CreateTextureFromSurface Error: %s\n", SDL_GetError());
        throw *(new ApplicationError);
    }
    SDL_FreeSurface(textSurface);
    textSurface=nullptr;
    return textTexture;
}
