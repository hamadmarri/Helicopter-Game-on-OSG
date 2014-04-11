//	See main.cpp file header for credits
//
//	created by Hamad Almarri
//

#include "StopLoggingCommand.h"


StopLoggingCommand::StopLoggingCommand(Game *game) {
	this->game = game;
}



bool StopLoggingCommand::execute() {
	this->game->getLogger()->endLogging();
	return true;
}