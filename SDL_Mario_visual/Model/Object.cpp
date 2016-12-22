
#include "Object.h"

Object::Object(const char* name, int id, int layer)
{
    rectCollision_ = {0,0,0,0};
    rectShow_ = {0,0,100,100};
    rotationPoint_ = {0,0};
    name_ = name;
    id_ = id;
    layer_ = layer;
    render_ = true;
    rectImageSrc_ = nullptr;
    currentTexture_ = nullptr;
    flipMode_ = SDL_FLIP_NONE;
    rotationAngle_ = 0.0f;
}

Object::~Object()
{
    if(rectImageSrc_ != nullptr)
    {
        delete rectImageSrc_;
        rectImageSrc_ = nullptr;
    }
}

SDL_Rect Object::getCollisionRect() const
{
    return rectCollision_;
}

SDL_Rect Object::getShowingRect() const
{
    return rectShow_;
}

void Object::setCollisionRect(const SDL_Rect& newRect)
{
    rectCollision_ = newRect;
}

void Object::setShowingRect(const SDL_Rect& newRect)
{
    rectShow_ = newRect;
}

void Object::setShowingRect(int x, int y, int width, int height)
{
    rectShow_.x = x;
    rectShow_.y = y;
    rectShow_.w = width;
    rectShow_.h = height;
}

void Object::setCollisionRect(int x, int y, int width, int height)
{
    rectCollision_.x = x;
    rectCollision_.y = y;
    rectCollision_.w = width;
    rectCollision_.h = height;
}

const char* Object::getName() const
{
    return name_;
}

void Object::setName(const char* name)
{
    name_ = name;
}

void Object::setId(int id)
{
    id_ = id;
}

int Object::getId() const
{
    return id_;
}

int Object::getLayer() const
{
    return layer_;
}

void Object::setLayer(int layer)
{
    layer_ = layer;
}

bool Object::isRendering() const
{
    return render_;
}

void Object::stopRendering()
{
    render_ = false;
}

void Object::restartRendering()
{
    render_ = true;
}

void Object::setTexture(SDL_Texture* texture)
{
    currentTexture_ = texture;
}

SDL_Texture* Object::getTexture() const
{
    return currentTexture_;
}

void Object::setBothRects(const SDL_Rect& rect)
{
    setShowingRect(rect);
    setCollisionRect(rect);
}

void Object::queryTexture()
{
    SDL_QueryTexture(currentTexture_, NULL, NULL, &rectShow_.w, &rectShow_.h);
    SDL_QueryTexture(currentTexture_, NULL, NULL, &rectCollision_.w, &rectCollision_.h);
}

void Object::setImageSourceRect(const SDL_Rect& rect)
{
    if(rectImageSrc_ == nullptr)
        rectImageSrc_ = new SDL_Rect;
    *rectImageSrc_ = rect;
}

SDL_Rect* Object::getImageSourceRect() const
{
    return rectImageSrc_;
}

void Object::setImageSourceRectToFull()
{
    if(rectImageSrc_ != nullptr)
    {
        delete rectImageSrc_;
        rectImageSrc_ = nullptr;
    }
}

void Object::setShowingPosition(int x, int y)
{
    rectShow_.x = x;
    rectShow_.y = y;
}

void Object::setCollisionPosition(int x, int y)
{
    rectCollision_.x = x;
    rectCollision_.y = y;
}

void Object::setBothPosition(int x, int y)
{
    setShowingPosition(x, y);
    setCollisionPosition(x, y);
}

SDL_Point Object::calcRelativeCenterPoint()
{
    return {(rectShow_.w-1)/2, (rectShow_.h-1)/2};
}

SDL_Point Object::calcUnrelatedCenterPoint()
{
    SDL_Point relativePoint = calcRelativeCenterPoint();
    return {rectShow_.x + relativePoint.x, rectShow_.y + relativePoint.y};
}

void Object::setRotationPoint(const SDL_Point& rotationPoint)
{
    rotationPoint_ = rotationPoint;
}

SDL_Point* Object::getRotationPoint()
{
    return &rotationPoint_;
}

void Object::setFlipMode(SDL_RendererFlip SDL_FLIP_MODE)
{
    flipMode_ = SDL_FLIP_MODE;
}

SDL_RendererFlip Object::getFlipMode() const
{
    return flipMode_;
}

void Object::setRotationAngle(double rotationAngle)
{
    rotationAngle_ = rotationAngle;
}

double Object::getRotationAngle() const
{
    return rotationAngle_;
}

void Object::rotateImage(const SDL_Point& rotationPoint, double rotationAngle, SDL_RendererFlip SDL_FLIP_MODE)
{
    setRotationPoint(rotationPoint);
    setRotationAngle(rotationAngle);
    setFlipMode(SDL_FLIP_MODE);
}

void Object::setShowingX(int x)
{
    rectShow_.x = x;
}

void Object::setShowingY(int y)
{
    rectShow_.y = y;
}

void Object::setCollisionX(int x)
{
    rectCollision_.x = x;
}

void Object::setCollisionY(int y)
{
    rectCollision_.y = y;
}

void Object::setCollisionWidth(int width)
{
    rectCollision_.w = width;
}

void Object::setCollisionHeight(int height)
{
    rectCollision_.h = height;
}

void Object::setShowingHeight(int height)
{
    rectShow_.h = height;
}

void Object::setShowingWidth(int width)
{
    rectShow_.w = width;
}
