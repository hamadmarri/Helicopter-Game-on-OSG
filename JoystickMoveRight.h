

#ifndef __HelicopterProject__JoystickMoveRight__
#define __HelicopterProject__JoystickMoveRight__

#include "Command.h"
#include "Joystick.h"


class JoystickMoveRight : public Command {
public:
	JoystickMoveRight(Joystick *joystick);
	bool execute();
	
private:
	Joystick *joystick;
};



#endif /* defined(__HelicopterProject__JoystickMoveRight__) */
