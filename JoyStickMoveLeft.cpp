

#include "JoyStickMoveLeft.h"


JoystickMoveLeft::JoystickMoveLeft(Joystick *joystick) {
	this->joystick = joystick;
}



bool JoystickMoveLeft::execute() {
	this->joystick->set_theta(15.0);
	this->joystick->set_phi(90.0);
	
	return true;
}