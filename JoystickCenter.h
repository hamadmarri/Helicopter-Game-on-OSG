//	See main.cpp file header for credits

#ifndef __HelicopterProject__JoystickCenter_h__
#define __HelicopterProject__JoystickCenter_h__

#include "Command.h"
#include "Joystick.h"


class JoystickCenter : public Command {
public:
	JoystickCenter(Joystick *joystick);
	bool execute();
	
private:
	Joystick *joystick;
};


#endif 
