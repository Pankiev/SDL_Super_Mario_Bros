
#pragma once

#include "GameBase.h"
#include "../Controller/MarioGame.h"

class String : public GameBase
{
public:

    String(MarioGame& game, std::string text);

    void action() override;
    bool isActive() const override {return true;}


protected:

    void loadString(std::string text);
    String(MarioGame& game);

    Timer existTimer_;
};
