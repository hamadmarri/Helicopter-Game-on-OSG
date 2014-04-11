//	See main.cpp file header for credits

#ifndef __HelicopterProject__JoystickMoveRight_h__
#define __HelicopterProject__JoystickMoveRight_h__

#include "Command.h"
#include "Joystick.h"


class JoystickMoveRight : public Command {
public:
	JoystickMoveRight(Joystick *joystick);
	bool execute();
	
private:
	Joystick *joystick;
};



#endif 
