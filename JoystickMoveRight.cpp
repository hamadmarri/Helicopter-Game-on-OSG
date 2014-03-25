

#include "JoystickMoveRight.h"


JoystickMoveRight::JoystickMoveRight(Joystick *joystick) {
	this->joystick = joystick;
}



bool JoystickMoveRight::execute() {
	this->joystick->set_theta(15.0);
	this->joystick->set_phi(270.0);
	
	return true;
}