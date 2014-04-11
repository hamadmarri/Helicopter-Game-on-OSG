//	See main.cpp file header for credits
//
//	created by Hamad Almarri
//

#include "StartLoggingCommand.h"


StartLoggingCommand::StartLoggingCommand(Game *game) {
	this->game = game;
}



bool StartLoggingCommand::execute() {
	this->game->getLogger()->startLogging();
	return true;
}