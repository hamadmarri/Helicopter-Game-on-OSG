

#include "JoystickMoveForward.h"



JoystickMoveForward::JoystickMoveForward(Joystick *joystick) {
	this->joystick = joystick;
}



bool JoystickMoveForward::execute() {
	this->joystick->set_theta(15.0);
	this->joystick->set_phi(0.0);

	return true;
}