#include "StringUtilities.h"

int size(const char* str)
{
	if (str == nullptr)
		return 0;

	int size = 0;
	for (; str[size] != '\0'; size++)
		;
	return size;
}

char* erase(char* str, int from, int to)
{
	int strSize = size(str);
	int eraseSize = to - from;
	if(eraseSize <= 0)
		return str;
	for (int i = from; i<strSize - eraseSize; i++) 
		str[i] = str[i + eraseSize];
	
	str[strSize - eraseSize] = '\0';
	return str;
}

char* readLine(char* destination, FILE* from)
{
	char c = fgetc(from);
	int i = 0;
	while(c != '\0' && c != '\n' && c != EOF)
	{
		destination[i] = c;
		i++;
		c = fgetc(from);
	}

	destination[i] = NULL;
	return destination;
}
