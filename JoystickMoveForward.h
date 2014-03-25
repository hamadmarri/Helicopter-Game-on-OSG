

#ifndef __HelicopterProject__JoystickMoveForward__
#define __HelicopterProject__JoystickMoveForward__

#include "Command.h"
#include "Joystick.h"


class JoystickMoveForward : public Command {
public:
	JoystickMoveForward(Joystick *joystick);
	bool execute();
	
private:
	Joystick *joystick;
};


#endif /* defined(__HelicopterProject__JoystickMoveForward__) */
