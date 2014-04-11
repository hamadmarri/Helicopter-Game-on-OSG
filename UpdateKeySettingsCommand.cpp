//	See main.cpp file header for credits


#include "UpdateKeySettingsCommand.h"


UpdateKeySettingsCommand::UpdateKeySettingsCommand(Game *game) {
	this->game = game;
}



bool UpdateKeySettingsCommand::execute() {
	// re-initialize key settings
	this->game->getConfiguration()->initKeySettings();
	
	// re-initialize pop up help screen
	this->game->initializePopupHelpScreen();
	
	// re-initialize camera
	this->game->initializeCamera();
	
	// re initialize huds manager
	this->game->initializeHudsManager();
	
	// re-initialize helicopter huds (in case changing missile from initial speed to fuel mode)
	this->game->getHelicopter()->initializeHuds();
	
	return true;
}