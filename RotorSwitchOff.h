

#ifndef __HelicopterProject__RotorSwitchOff__
#define __HelicopterProject__RotorSwitchOff__

#include "Command.h"
#include "Rotor.h"


class RotorSwitchOff : public Command {
public:
	RotorSwitchOff(Rotor *rotor);
	bool execute();
	
private:
	Rotor *rotor;
};

#endif /* defined(__HelicopterProject__RotorSwitchOff__) */
