//	See main.cpp file header for credits


#ifndef __HelicopterProject__StopLoggingCommand_h__
#define __HelicopterProject__StopLoggingCommand_h__

#include "Command.h"
#include "Game.h"


class StopLoggingCommand : public Command {
public:
	StopLoggingCommand(Game *game);
	bool execute();
	
private:
	Game *game;
};


#endif
