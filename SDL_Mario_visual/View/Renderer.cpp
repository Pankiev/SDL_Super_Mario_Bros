
#include "Renderer.h"

Renderer::Renderer()
{
    renderer_ = nullptr;
    windowPtr_ = nullptr;
    camera_ = nullptr;
    showingWidthScale_ = 1.0f;
    showingHeightScale_ = 1.0f;
}

void Renderer::createRenderer(SDL_Window* window)
{
    windowPtr_ = window;
    renderer_ = SDL_CreateRenderer(windowPtr_, -1, SDL_RENDERER_PRESENTVSYNC);
    if(renderer_ == NULL)
    {
        std::cout << "Renderer creating error: " << SDL_GetError() << std::endl;
        throw *(new std::exception);
    }
    initCamera();
}

void Renderer::renderAll()
{
    renderObjects();
    renderText();
}

void Renderer::renderObjects()
{
    std::list<Object*>::iterator i = objects_.begin();
    float w,h;
    SDL_RenderGetScale(getRenderer(), &w, &h);
    while(i != objects_.end())
    {
        if(((*i)->isRendering()))
        {
            SDL_Rect tempRect = (*i)->getShowingRect();
            SDL_RenderCopyEx(getRenderer(), (*i)->getTexture(),
            (*i)->getImageSourceRect(), &tempRect, (*i)->getRotationAngle(),
                             (*i)->getRotationPoint(), (*i)->getFlipMode());
            i++;
        }
        else
        {
            i = removeObject(i);
        }
    };
}

void Renderer::renderText()
{
    std::list<SdlString*>::iterator i = text_.begin();
    while(i != text_.end())
    {
        if(((*i)->isRendering()))
        {
            SDL_Rect tempRect = (*i)->getShowingRect();
            SDL_RenderCopy(getRenderer(), ((Object*)(*i))->getTexture(), NULL, &tempRect);
            i++;
        }
        else
        {
            i = removeText(i);
        }
    }
}

void Renderer::add(Object* object)
{
    bool added = false;

    for(std::list<Object*>::iterator i = objects_.begin(); i != objects_.end(); i++)
    {
        if((*i)->getLayer() > object->getLayer())
        {
            objects_.insert(i, object);
            added = true;
            break;
        }
    }
    if(!(added))
        objects_.push_back(object);
}

void Renderer::add(SdlString* text)
{
    text_.push_back(text);
}

void Renderer::renderClear()
{
    SDL_RenderClear(renderer_);
}

SDL_Renderer* Renderer::getRenderer()
{
    return renderer_;
}

void Renderer::freeMemory()
{
    if(renderer_ != nullptr)
    {
        SDL_DestroyRenderer(renderer_);
        renderer_ = nullptr;
    }
    if(camera_ != nullptr)
    {
        SDL_DestroyTexture(camera_);
        camera_ = nullptr;
    }
}

std::list<Object*>::iterator
Renderer::removeObject(std::list<Object*>::iterator i)
{
    return objects_.erase(i);
}

std::list<SdlString*>::iterator
Renderer::removeText(std::list<SdlString*>::iterator i)
{
    return text_.erase(i);
}

void Renderer::renderShow()
{
    SDL_RenderPresent(renderer_);
}

void Renderer::getDesktopResolution(int& width, int& height)
{
    SDL_DisplayMode d1;
    if(SDL_GetDesktopDisplayMode(0, &d1) != 0)
    {
        SDL_Log("Could not get display mode for video display: %s", SDL_GetError());
        throw *(new std::exception);
    }
    width = d1.w;
    height = d1.h;
}

void Renderer::scaleImage(int gameWidth, int gameHeight)
{
    int desktopWidth, desktopHeight;
    getDesktopResolution(desktopWidth, desktopHeight);

    showingWidthScale_ = (float)desktopWidth/gameWidth;
    showingHeightScale_ = (float)desktopHeight/gameHeight;
    SDL_RenderSetScale(getRenderer(), showingWidthScale_, showingHeightScale_);
}

void Renderer::initCamera()
{
    int desktopWidth, desktopHeight;
    getDesktopResolution(desktopWidth, desktopHeight);
    camera_ = SDL_CreateTexture
    (getRenderer(), SDL_PIXELFORMAT_RGBX8888, SDL_TEXTUREACCESS_TARGET, 7168, 1000);

    if(camera_ == nullptr)
    {
        std::cout << "Cannot create cameraTexture: " << SDL_GetError() << std::endl;
        throw *(new std::exception);
    }
}

void Renderer::renderPart(const SDL_Rect& camera)
{
    SDL_SetRenderTarget(getRenderer(), camera_);
    SDL_RenderSetClipRect(getRenderer(), &camera);
    SDL_RenderClear(getRenderer());

    renderAll();
    SDL_SetRenderTarget(getRenderer(), NULL);
    SDL_RenderCopy(getRenderer(), camera_, &camera, NULL);
}

SDL_Rect Renderer::getScaledRect(const SDL_Rect& rect)
{
    SDL_Rect ret = rect;
    ret.x *= showingWidthScale_;
    ret.w *= showingWidthScale_;
    ret.y *= showingHeightScale_;
    ret.h *= showingHeightScale_;
    return ret;
}
