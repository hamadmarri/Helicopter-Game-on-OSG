
#ifndef __HelicopterProject__RotorSetMagnitude__
#define __HelicopterProject__RotorSetMagnitude__

#include "Command.h"
#include "Rotor.h"


class RotorSetMagnitude : public Command {
public:
	RotorSetMagnitude(Rotor *rotor, float magnitude);
	bool execute();
	
private:
	Rotor *rotor;
	float magnitude;
};

#endif /* defined(__HelicopterProject__RotorSetMagnitude__) */
