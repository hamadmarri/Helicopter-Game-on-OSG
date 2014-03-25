

#include "JoyStickSetManually.h"


JoyStickSetManually::JoyStickSetManually(Joystick *joystick, float theta, float phi) {
	this->joystick = joystick;
	this->theta = theta;
	this->phi = phi;
}



bool JoyStickSetManually::execute() {
	this->joystick->set_theta(this->theta);
	this->joystick->set_phi(this->phi);
	
	return true;
}