#pragma once

#include "AnimationSet.h"
#include "../../Model/ManyPicAnimation.h"

class Mario;

class MarioAnimation : public AnimationSet
{
public:

    MarioAnimation(Mario& owner);

    SDL_Texture* animateWalk() override;
    SDL_Texture* animateStand() override;
    SDL_Texture* animateDie() override;
    SDL_Texture* animateJump() override;
    SDL_Texture* animateGrow();
    SDL_Texture* animateShrink();
    SDL_Texture* animateTransformFire();
    SDL_Texture* animateSquat();
    SDL_Texture* animateClimb();
    void setTextures() override;
    SDL_Texture* animate(ManyPicAnimation& animation);
    void freezeAnimation(ManyPicAnimation& animation);

private:

    ManyPicAnimation walkSmall_;
    ManyPicAnimation climbSmall_;

    SDL_Texture* standSmall_;
    SDL_Texture* die_;
    SDL_Texture* jumpSmall_;

    ManyPicAnimation walkBig_;
    ManyPicAnimation climbBig_;

    SDL_Texture* standBig_;
    SDL_Texture* jumpBig_;
    SDL_Texture* squatBig_;

    ManyPicAnimation walkFire_;
    ManyPicAnimation climbFire_;

    SDL_Texture* standFire_;
    SDL_Texture* jumpFire_;
    SDL_Texture* squatFire_;

    ManyPicAnimation walkSmallInvincibility_;
    ManyPicAnimation jumpSmallInvincibility_;
    ManyPicAnimation standSmallInvincibility_;

    ManyPicAnimation walkBigFireInvincibility_;
    ManyPicAnimation jumpBigFireInvincibility_;
    ManyPicAnimation standBigFireInvincibility_;

    ManyPicAnimation grow_;
    ManyPicAnimation fireTransform_;
    ManyPicAnimation shrink_;
};
