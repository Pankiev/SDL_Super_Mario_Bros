#pragma once

#include <SDL.h>
#include <iostream>
#include <list>
#include "../Model/Object.h"
#include "SdlString.h"

class Renderer
{
public:

    Renderer();
    void createRenderer(SDL_Window* window);
    SDL_Renderer* getRenderer();
    void freeMemory();
    void renderObjects();
    void renderText();
    void renderAll();
    void renderShow();
    void renderClear();
    void add(Object* object);
    void add(SdlString* object);
    static void getDesktopResolution(int& width, int& height);
    void scaleImage(int gameWidth, int gameHeight);
    void renderPart(const SDL_Rect& camera);
    void showAll();

private:

    void initCamera();
    SDL_Rect getScaledRect(const SDL_Rect& rect);
    std::list<Object*>::iterator
    removeObject(std::list<Object*>::iterator i);

    std::list<SdlString*>::iterator
    removeText(std::list<SdlString*>::iterator i);

    SDL_Renderer* renderer_;
    SDL_Window* windowPtr_;
    std::list<Object*> objects_;
    std::list<SdlString*> text_;

    float showingWidthScale_;
    float showingHeightScale_;
    SDL_Texture* camera_;
};
