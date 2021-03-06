
#pragma once

#include "GameBase.h"

#define IDENTIFY_END_FLAG_CONTROLLER 'x'

class EndFlagController : public GameBase
{
public:

    EndFlagController(MarioGame& game, int flagXPosition=0);

    bool isActive() const override {return true;}
    void action() override;
    char identify() const override {return IDENTIFY_END_FLAG_CONTROLLER;}

    void setFlagXPosition(int flagXPosition);

    std::string loadObject(std::string objectLine) override;
    void saveObject(std::ofstream& file);

private:

    bool flagUseConditionsFulfilled();

    bool flagUsed_;
    int flagXPosition_;
};
