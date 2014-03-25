

#include "JoystickMoveBackward.h"


JoystickMoveBackward::JoystickMoveBackward(Joystick *joystick) {
	this->joystick = joystick;
}



bool JoystickMoveBackward::execute() {
	this->joystick->set_theta(15.0);
	this->joystick->set_phi(180.0);
	
	return true;
}