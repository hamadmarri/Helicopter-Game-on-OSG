//	See main.cpp file header for credits

#ifndef __HelicopterProject__ActivateFrictionCommand_h__
#define __HelicopterProject__ActivateFrictionCommand_h__

#include "Command.h"
#include "Game.h"

//class Game;

class ActivateFrictionCommand : public Command {
public:
	ActivateFrictionCommand(Game *game);
	bool execute();
	
private:
	Game *game;
};


#endif
