//	See main.cpp file header for credits
//
//	created by Hamad Almarri
//

#ifndef __HelicopterProject__UpdateKeySettingsCommand_h__
#define __HelicopterProject__UpdateKeySettingsCommand_h__

#include "Command.h"
#include "Game.h"


class UpdateKeySettingsCommand : public Command {
public:
	UpdateKeySettingsCommand(Game *game);
	bool execute();
	
private:
	Game *game;
};


#endif 
