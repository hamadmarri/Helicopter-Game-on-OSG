//	See main.cpp file header for credits

#ifndef __HelicopterProject__JoystickMoveBackward_h__
#define __HelicopterProject__JoystickMoveBackward_h__

#include "Command.h"
#include "Joystick.h"


class JoystickMoveBackward : public Command {
public:
	JoystickMoveBackward(Joystick *joystick);
	bool execute();
	
private:
	Joystick *joystick;
};

#endif 
