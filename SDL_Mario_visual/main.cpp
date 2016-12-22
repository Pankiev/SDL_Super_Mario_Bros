//REMEMBER, YOU HAVE TO USE TIME CALCULATION FROM
//MAIN CONTROLLER IN MAIN LOOP TO WORK PROPERELY

#include "Mario/Controller/MarioGame.h"
#include "StringUtilities.h"

int main(int argc, char* argv[])
{
	//char xxx[12] = "1234567890";
	//erase(xxx, 3, 5);
	//printf("%s", xxx);
	MarioGame game;
	game.run();
	return 0;
}
