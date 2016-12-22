
#include <cmath>

#include "MarioAnimation.h"
#include "MarioGame.h"
#include "../../ApplicationError.h"

MarioAnimation::MarioAnimation(Mario& owner):AnimationSet(owner)
{
	die_ = nullptr;

	standSmall_ = nullptr;
	standBig_ = nullptr;
	standFire_ = nullptr;

	jumpBig_ = nullptr;
	jumpFire_ = nullptr;
	jumpSmall_ = nullptr;

	squatBig_ = nullptr;
	squatFire_ = nullptr;
}

void MarioAnimation::setTextures()
{
	MarioGame& game = owner_.getWorld();
	standSmall_ = game.getTexture(TEXTURE_MARIO_SMALL_MARIOSTAND);
	die_ = game.getTexture(TEXTURE_MARIO_SMALL_MARIODIE);
	jumpSmall_ = game.getTexture(TEXTURE_MARIO_SMALL_JUMP);

	climbSmall_.addTexture(game.getTexture(TEXTURE_MARIO_SMALL_CLIMB_1));
	climbSmall_.addTexture(game.getTexture(TEXTURE_MARIO_SMALL_CLIMB_2));

	climbSmall_.animateInit(15.0f);

	walkSmall_.addTexture(game.getTexture(TEXTURE_MARIO_SMALL_MARIOMOVE_1));
	walkSmall_.addTexture(game.getTexture(TEXTURE_MARIO_SMALL_MARIOMOVE_2));
	walkSmall_.addTexture(game.getTexture(TEXTURE_MARIO_SMALL_MARIOMOVE_3));

	walkSmall_.animateInit(15.0f);

	standBig_ = game.getTexture(TEXTURE_MARIO_BIG_STAND);
	jumpBig_ = game.getTexture(TEXTURE_MARIO_BIG_JUMP);
	squatBig_ = game.getTexture(TEXTURE_MARIO_BIG_SQUAT);

	climbBig_.addTexture(game.getTexture(TEXTURE_MARIO_BIG_CLIMB_1));
	climbBig_.addTexture(game.getTexture(TEXTURE_MARIO_BIG_CLIMB_2));

	climbBig_.animateInit(15.0f);

	walkBig_.addTexture(game.getTexture(TEXTURE_MARIO_BIG_MARIOMOVE_1));
	walkBig_.addTexture(game.getTexture(TEXTURE_MARIO_BIG_MARIOMOVE_2));
	walkBig_.addTexture(game.getTexture(TEXTURE_MARIO_BIG_MARIOMOVE_3));

	walkBig_.animateInit(15.0f);

	grow_.addTexture(standSmall_);
	grow_.addTexture(game.getTexture(TEXTURE_MARIO_GROW));
	grow_.addTexture(standBig_);

	grow_.animateInit(15.0f);

	standFire_ = game.getTexture(TEXTURE_MARIO_FIRE_STAND);
	jumpFire_ = game.getTexture(TEXTURE_MARIO_FIRE_JUMP);
	squatFire_ = game.getTexture(TEXTURE_MARIO_FIRE_SQUAT);

	climbFire_.addTexture(game.getTexture(TEXTURE_MARIO_FIRE_CLIMB_1));
	climbFire_.addTexture(game.getTexture(TEXTURE_MARIO_FIRE_CLIMB_2));

	climbFire_.animateInit(15.0f);

	walkFire_.addTexture(game.getTexture(TEXTURE_MARIO_FIRE_MOVE_1));
	walkFire_.addTexture(game.getTexture(TEXTURE_MARIO_FIRE_MOVE_2));
	walkFire_.addTexture(game.getTexture(TEXTURE_MARIO_FIRE_MOVE_3));

	walkFire_.animateInit(15.0f);

	fireTransform_.addTexture(game.getTexture(TEXTURE_MARIO_BIG_STAND));
	fireTransform_.addTexture(game.getTexture(TEXTURE_MARIO_INVINCIBILITY_STAND));
	fireTransform_.addTexture(game.getTexture(TEXTURE_MARIO_FIRE_STAND));

	fireTransform_.animateInit(15.0f);

	shrink_.addTexture(standBig_);
	shrink_.addTexture(game.getTexture(TEXTURE_MARIO_GROW));
	shrink_.addTexture(standSmall_);

	shrink_.animateInit(15.0f);

	standBigFireInvincibility_.addTexture(game.getTexture(TEXTURE_MARIO_INVINCIBILITY_STAND));
	standBigFireInvincibility_.addTexture(game.getTexture(TEXTURE_MARIO_BIG_STAND));
	standBigFireInvincibility_.addTexture(game.getTexture(TEXTURE_MARIO_INVINCIBILITY_STAND));
	standBigFireInvincibility_.addTexture(game.getTexture(TEXTURE_MARIO_FIRE_STAND));

	standBigFireInvincibility_.animateInit(15.0f);

	jumpBigFireInvincibility_.addTexture(game.getTexture(TEXTURE_MARIO_INVINCIBILITY_JUMP));
	jumpBigFireInvincibility_.addTexture(game.getTexture(TEXTURE_MARIO_BIG_JUMP));
	jumpBigFireInvincibility_.addTexture(game.getTexture(TEXTURE_MARIO_INVINCIBILITY_JUMP));
	jumpBigFireInvincibility_.addTexture(game.getTexture(TEXTURE_MARIO_FIRE_JUMP));

	jumpBigFireInvincibility_.animateInit(15.0f);

	walkBigFireInvincibility_.addTexture(game.getTexture(TEXTURE_MARIO_INVINCIBILITY_MOVE_1));
	walkBigFireInvincibility_.addTexture(game.getTexture(TEXTURE_MARIO_BIG_MARIOMOVE_2));
	walkBigFireInvincibility_.addTexture(game.getTexture(TEXTURE_MARIO_FIRE_MOVE_3));

	walkBigFireInvincibility_.animateInit(20.0f);

	walkSmallInvincibility_.addTexture(game.getTexture(TEXTURE_MARIO_SMALL_INVINCIBILITY_MOVE_1));
	walkSmallInvincibility_.addTexture(game.getTexture(TEXTURE_MARIO_SMALL_MARIOMOVE_2));
	walkSmallInvincibility_.addTexture(game.getTexture(TEXTURE_MARIO_SMALL_INVINCIBILITY_MOVE_6));

	walkSmallInvincibility_.animateInit(20.0f);

	standSmallInvincibility_.addTexture(game.getTexture(TEXTURE_MARIO_SMALL_INVINCIBILITY_STAND_1));
	standSmallInvincibility_.addTexture(game.getTexture(TEXTURE_MARIO_SMALL_MARIOSTAND));
	standSmallInvincibility_.addTexture(game.getTexture(TEXTURE_MARIO_SMALL_INVINCIBILITY_STAND_1));
	standSmallInvincibility_.addTexture(game.getTexture(TEXTURE_MARIO_SMALL_INVINCIBILITY_STAND_2));

	standSmallInvincibility_.animateInit(15.0f);

	jumpSmallInvincibility_.addTexture(game.getTexture(TEXTURE_MARIO_SMALL_INVINCIBILITY_JUMP_1));
	jumpSmallInvincibility_.addTexture(game.getTexture(TEXTURE_MARIO_SMALL_JUMP));
	jumpSmallInvincibility_.addTexture(game.getTexture(TEXTURE_MARIO_SMALL_INVINCIBILITY_JUMP_1));
	jumpSmallInvincibility_.addTexture(game.getTexture(TEXTURE_MARIO_SMALL_INVINCIBILITY_JUMP_2));

	jumpSmallInvincibility_.animateInit(15.0f);
}

SDL_Texture* MarioAnimation::animateStand()
{
	int marioType = ((Mario&)owner_).getMarioType();

	if(((Mario&)owner_).isInvincible())
	{
		if(marioType == MARIO_SMALL)
			return animate(standSmallInvincibility_);
		else
			return animate(standBigFireInvincibility_);
	}

	switch(marioType)
	{
		case MARIO_SMALL : return standSmall_;
		case MARIO_BIG : return standBig_;
		case MARIO_FIRE : return standFire_;
		default:
			printf("Nie ma animateStand() w MarioAnimation\n");
			throw *(new ApplicationError);
	}
}

SDL_Texture* MarioAnimation::animateDie()
{
	return die_;
}

void MarioAnimation::freezeAnimation(ManyPicAnimation& animation)
{
	animation.animateInit(0.00001f);
}

SDL_Texture* MarioAnimation::animateWalk()
{
	int marioType = ((Mario*)&owner_)->getMarioType();

	if(((Mario&)owner_).isInvincible())
	{
		if(marioType == MARIO_SMALL)
			return animate(walkSmallInvincibility_);
		else
			return animate(walkBigFireInvincibility_);
	}

	switch(marioType)
	{
		case MARIO_SMALL : return animate(walkSmall_);
		case MARIO_BIG : return animate(walkBig_);
		case MARIO_FIRE : return animate(walkFire_);
		default:
			printf("This error doesn't make sense, catch an exception :)\n");
			throw *(new ApplicationError);
	}
}

SDL_Texture* MarioAnimation::animateJump()
{
	int marioType = ((Mario&)owner_).getMarioType();

	if(((Mario&)owner_).isInvincible())
	{
		if(marioType == MARIO_SMALL)
			return animate(jumpSmallInvincibility_);
		else
			return animate(jumpBigFireInvincibility_);
	}

	switch(marioType)
	{
		case MARIO_SMALL : return jumpSmall_;
		case MARIO_BIG : return jumpBig_;
		case MARIO_FIRE : return jumpFire_;
		default:
			printf("Ni ma animateJump() w MarioAnimation\n");
			throw *(new ApplicationError);
	}
}

SDL_Texture* MarioAnimation::animateGrow()
{
	return animate(grow_);
}

SDL_Texture* MarioAnimation::animateShrink()
{
	return animate(shrink_);
}

SDL_Texture* MarioAnimation::animate(ManyPicAnimation& animation)
{
	animation.animate();
	return animation.getTexture();
}

SDL_Texture* MarioAnimation::animateTransformFire()
{
	return animate(fireTransform_);
}

SDL_Texture* MarioAnimation::animateSquat()
{
	int marioType = ((Mario&)owner_).getMarioType();

	switch(marioType)
	{
		case MARIO_BIG:     return squatBig_;
		case MARIO_FIRE:    return squatFire_;
		default:
			printf("animateSquat()\n");
			throw *(new ApplicationError);
	}
}

SDL_Texture* MarioAnimation::animateClimb()
{
	int marioType = ((Mario&)owner_).getMarioType();

	switch(marioType)
	{
		case MARIO_SMALL:   return animate(climbSmall_);
		case MARIO_BIG:     return animate(climbBig_);
		case MARIO_FIRE:    return animate(climbFire_);
		default:
			printf("animateClimb()\n");
			throw *(new ApplicationError);
	}
}
