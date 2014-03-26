//	See main.cpp file header for credits

#ifndef __HelicopterProject__RotorIncrease__
#define __HelicopterProject__RotorIncrease__

#include "Command.h"
#include "Rotor.h"


class RotorIncrease : public Command {
public:
	RotorIncrease(Rotor *rotor);
	bool execute();
	
private:
	Rotor *rotor;
};

#endif /* defined(__HelicopterProject__RotorIncrease__) */
