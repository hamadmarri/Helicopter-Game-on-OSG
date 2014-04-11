//	See main.cpp file header for credits

#ifndef __HelicopterProject__JoyStickSetManually__
#define __HelicopterProject__JoyStickSetManually__

#include "Command.h"
#include "Joystick.h"
#include "Configuration.h"


class JoyStickSetManually : public Command {
public:
	JoyStickSetManually(Joystick *joystick, float theta, float phi);
	virtual bool execute();
	
private:
	Joystick *joystick;
	float theta;
	float phi;
};


#endif /* defined(__HelicopterProject__JoyStickSetManually__) */
