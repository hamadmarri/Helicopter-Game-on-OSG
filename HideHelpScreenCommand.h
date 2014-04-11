//	See main.cpp file header for credits
//
//	created by Hamad Almarri
//


#ifndef __HelicopterProject__HideHelpScreenCommand_h__
#define __HelicopterProject__HideHelpScreenCommand_h__

#include "Command.h"
#include "Game.h"


class HideHelpScreenCommand : public Command {
public:
	HideHelpScreenCommand(Game *game);
	bool execute();
	
private:
	Game *game;
};


#endif 
