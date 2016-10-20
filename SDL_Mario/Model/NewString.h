
#pragma once
#include "../View/SdlString.h"

class NewString : public SdlString
{
public:

    NewString();
    void updateInNeed(int value, StringFactory& factory);
    int getCurrentValue();

private:
    int value_;
};
