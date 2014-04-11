
#include "ActivateFrictionCommand.h"



ActivateFrictionCommand::ActivateFrictionCommand(Game *game) {
	this->game = game;
}



bool ActivateFrictionCommand::execute() {
	this->game->getConfiguration()->activateFriction();
	return true;
}