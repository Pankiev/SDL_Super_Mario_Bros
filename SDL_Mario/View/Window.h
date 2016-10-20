#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <string>
#include "Renderer.h"

#define DEFAULT_ICON_PATH "images/icon.jpg"

class Window
{
public:

    Window();
    void createWindow(std::string title, int width, int height);
    SDL_Renderer* getRenderer();
    void freeMemory();
    void add(Object* object);
    void add(SdlString* object);
    void renderAll();
    void renderClear();
    void showImage();
    void setIcon(std::string iconPath);
    void scaleImage(int gameWidth, int gameHeight);
    SDL_Window* getWindow();
    void renderPart(const SDL_Rect& cameraRect);

private:

    SDL_Window* window_;
    Renderer renderer_;
};
