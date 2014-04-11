//	See main.cpp file header for credits
// This is the implementation of the JoystickMoveBackward class. It has two main functions, one constructor to set the joystick
// and the second funciton is to execute the joystick theta to 15 and the joystick phi to 180.

#include "JoystickMoveBackward.h"

// a constructor to set the joystick
JoystickMoveBackward::JoystickMoveBackward(Joystick *joystick) {
	this->joystick = joystick;
}


// a boolean function to execute the joystick theta to 15.0 , and the joystick phi to 180 
bool JoystickMoveBackward::execute() {
	this->joystick->set_theta(15.0);
	this->joystick->set_phi(180.0);
	
	return true;
}