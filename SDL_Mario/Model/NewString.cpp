
#include <sstream>

#include "NewString.h"

NewString::NewString()
{
    value_ = -1;
}

void NewString::updateInNeed(int value, StringFactory& factory)
{
    if(value_ != value)
    {
        value_ = value;
        std::ostringstream ss;
        ss << value;
        setTexture(factory.createText(ss.str(), FONT_BATMFA, 25));
    }
}

int NewString::getCurrentValue()
{
    return value_;
}
