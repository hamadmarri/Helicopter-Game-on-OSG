//	See main.cpp file header for credits
//
//	created by Hamad Almarri
//

#ifndef __HelicopterProject__ActivateFrictionCommand_h__
#define __HelicopterProject__ActivateFrictionCommand_h__

#include "Command.h"
#include "Game.h"


class ActivateFrictionCommand : public Command {
public:
	ActivateFrictionCommand(Game *game);
	bool execute();
	
private:
	Game *game;
};


#endif
