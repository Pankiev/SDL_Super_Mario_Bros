
#include <cmath>

#include "CollisionMap.h"

CollisionMap::CollisionMap(int width, int height):borderObject("BorderObject", BORDER_ID, -1)
{
    width_ = width;
    height_ = height;
    map_ = new Object**[height_];
    for(int i=0; i<height_; i++)
    {
        map_[i] = new Object*[width_]{nullptr};
    }
    makeBorder();
}

CollisionMap::~CollisionMap()
{
    for(int i=0; i<height_; i++)
    {
        delete[] map_[i];
    }
    delete[] map_;
}

void CollisionMap::makeBorder()
{
    for(int i=0; i<width_; i++)
    {
        map_[0][i] = &borderObject;
    }

    for(int i=0; i<width_; i++)
    {
        map_[height_-1][i] = &borderObject;
    }

    for(int i=0; i<height_; i++)
    {
        map_[i][0] = &borderObject;
    }

    for(int i=0; i<height_; i++)
    {
        map_[i][width_-1] = &borderObject;
    }
}

void CollisionMap::update(Object* object)
{
    SDL_Rect objRect = object->getCollisionRect();

    for(int i=objRect.y; i<objRect.y+objRect.h; i++)
    {
        for(int j=objRect.x; j<objRect.x+objRect.w; j++)
        {
            map_[i][j] = object;
        }
    }
}

Object* CollisionMap::checkForSpace(int moveValue, int direction, const SDL_Rect& rect) const
{
    int top, bottom, left, right;
    getRectBorders(rect, top, bottom, left, right);
    if(inBorder(direction, moveValue, rect))
    {
        /*switch(direction)
        {
        case UP:
            for(int i=top-1; i>=top-moveValue; i--)
            {
                if(map_[i][left] != nullptr)
                    return map_[i][left];
                if(map_[i][left+(right-left)/2] != nullptr)
                    return map_[i][left+(right-left)/2];
                if(map_[i][right] != nullptr)
                    return map_[i][right];
            }
            break;
        case DOWN:
            for(int i=bottom+1; i<=bottom+moveValue; i++)
            {
                if(map_[i][left] != nullptr)
                    return map_[i][left];
                if(map_[i][left+(right-left)/2] != nullptr)
                    return map_[i][left+(right-left)/2];
                if(map_[i][right] != nullptr)
                    return map_[i][right];
            }
            break;
        case LEFT:
            for(int i=left-1; i>=left-moveValue; i--)
            {
                if(map_[top][i] != nullptr)
                    return map_[top][i];
                if(map_[top+(bottom-top)/2][i] != nullptr)
                    return map_[top+(bottom-top)/2][i];
                if(map_[bottom][i] != nullptr)
                    return map_[bottom][i];
            }
            break;
        case RIGHT:
            for(int i=right+1; i<=right+moveValue; i++)
            {
                if(map_[top][i] != nullptr)
                    return map_[top][i];
                if(map_[top+(bottom-top)/2][i] != nullptr)
                    return map_[top+(bottom-top)/2][i];
                if(map_[bottom][i] != nullptr)
                    return map_[bottom][i];
            }
            break;
        default:
            std::cout << "Bad direction choosen(checkForSpace method)!" << std::endl;
            throw *(new std::exception);
        }*/
        switch(direction)
        {
        case UP:

            for(int i=top-1; i>=top-moveValue; i--)
                for(int j=left; j<=right; j++)
                    if(map_[i][j] != nullptr)
                        return map_[i][j];
            break;
        case DOWN:
            for(int i=bottom+1; i<=bottom+moveValue; i++)
                for(int j=left; j<=right; j++)
                    if(map_[i][j] != nullptr)
                        return map_[i][j];
            break;
        case LEFT:
            for(int i=left-1; i>=left-moveValue; i--)
                for(int j=top; j<=bottom; j++)
                    if(map_[j][i] != nullptr)
                        return map_[j][i];
            break;
        case RIGHT:
            for(int i=right+1; i<=right+moveValue; i++)
                for(int j=top; j<=bottom; j++)
                    if(map_[j][i] != nullptr)
                        return map_[j][i];
            break;
        case DIRECTION_NONE:
            return map_[top][left];
        default:
            std::cout << "Bad direction choosen(checkForSpace method)!" << std::endl;
            throw *(new std::exception);
        }
        return nullptr;
    }
    else
        return (Object*)&borderObject;
}

void CollisionMap::repositionCollision(int moveValue, int direction, const Object& object)
{
    const SDL_Rect rect = object.getCollisionRect();
    int top, bottom, left, right;
    getRectBorders(rect, top, bottom, left, right);

    switch(direction)
    {
    case UP:
        for(int i=top-moveValue; i<top; i++)
            for(int j=left; j<=right; j++)
                map_[i][j] = (Object*)&object;

        for(int i=bottom-moveValue+1; i<=bottom; i++)
            for(int j=left; j<=right; j++)
                map_[i][j] = nullptr;
        break;
    case DOWN:
        for(int i=bottom+1; i<=bottom+moveValue; i++)
            for(int j=left; j<=right; j++)
                map_[i][j] = (Object*)&object;

        for(int i=top; i<top+moveValue; i++)
            for(int j=left; j<=right; j++)
                map_[i][j] = nullptr;
        break;
    case LEFT:
        for(int i=top; i<=bottom; i++)
            for(int j=left-moveValue; j<left; j++)
                map_[i][j] = (Object*)&object;

        for(int i=top; i<=bottom; i++)
            for(int j=right-moveValue+1; j<=right; j++)
                map_[i][j] = nullptr;
        break;
    case RIGHT:
        for(int i=top; i<=bottom; i++)
            for(int j=right+1; j<=right+moveValue; j++)
                map_[i][j] = (Object*)&object;

        for(int i=top; i<=bottom; i++)
            for(int j=left; j<left+moveValue; j++)
                map_[i][j] = nullptr;
        break;
    case DIRECTION_NONE:
        break;
    default:
        std::cout << "Bad direction choosen(repositionCollision method)!" << std::endl;
        throw *(new std::exception);
    }
}

bool CollisionMap::inBorder(int direction, int moveValue, const SDL_Rect& rect) const
{
    switch(direction)
    {
    case UP:
        return inBorder(rect.x, rect.y-moveValue);
    case DOWN:
        return inBorder(rect.x, rect.y+rect.h+moveValue-1);
    case LEFT:
        return inBorder(rect.x-moveValue, rect.y);
    case RIGHT:
        return inBorder(rect.x+rect.w+moveValue-1, rect.y);
    case DIRECTION_NONE:
        return inBorder(rect.x, rect.y);
    default:
        std::cout << "Bad direction choosen(inBorder method)!" << std::endl;
        throw *(new std::exception);
    }
}

bool CollisionMap::inBorder(int x, int y) const
{
    return (x>0 && y>0 && x<width_-1 && y<height_-1);
}

Object* CollisionMap::repositionObjectColl(Object* object, int x, int y)
{
    const SDL_Rect rect = object->getCollisionRect();

    clearColl(rect);

    object->setCollisionRect({x,y,rect.w, rect.h});
    Object* ret = &borderObject;
    if(inBorder(object->getCollisionRect()))
    {
        ret = getObjectInRect(object->getCollisionRect());
        update(object);
    }


    return ret;
}

bool CollisionMap::inBorder(const SDL_Rect& rect) const
{
    int top, bottom, left, right;
    getRectBorders(rect, top, bottom, left, right);
    return (inBorder(left,top) && inBorder(right,top) && inBorder(left,bottom) && inBorder(right,bottom));
}

Object* CollisionMap::getObjectInRect(const SDL_Rect& rect) const
{
    int top, bottom, left, right;
    getRectBorders(rect, top, bottom, left, right);

    for(int i=top; i<=bottom; i++)
        for(int j=left; j<=right; j++)
            if(map_[i][j] != nullptr)
                return map_[i][j];

    return nullptr;
}

void CollisionMap::getRectBorders(const SDL_Rect& rect, int& top, int& bottom, int& left, int& right) const
{
    left = rect.x;
    right = rect.x+rect.w-1;
    top = rect.y;
    bottom = rect.y+rect.h-1;
}


void CollisionMap::clearColl(const SDL_Rect& rect)
{
    int top, bottom, left, right;
    getRectBorders(rect, top, bottom, left, right);

    for(int i=top; i<=bottom; i++)
        for(int j=left; j<=right; j++)
        {
            if(inBorder(j,i))
                map_[i][j] = nullptr;
        }
}

Object* CollisionMap::getObjectInPosition(int x, int y) const
{
    return map_[y][x];
}

void CollisionMap::clear()
{
    for(int i=0; i<height_; i++)
        for(int j=0; j<width_; j++)
            map_[i][j] = nullptr;

    makeBorder();
}

bool CollisionMap::isPointInRect(const SDL_Point& point, const SDL_Rect& rect)
{
    return (point.y >= rect.y && point.y <= rect.y+rect.h-1 &&
            point.x >= rect.x && point.x <= rect.x+rect.w-1);
}

int CollisionMap::getWidth() const
{
    return width_;
}

int CollisionMap::getHeight() const
{
    return height_;
}

float CollisionMap::calcDistanceBetweenPoints(const SDL_Point& firstPoint, const SDL_Point& secondPoint)
{
    float distance = sqrt(pow(secondPoint.x - firstPoint.x, 2) + pow(secondPoint.y - firstPoint.y, 2));
    return distance;
}

bool CollisionMap::isRectsTouching(const SDL_Rect& first, const SDL_Rect& second)
{
    return  !(first.x + first.w < second.x || first.x > second.x + second.w ||
             first.y + first.h < second.y || first.y > second.y + second.h);
}


