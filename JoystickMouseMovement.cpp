//	See main.cpp file header for credits

#include "JoystickMouseMovement.h"


JoystickMouseMovement::JoystickMouseMovement(Joystick *joystick, float xCartesian, float yCartesian) {
	this->joystick = joystick;
	this->xCartesian = (Configuration::getScreenWidth() / 2) - xCartesian;
	this->yCartesian = (Configuration::getScreenHeight() / 2) - yCartesian;
}



bool JoystickMouseMovement::execute() {
	float magnitude = int(sqrt((float) (pow(this->xCartesian, 2.0) + pow(this->yCartesian, 2.0))) / 100) % 15;
	
	this->joystick->set_theta(magnitude);
	this->joystick->set_phi(atan2(this->xCartesian, -1 * this->yCartesian) * 180 / WORLD_PI);

	return true;
}