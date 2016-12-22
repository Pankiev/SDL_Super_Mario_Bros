
#pragma once

#include "GameBase.h"
#include "../Controller/MarioGame.h"

class String : public GameBase
{
public:

    String(MarioGame& game, const char* text);

    void action() override;
    bool isActive() const override {return true;}


protected:

    void loadString(const char* text);
    String(MarioGame& game);

    Timer existTimer_;
};
