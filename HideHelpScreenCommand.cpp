//	See main.cpp file header for credits


#include "HideHelpScreenCommand.h"


HideHelpScreenCommand::HideHelpScreenCommand(Game *game) {
	this->game = game;
}



bool HideHelpScreenCommand::execute() {
	this->game->getPopupHelpScreen()->hide();
	
	return true;
}