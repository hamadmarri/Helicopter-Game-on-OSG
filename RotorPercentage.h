//	See main.cpp file header for credits

#ifndef __HelicopterProject__RotorPercentage__
#define __HelicopterProject__RotorPercentage__

#include "Command.h"
#include "Rotor.h"


class RotorPercentage : public Command {
public:
	RotorPercentage(Rotor *rotor, float percentage);
	bool execute();
	
private:
	Rotor *rotor;
	float percentage;
};

#endif /* defined(__HelicopterProject__RotorPercentage__) */
