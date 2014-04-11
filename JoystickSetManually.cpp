//	See main.cpp file header for credits

#include "JoystickSetManually.h"


JoystickSetManually::JoystickSetManually(Joystick *joystick, float theta, float phi) {
	this->joystick = joystick;
	this->theta = theta;
	this->phi = phi;
}



bool JoystickSetManually::execute() {
	this->joystick->set_theta(this->theta);
	this->joystick->set_phi(this->phi);
	
	return true;
}