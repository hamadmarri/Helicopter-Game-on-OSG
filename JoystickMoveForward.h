//	See main.cpp file header for credits
//  JoystickMoveForward class inheritance public from Command class. The main purpose of this class is to set the
//  joystick theta to 15.0 degree and set the phi of the joystick to 0.0.

#ifndef __HelicopterProject__JoystickMoveForward_h__
#define __HelicopterProject__JoystickMoveForward_h__

#include "Command.h"
#include "Joystick.h"

// public inheritance from Command class
class JoystickMoveForward : public Command {
public:
	JoystickMoveForward(Joystick *joystick);            // a constructor to set the joystick
	bool execute();                                     // boolean function to execute the joystick theta, and phi
	
private:                                                // one private member pointer from a Joystick 
	Joystick *joystick;
};


#endif 
