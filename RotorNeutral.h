

#ifndef __HelicopterProject__RotorNeutral__
#define __HelicopterProject__RotorNeutral__

#include "Command.h"
#include "Rotor.h"


class RotorNeutral : public Command {
public:
	RotorNeutral(Rotor *rotor);
	bool execute();
	
private:
	Rotor *rotor;
};

#endif /* defined(__HelicopterProject__RotorNeutral__) */
