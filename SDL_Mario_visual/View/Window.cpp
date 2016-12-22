
#include "Window.h"
#include "../ApplicationError.h"

Window::Window()
{
    window_ = nullptr;
}

void Window::createWindow(std::string title, int width, int height)
{
    window_ = SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
                     width, height, SDL_WINDOW_SHOWN);
    renderer_.createRenderer(window_);
}

SDL_Renderer* Window::getRenderer()
{
    return renderer_.getRenderer();
}

void Window::freeMemory()
{
    renderer_.freeMemory();
    if(window_ != nullptr)
    {
        SDL_DestroyWindow(window_);
        window_ = nullptr;
    }
}

void Window::add(Object* object)
{
    renderer_.add(object);
}

void Window::add(SdlString* sdlStr)
{
    renderer_.add(sdlStr);
}

void Window::renderAll()
{
    renderer_.renderAll();
}

void Window::renderClear()
{
    renderer_.renderClear();
}

void Window::showImage()
{
    renderer_.renderShow();
}

void Window::setIcon(std::string iconPath)
{
    SDL_Surface* icon_ = IMG_Load(iconPath.c_str());
    SDL_SetColorKey(icon_, SDL_TRUE, 0xFF00FF);
    if(icon_ == NULL)
    {
        printf("Icon loading error: %s\n", IMG_GetError());
        throw *(new ApplicationError);
    }
    SDL_SetWindowIcon(window_, icon_);
    SDL_FreeSurface(icon_);
}

void Window::scaleImage(int gameWidth, int gameHeight)
{
    renderer_.scaleImage(gameWidth, gameHeight);
}

SDL_Window* Window::getWindow()
{
    return window_;
}

void Window::renderPart(const SDL_Rect& cameraRect)
{
    renderer_.renderPart(cameraRect);
}
