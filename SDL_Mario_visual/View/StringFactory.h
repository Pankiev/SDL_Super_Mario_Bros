#pragma once
#include <SDL_ttf.h>
#include <iostream>

#define FONT_BATMFA_PATH "fonts/batmfa.ttf"
#define FONT_MARIO_PATH "fonts/marioFont.ttf"

enum
{
    FONT_BATMFA = 0,
    FONT_MARIO = 1
};

class Renderer;

class StringFactory
{
public:

    StringFactory(SDL_Renderer* renderer);
    ~StringFactory();

    SDL_Texture* createText(std::string text, int FONT_CONSTANT=FONT_BATMFA,
                            int fontSize=15, SDL_Color color={255,255,255,255});

private:

    void loadFont(int FONT_CONSTANT, int size);
    std::string getFontPath(int FONT_CONSTANT);
    SDL_Texture* createTextTexture(std::string text);

    SDL_Renderer* renderer_;
    TTF_Font* font_;
    int currentFont_;
    int currentFontSize_;
    SDL_Color color_;
};
