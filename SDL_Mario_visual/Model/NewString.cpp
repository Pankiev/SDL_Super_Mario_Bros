

#include "NewString.h"

NewString::NewString()
{
	value_ = -1;
}

void NewString::updateInNeed(int value, StringFactory& factory)
{
	if(value_ != value)
	{
		char valueString[20];
		value_ = value;
		_itoa_s(value, valueString, 10);
		setTexture(factory.createText(valueString, FONT_BATMFA, 25));
	}
}

int NewString::getCurrentValue()
{
	return value_;
}
