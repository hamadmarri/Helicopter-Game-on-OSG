//	See main.cpp file header for credits

#ifndef __HelicopterProject__JoystickSetManually_h__
#define __HelicopterProject__JoystickSetManually_h__

#include "Command.h"
#include "Joystick.h"
#include "Configuration.h"


class JoystickSetManually : public Command {
public:
	JoystickSetManually(Joystick *joystick, float theta, float phi);
	virtual bool execute();
	
private:
	Joystick *joystick;
	float theta;
	float phi;
};


#endif
