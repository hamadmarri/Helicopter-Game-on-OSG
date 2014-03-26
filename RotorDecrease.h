//	See main.cpp file header for credits

#ifndef __HelicopterProject__RotorDecrease__
#define __HelicopterProject__RotorDecrease__

#include "Command.h"
#include "Rotor.h"


class RotorDecrease : public Command {
public:
	RotorDecrease(Rotor *rotor);
	bool execute();
	
private:
	Rotor *rotor;
};

#endif /* defined(__HelicopterProject__RotorDecrease__) */
