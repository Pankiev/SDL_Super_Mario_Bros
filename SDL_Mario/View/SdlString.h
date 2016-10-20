#pragma once
#include <SDL.h>
#include <SDL_ttf.h>
#include <iostream>
#include "StringFactory.h"
#include "../Model/Object.h"

class SdlString : public Object
{
public:

    SdlString(StringFactory* strFac=nullptr, std::string message="", int FONT_CONSTANT=FONT_BATMFA,
              int fontSize=15, SDL_Color color={255,255,255,255});
    ~SdlString();

    void reloadText(StringFactory* strFac=nullptr, std::string message="", int FONT_CONSTANT=FONT_BATMFA,
              int fontSize=15, SDL_Color color={255,255,255,255});
    void setTexture(SDL_Texture* text) override;
    void freeTexture();
};
