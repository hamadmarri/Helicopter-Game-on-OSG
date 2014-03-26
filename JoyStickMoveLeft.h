//	See main.cpp file header for credits

#ifndef __HelicopterProject__MoveLeft__
#define __HelicopterProject__MoveLeft__

#include "Command.h"
#include "Joystick.h"


class JoystickMoveLeft : public Command {
public:
	JoystickMoveLeft(Joystick *joystick);
	bool execute();
	
private:
	Joystick *joystick;
};

#endif /* defined(__HelicopterProject__MoveLeft__) */
