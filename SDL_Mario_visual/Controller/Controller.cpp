
#include "Controller.h"
#include "../ApplicationError.h"

Controller::Controller():hardwareController(*this)
{
    gameOver_ = false;
    map_ = nullptr;
}

Controller::~Controller()
{
    delete map_;
    SDL_quit();
}

void Controller::run()
{/*
    SDL_init();
    int screenWidth, screenHeight;
    Renderer::getDesktopResolution(screenWidth, screenHeight);
    createWindow("My game", screenWidth, screenHeight);
    scaleImage(GAME_WIDTH, GAME_HEIGHT);
    map_ = new CollisionMap(GAME_WIDTH, GAME_HEIGHT);
    window_.setIcon(DEFAULT_ICON_PATH);
    StringFactory stringFactory(window_.getRenderer());
    SdlString sdlString(&stringFactory, "Kupa", FONT_BATMFA, 30);
    textures_.loadTextures(window_.getRenderer());
    testObject_.setName("Test");
    testObject_.setId(-1);
    testObject_.setLayer(1000);
    testObject_.setTexture(textures_.getTexture(TEXTURE_TEST));
    window_.add(&testObject_);
    testObject_.setBothRects({400, 400, 50, 50});
    map_->update(&testObject_);
    Object test("asd");
    test.setTexture(textures_.getTexture(TEXTURE_SPACEINVADERS_INVADER1));
    test.setBothRects({500,350, 50, 50});
    addImage(&test);
    map_->update(&test);
    window_.add(&sdlString);
    audio_.loadMusic(MUSIC_TEST_PATH);
    audio_.loadChunkSounds();
    audio_.playplayMusic();
    audio_.setMusicVolume(50);
    audio_.setEfxVolume(50);
    audio_.playChunkSound(CHUNKSOUND_TEST);

    AnimatingMobileObject explosion("Explosion", 20, 20);
    explosion.animateInit(textures_.getTexture(TEXTURE_SPACEINVADERS_EXPLOSION_SET), 5, 5, 30.0f);
    explosion.setShowingRect(200,200, 100, 100);

    testObject_.setMoveSpeed(500.0f);
    window_.add(&explosion);
    while(!(isGameOver()))
    {
        explosion.animate();
        gameTimer_.calculateTime();
        handleControllers();
        window_.renderClear();
        window_.renderClear();
        window_.renderAll();
        window_.showImage();

        SDL_Delay(1);
    }
    freeMemory();*/
}

void Controller::SDL_init()
{
    if(SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        printf("Video or Audio Init Error %s\n", SDL_GetError());
        throw *(new ApplicationError);
    }

    if(IMG_InitFlags(IMG_INIT_PNG) != IMG_INIT_PNG)
    {
        printf("Images init error: %s\n", IMG_GetError());
        throw *(new ApplicationError);
    }

    if(TTF_Init() < 0)
    {
        printf("TTF Init Error: %s\n", TTF_GetError());
        throw *(new ApplicationError);
    }

    if(Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0)
    {
        printf("Audio opening error: %s\n", Mix_GetError());
        throw *(new ApplicationError);
    }
}

void Controller::init()
{
    createWindow("MyTitle");
    loadTextures();
}

void Controller::createWindow(std::string title, int width, int height)
{
    window_.createWindow(title, width, height);
}

void Controller::loadTextures()
{
    textures_.loadTextures(window_.getRenderer());
}

void Controller::SDL_quit()
{
    IMG_Quit();
    Mix_Quit();
    TTF_Quit();
    SDL_Quit();
}

float Controller::getTimeFactor()
{
    return gameTimer_.getInterval();
}

CollisionMap* Controller::getCollsionMap()
{
    return map_;
}

void Controller::handleControllers()
{
    hardwareController.handle();
}

void Controller::gameOver()
{
    gameOver_ = true;
}

bool Controller::isGameOver()
{
    return gameOver_;
}

void Controller::freeMemory()
{
    textures_.freeMemory();
    window_.freeMemory();
    audio_.freeMemory();
}

void Controller::renderAll()
{
    window_.renderAll();
}

SDL_Texture* Controller::getTexture(int TEXTURE_CONSTANT)
{
    return textures_.getTexture(TEXTURE_CONSTANT);
}

void Controller::addImage(Object* object)
{
    window_.add(object);
}

void Controller::playSoundEfx(int CHUNKSOUND_CONSTANT, int loops)
{
    audio_.playChunkSound(CHUNKSOUND_CONSTANT, loops);
}

void Controller::reRender()
{
    window_.renderClear();
    window_.renderAll();
    window_.showImage();
}

SDL_Renderer* Controller::getRenderer()
{
    return window_.getRenderer();
}

void Controller::addImage(SdlString* object)
{
    window_.add(object);
}

void Controller::scaleImage(int gameWidth, int gameHeight)
{
    window_.scaleImage(gameWidth, gameHeight);
}

void Controller::haltSoundEfx(int CHUNKSOUND_CONSTANT)
{
    audio_.haltChunkSound(CHUNKSOUND_CONSTANT);
}

void Controller::haltAllSoundEfx()
{
    audio_.haltAllChunkSounds();
}

bool Controller::isChunkSoundPlaying(int CHUNKSOUND_CONSTANT)
{
    return audio_.isChunkSoundPlaying(CHUNKSOUND_CONSTANT);
}

void Controller::debugRenderCollisionPoints()
{
    int mapWidth = map_->getWidth(), mapHeight = map_->getHeight();

    SDL_Color c;
    SDL_GetRenderDrawColor(getRenderer(), &c.r, &c.g, &c.b, &c.a);
    SDL_SetRenderDrawColor(getRenderer(), 200, 200, 200, 255);

    for(int i=0; i<mapHeight; i++)
        for(int j=0; j<mapWidth; j++)
            if(map_->getObjectInPosition(j, i) != nullptr)
                SDL_RenderDrawPoint(getRenderer(), j, i);

    SDL_SetRenderDrawColor(getRenderer(), c.r, c.g, c.b, c.a);
}

void Controller::debugRenderCollisionPoints(const SDL_Rect& camera)
{
    SDL_Color c;
    SDL_GetRenderDrawColor(getRenderer(), &c.r, &c.g, &c.b, &c.a);
    SDL_SetRenderDrawColor(getRenderer(), 200, 200, 200, 255);
    int desktopWidth, desktopHeight;
    Renderer::getDesktopResolution(desktopWidth, desktopHeight);
    for(int i=camera.y; i<camera.y+camera.h-1; i++)
        for(int j=camera.x; j<camera.x+camera.w-1; j++)
            if(map_->getObjectInPosition(j, i) != nullptr)
                SDL_RenderDrawPoint(getRenderer(), j, i);

    SDL_SetRenderDrawColor(getRenderer(), c.r, c.g, c.b, c.a);
}

void Controller::reRenderPart(const SDL_Rect& camera)
{
    window_.renderClear();
    window_.renderPart(camera);
    window_.showImage();
}

void Controller::createScreenSizedWindow(std::string title)
{
    int screenWidth, screenHeight;
    Renderer::getDesktopResolution(screenWidth, screenHeight);
    createWindow(title, screenWidth, screenHeight);
}
