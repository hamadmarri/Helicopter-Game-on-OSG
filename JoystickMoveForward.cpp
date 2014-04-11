//	See main.cpp file header for credits
//  This is the implementatioin of JoystickMoveForward class. It has two main functions, one function is a constructor to
/// set the joystick passed to it, and the second function is a boolean function to set the joystick theta to 15.0 and
//  to set the phi of the joystick to 0.0

#include "JoystickMoveForward.h"


// a constructor to set the joystick pointer
JoystickMoveForward::JoystickMoveForward(Joystick *joystick) {
	this->joystick = joystick;
}


// boolean function to take our passed pointer joystick and set it's theta to 15.0 and it's phi to 0.0
bool JoystickMoveForward::execute() {
	this->joystick->set_theta(15.0);
	this->joystick->set_phi(0.0);

	return true;
}