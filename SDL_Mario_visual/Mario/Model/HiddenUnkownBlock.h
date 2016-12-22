
#pragma once

#include "UnknownBlock.h"

#define IDENTIFY_HIDDEN_UNKNOWN_BLOCK 'o'

class HiddenUnknownBlock : public UnknownBlock
{
public:

    HiddenUnknownBlock(MarioGame& game, AbstractMob* content = nullptr);

    void action() override;
    char identify() const override {return IDENTIFY_HIDDEN_UNKNOWN_BLOCK;}
    bool askForActivate();
    void activate();

private:

    void doOnce();
    void saveRects();

    SDL_Rect activateRect_;
    bool once_;
};
