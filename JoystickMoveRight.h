//	See main.cpp file header for credits
//  This is JoystickMoveRight class. The main pourpose of the calss is to the joystick theat to 15 degree, and
// to set the phi to 270. The class inheritance public from a Command class.

#ifndef __HelicopterProject__JoystickMoveRight_h__
#define __HelicopterProject__JoystickMoveRight_h__

#include "Command.h"
#include "Joystick.h"

// inhertitance public from Command class
class JoystickMoveRight : public Command {
public:
	JoystickMoveRight(Joystick *joystick);      // a constructor passing a pointer from a joystick
	bool execute();                             // execute function to set the theat,phi
	
private:                // one private member pointe of a joystick 
	Joystick *joystick;
};



#endif 
