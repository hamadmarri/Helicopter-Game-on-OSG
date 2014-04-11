//	See main.cpp file header for credits


#ifndef __HelicopterProject__ShowHelpScreenCommand_h__
#define __HelicopterProject__ShowHelpScreenCommand_h__

#include "Command.h"
#include "Game.h"


class ShowHelpScreenCommand : public Command {
public:
	ShowHelpScreenCommand(Game *game);
	bool execute();
	
private:
	Game *game;
};


#endif 
