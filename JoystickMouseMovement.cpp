//	See main.cpp file header for credits

#include "JoystickMouseMovement.h"


JoystickMouseMovement::JoystickMouseMovement(Game *game, Joystick *joystick, float xCartesian, float yCartesian) {
	this->game = game;
	this->joystick = joystick;
	this->xCartesian = (this->game->getConfiguration()->getScreenWidth() / 2) - xCartesian;
	this->yCartesian = (yCartesian - this->game->getConfiguration()->getScreenHeight() / 2);
}



bool JoystickMouseMovement::execute() {
	float magnitude = sqrt((float) (pow(this->xCartesian, 2.0) + pow(this->yCartesian, 2.0))) /
						  (this->game->getConfiguration()->getScreenHeight() / (2 * 15));
	
	this->joystick->set_theta(magnitude);
	this->joystick->set_phi(atan2(this->xCartesian, this->yCartesian) * 180 / WORLD_PI);

	return true;
}