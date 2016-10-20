
#include "StringFactory.h"

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

SDL_Texture* StringFactory::createText(std::string text, int FONT_CONSTANT, int fontSize, SDL_Color color)
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
    std::string fontpath = getFontPath(FONT_CONSTANT);
    font_ = TTF_OpenFont(fontpath.c_str(), fontSize);
    if(font_ == NULL)
    {
        std::cout << "Font opening error: " << TTF_GetError() << std::endl;
        throw *(new std::exception);
    }
}

std::string StringFactory::getFontPath(int FONT_CONSTANT)
{
    switch(FONT_CONSTANT)
    {
    case FONT_BATMFA :
        return FONT_BATMFA_PATH;
    case FONT_MARIO :
        return FONT_MARIO_PATH;
    default:
        std::cout << "Make more font constants!" << std::endl;
        throw *(new std::exception);
    }
}

SDL_Texture* StringFactory::createTextTexture(std::string text)
{
    SDL_Surface* textSurface = TTF_RenderText_Solid(font_, text.c_str(), color_);
    if(textSurface == NULL)
    {
        std::cout << "TTF_RenderText error: " << TTF_GetError() << std::endl;
        throw *(new std::exception);
    }

    SDL_Texture* textTexture = SDL_CreateTextureFromSurface(renderer_, textSurface);
    if(textTexture == NULL)
    {
        std::cout << "CreateTextureFromSurface Error: " << SDL_GetError() << std::endl;
        throw *(new std::exception);
    }
    SDL_FreeSurface(textSurface);
    textSurface=nullptr;
    return textTexture;
}
