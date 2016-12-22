#pragma once

#include <SDL.h>
#include <SDL_mixer.h>
#include <SDL_ttf.h>
#include <SDL_image.h>

#include <iostream>

#include "../View/Window.h"
#include "../View/TextureHolder.h"
#include "../Model/CollisionMap.h"
#include "../View/SdlString.h"
#include "../View/StringFactory.h"
#include "../View/Audio.h"
#include "../Model/MobileObject.h"
#include "Timer.h"
#include "HardwareController.h"

class Controller
{
public:

    Controller();
    ~Controller();

    virtual void run();

    void SDL_init();
    void SDL_quit();
    void init();
    void createWindow(const char* title="Unnamed", int width=900, int height=500);
    void createScreenSizedWindow(const char* title="Unnamed");
    void loadTextures();
    void freeMemory();
    void gameOver();
    bool isGameOver();
    void renderAll();
    void handleControllers();
    MobileObject* getMainChar();
    float getTimeFactor();
    CollisionMap* getCollsionMap();
    SDL_Texture* getTexture(int TEXTURE_CONSTANT);
    void addImage(Object* object);
    void addImage(SdlString* object);
    void playSoundEfx(int CHUNKSOUND_CONSTANT, int loops = PLAY_ONCE);
    void haltSoundEfx(int CHUNKSOUND_CONSTANT);
    bool isChunkSoundPlaying(int CHUNKSOUND_CONSTANT);
    void haltAllSoundEfx();
    void reRender();
    SDL_Renderer* getRenderer();
    void scaleImage(int gameWidth, int gameHeight);
    void debugRenderCollisionPoints();
    void debugRenderCollisionPoints(const SDL_Rect& camera);
    void reRenderPart(const SDL_Rect& camera);

protected:

    Timer gameTimer_;
    Audio audio_;
    TextureHolder textures_;
    CollisionMap* map_;
    Window window_;
    HardwareController hardwareController;
    bool gameOver_;
};
