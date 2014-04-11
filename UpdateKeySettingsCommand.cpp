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
	
	// delete old hudsManager and instanciate new one
	delete game->hudsManager;
	this->game->hudsManager = new HudsManager(game, 0);
	
	// re-initialize helicopter huds (in case changing missile from initial speed to fuel mode)
	this->game->getHelicopter()->initializeHuds();
	
	return true;
}