//	See main.cpp file header for credits

#ifndef __HelicopterProject__JoystickMoveLeft_h__
#define __HelicopterProject__JoystickMoveLeft_h__

#include "Command.h"
#include "Joystick.h"


class JoystickMoveLeft : public Command {
public:
	JoystickMoveLeft(Joystick *joystick);
	bool execute();
	
private:
	Joystick *joystick;
};

#endif