
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

    const char* loadObject(const char* objectLine) override;
    void saveObject(FILE* file);

private:

    bool flagUseConditionsFulfilled();

    bool flagUsed_;
    int flagXPosition_;
};
