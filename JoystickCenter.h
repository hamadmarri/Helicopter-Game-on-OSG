//	See main.cpp file header for credits

#ifndef __HelicopterProject__JoystickCenter__
#define __HelicopterProject__JoystickCenter__

#include "Command.h"
#include "Joystick.h"


class JoystickCenter : public Command {
public:
	JoystickCenter(Joystick *joystick);
	bool execute();
	
private:
	Joystick *joystick;
};


#endif /* defined(__HelicopterProject__JoystickCenter__) */
