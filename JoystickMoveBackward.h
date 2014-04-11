//	See main.cpp file header for credits
//  JoystickMoveBackward class inhertitance from a Command class public. The main purpose of this class is to
//  set the joystick theta to 15 and the joystick phi to 180, once a function called executed called.

#ifndef __HelicopterProject__JoystickMoveBackward_h__
#define __HelicopterProject__JoystickMoveBackward_h__

#include "Command.h"
#include "Joystick.h"

// public inheritance from Command class
class JoystickMoveBackward : public Command {
public:
	JoystickMoveBackward(Joystick *joystick);           // a constructor passing a pointer of a joystick to set it
	bool execute();                                     // execute function to set the theta and the phi of the joystick
	
private:                                                // one private member pointer of a joystick 
	Joystick *joystick;
};

#endif 
