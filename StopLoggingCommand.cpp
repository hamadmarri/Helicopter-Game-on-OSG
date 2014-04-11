//	See main.cpp file header for credits


#include "StopLoggingCommand.h"


StopLoggingCommand::StopLoggingCommand(Game *game) {
	this->game = game;
}



bool StopLoggingCommand::execute() {
	this->game->logger->endLogging();
	return true;
}