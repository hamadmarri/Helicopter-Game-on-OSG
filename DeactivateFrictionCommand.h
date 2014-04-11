//	See main.cpp file header for credits
//
//	created by Hamad Almarri
//

#ifndef __HelicopterProject__DeactivateFrictionCommand_h__
#define __HelicopterProject__DeactivateFrictionCommand_h__

#include "Command.h"
#include "Game.h"


class DeactivateFrictionCommand : public Command {
public:
	DeactivateFrictionCommand(Game *game);
	bool execute();
	
private:
	Game *game;
};

#endif
