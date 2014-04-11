//	See main.cpp file header for credits


#include "ShowHelpScreenCommand.h"


ShowHelpScreenCommand::ShowHelpScreenCommand(Game *game) {
	this->game = game;
}



bool ShowHelpScreenCommand::execute() {
	this->game->getPopupHelpScreen()->show();
	
	return true;
}