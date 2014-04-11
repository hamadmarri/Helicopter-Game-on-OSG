//	See main.cpp file header for credits


#ifndef __HelicopterProject__StartLoggingCommand_h__
#define __HelicopterProject__StartLoggingCommand_h__

#include "Command.h"
#include "Game.h"


class StartLoggingCommand : public Command {
public:
	StartLoggingCommand(Game *game);
	bool execute();
	
private:
	Game *game;
};

#endif 
