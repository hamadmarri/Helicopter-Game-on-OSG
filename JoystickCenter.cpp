

#include "JoystickCenter.h"


JoystickCenter::JoystickCenter(Joystick *joystick) {
	this->joystick = joystick;
}



bool JoystickCenter::execute() {
	this->joystick->set_theta(0.0);
	this->joystick->set_phi(0.0);
	
	return true;
}