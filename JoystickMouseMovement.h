//	See main.cpp file header for credits

#ifndef __HelicopterProject__JoystickMouseMovement__
#define __HelicopterProject__JoystickMouseMovement__

#include "Command.h"
#include "Joystick.h"
#include "Configuration.h"


class JoystickMouseMovement : public Command {
public:
	JoystickMouseMovement(Joystick *joystick, float xCartesian, float yCartesian);
	virtual bool execute();
	
private:
	Joystick *joystick;
	float xCartesian;
	float yCartesian;
};


#endif /* defined(__HelicopterProject__JoystickMouseMovement__) */
