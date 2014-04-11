//	See main.cpp file header for credits
//
//	created by Hamad Almarri
//

#include "DeactivateFrictionCommand.h"


DeactivateFrictionCommand::DeactivateFrictionCommand(Game *game) {
	this->game = game;
}



bool DeactivateFrictionCommand::execute() {
	this->game->getConfiguration()->deactivateFriction();
	return true;
}