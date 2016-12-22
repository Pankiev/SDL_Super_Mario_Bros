
#include <cmath>

#include "MobileObject.h"
#include "CollisionMap.h"
#include "../ApplicationError.h"

MobileObject::MobileObject(const char* name, int id, int layer):Object(name, id, layer)
{
	moveSpeed_ = DEFAULT_MOVE_SPEED;
	horizontalMove_ = 0;
	verticalMove_ = 0;
	calcOnce_ = true;
}

void MobileObject::setMoveSpeed(float moveSpeed)
{
	moveSpeed_ = moveSpeed;
}

float MobileObject::getMoveSpeed() const
{
	return moveSpeed_;
}

void MobileObject::move(int direction, float timeFactor)
{
	int moveValue;
	if(calcOnce_)
		moveValue = calcMoveValue(moveSpeed_*timeFactor, direction);
	else
		moveValue = extractFloat();

	applyMoveToRects(direction, moveValue);

	horizontalMove_ -= (int)horizontalMove_;
	verticalMove_ -= (int)verticalMove_;
	calcOnce_ = true;
}

Object* MobileObject::move(CollisionMap& map, int direction, float timeFactor)
{
	int moveValue = calcMoveValue(moveSpeed_*timeFactor, direction);
	calcOnce_ = false;
	Object* ret = map.checkForSpace(moveValue, direction, rectCollision_);
	if(ret == nullptr)
	{
		map.repositionCollision(moveValue, direction, *this);
		move(direction, timeFactor);
	}
	else
	{
		horizontalMove_ -= (int)horizontalMove_;
		verticalMove_ -= (int)verticalMove_;
	}
	return ret;
}

Object* MobileObject::moveAnyway(CollisionMap& map, int direction, float timeFactor)
{
	int moveValue = calcMoveValue(moveSpeed_*timeFactor, direction);
	calcOnce_ = false;
	Object* ret = map.checkForSpace(moveValue, direction, rectCollision_);
	//if(ret == nullptr || ret->getId() != BORDER_ID)
	//{
		map.repositionCollision(moveValue, direction, *this);
		move(direction, timeFactor);
	//}
	//else
	//{
	//    horizontalMove_ -= (int)horizontalMove_;
  //      verticalMove_ -= (int)verticalMove_;
  //  }
	return ret;
}

Object* MobileObject::moveAnyway(CollisionMap& map, int direction, int pixels)
{
	int moveValue = pixels;
	Object* ret = map.checkForSpace(moveValue, direction, rectCollision_);
	//if(ret == nullptr || ret->getId() != BORDER_ID)
	//{
		map.repositionCollision(moveValue, direction, *this);
		applyMoveToRects(direction, pixels);
	//}
	//else
	//{
	//    horizontalMove_ -= (int)horizontalMove_;
  //      verticalMove_ -= (int)verticalMove_;
  //  }
	return ret;
}

int MobileObject::calcMoveValue(float floatMoveValue, int direction)
{
	switch(direction)
	{
	case UP:
		verticalMove_ -= floatMoveValue;
		break;
	case DOWN:
		verticalMove_ += floatMoveValue;
		break;
	case LEFT:
		horizontalMove_ -= floatMoveValue;
		break;
	case RIGHT:
		//horizontalMove_ -= floatMoveValue;
		horizontalMove_ += floatMoveValue;
		break;
	case DIRECTION_NONE:
		break;
	default:
		printf("CalcMoveVale method:-> bad direction choosen! \n");
		throw *(new ApplicationError);
	}

	return extractFloat();
}

int MobileObject::extractFloat()
{
	int decimalVertical = verticalMove_;
	if(decimalVertical != 0)
		return abs(decimalVertical);

	int decimalHorizontal = horizontalMove_;
	if(decimalHorizontal != 0)
		return abs(decimalHorizontal);

	return 0;
}

Object* MobileObject::repositionObjectCollision(CollisionMap& map, int x, int y)
{
	return map.repositionObjectColl(this, x, y);
}

void MobileObject::goToPoint(CollisionMap& map, int x, int y, float timeFactor)
{
	if(rectCollision_.x < x)
		move(map, RIGHT, timeFactor);
	else if(rectCollision_.x > x)
		move(map, LEFT, timeFactor);
	if(rectCollision_.y < y)
		move(map, DOWN, timeFactor);
	else if(rectCollision_.y > y)
		move(map, UP, timeFactor);
}

void MobileObject::applyMoveToRects(int direction, int moveValue)
{
	switch(direction)
	{
	case UP:
		rectShow_.y -= moveValue;
		rectCollision_.y -= moveValue;
		break;
	case DOWN:
		rectShow_.y += moveValue;
		rectCollision_.y += moveValue;
		break;
	case LEFT:
		rectShow_.x -= moveValue;
		rectCollision_.x -= moveValue;
		break;
	case RIGHT:
		rectShow_.x += moveValue;
		rectCollision_.x += moveValue;
		break;
	default:
		printf("Move method:-> bad direction choosen! \n");
		throw *(new ApplicationError);
	}
}

Object* MobileObject::move(CollisionMap& map, int direction, int pixels)
{
	Object* coll = map.checkForSpace(pixels, direction, getCollisionRect());
	if(coll == nullptr)
	{
		map.repositionCollision(pixels, direction, *this);
		applyMoveToRects(direction, pixels);
	}

	return coll;
}
