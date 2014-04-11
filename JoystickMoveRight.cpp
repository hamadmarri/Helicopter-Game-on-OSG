//	See main.cpp file header for credits
//  This is the implementation of joystickMoveRight class. Two main functions, a constructor to pass the joystick pointer and
//  a boolean function to set the joystick theta to 15, and the joystick phi to 270.

#include "JoystickMoveRight.h"

// a constructor passing a pointer from a Joystick
JoystickMoveRight::JoystickMoveRight(Joystick *joystick) {
	this->joystick = joystick;
}


// a boolean funciton to execute the joystick theta, and the joystick phi 
bool JoystickMoveRight::execute() {
	this->joystick->set_theta(15.0);
	this->joystick->set_phi(270.0);
	
	return true;
}