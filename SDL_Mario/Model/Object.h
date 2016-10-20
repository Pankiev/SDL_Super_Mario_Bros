#pragma once
#include <SDL.h>
#include <iostream>

#define SDL_FLIP_BOTH (SDL_RendererFlip)(SDL_FLIP_HORIZONTAL | SDL_FLIP_VERTICAL)

enum
{
    LEFT = 0,
    RIGHT = 1,
    UP = 2,
    DOWN = 3,
    DIRECTION_NONE = 4
};

class CollisionMap;

class Object
{
public:

    Object(std::string name="Unnamed", int id=0, int layer=0);
    virtual ~Object();

    SDL_Rect        getCollisionRect() const;
    SDL_Rect        getShowingRect() const;
    SDL_Texture*    getTexture() const;
    SDL_Rect*       getImageSourceRect() const;
    SDL_Point*      getRotationPoint();
    SDL_RendererFlip getFlipMode() const;
    int             getId() const;
    int             getLayer() const;
    double          getRotationAngle() const;
    std::string     getName() const;
    bool isRendering() const;

    void setShowingRect(const SDL_Rect&);
    void setShowingRect(int x, int y, int width, int height);
    void setCollisionRect(const SDL_Rect&);
    void setCollisionRect(int x, int y, int width, int height);
    void setBothRects(const SDL_Rect& rect);
    void setImageSourceRect(const SDL_Rect& rect);
    void setName(std::string name);
    void setId(int id);
    void setLayer(int layer);
    void setShowingPosition(int x, int y);
    void setShowingX(int x);
    void setShowingY(int y);
    void setCollisionX(int x);
    void setCollisionY(int y);
    void setCollisionPosition(int x, int y);
    void setBothPosition(int x, int y);
    void setCollisionWidth(int width);
    void setCollisionHeight(int height);
    void setShowingWidth(int width);
    void setShowingHeight(int height);
    virtual void setTexture(SDL_Texture* texture);
    void setRotationPoint(const SDL_Point& rotationPoint);
    void setFlipMode(SDL_RendererFlip SDL_FLIP_MODE);
    void setRotationAngle(double rotationAngle);

    void restartRendering();
    void stopRendering();
    void queryTexture();
    void setImageSourceRectToFull();
    SDL_Point calcRelativeCenterPoint(); //taking showing rect to calculate
    SDL_Point calcUnrelatedCenterPoint(); //taking showing rect to calculate
    void rotateImage(const SDL_Point& rotationPoint, double rotationAngle, SDL_RendererFlip SDL_FLIP_MODE);

protected:

    SDL_Texture* currentTexture_;
    SDL_Rect rectShow_;
    SDL_Rect rectCollision_;
    SDL_Rect* rectImageSrc_;
    SDL_Point rotationPoint_;
    std::string name_;
    int id_;
    int layer_;
    bool render_;
    SDL_RendererFlip flipMode_;
    double rotationAngle_;
};
