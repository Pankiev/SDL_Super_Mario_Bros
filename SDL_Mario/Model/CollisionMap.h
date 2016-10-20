#pragma once

#include "Object.h"

#define BORDER_ID -1

class CollisionMap
{
public:

    CollisionMap(int width, int height);
    ~CollisionMap();

    void update(Object* object);
    Object* checkForSpace(int moveValue, int direction, const SDL_Rect& rect) const;
    Object* repositionObjectColl(Object* object, int x, int y);
    void repositionCollision(int moveValue, int direction, const Object& rect);
    Object* getObjectInRect(const SDL_Rect& rect) const;
    Object* getObjectInPosition(int x, int y) const;
    void clearColl(const SDL_Rect& rect);
    void getRectBorders(const SDL_Rect& rect, int& top, int& bottom, int& left, int& right) const;
    void clear();

    int getWidth() const;
    int getHeight() const;

    static bool isPointInRect(const SDL_Point& point, const SDL_Rect& rect);
    static float calcDistanceBetweenPoints(const SDL_Point& firstPoint, const SDL_Point& secondPoint);
    static bool isRectsTouching(const SDL_Rect& first, const SDL_Rect& second);

private:

    void makeBorder();
    bool inBorder(int direction, int moveValue, const SDL_Rect& rect) const;
    bool inBorder(int x, int y) const;
    bool inBorder(const SDL_Rect& rect) const;

    Object*** map_;
    Object borderObject;
    int width_;
    int height_;
};
