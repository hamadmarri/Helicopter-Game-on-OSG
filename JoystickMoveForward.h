//	See main.cpp file header for credits

#ifndef __HelicopterProject__JoystickMoveForward_h__
#define __HelicopterProject__JoystickMoveForward_h__

#include "Command.h"
#include "Joystick.h"


class JoystickMoveForward : public Command {
public:
	JoystickMoveForward(Joystick *joystick);
	bool execute();
	
private:
	Joystick *joystick;
};


#endif 
