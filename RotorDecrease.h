//	See main.cpp file header for credits
// RotorDecrease class inhertance from Command class public. The main puropose of this class is to call
// decreaseMagnitude function of a rotor class and set a passing rotor in the constructor to do that.
// Two main funcitons in the class, a consturctor to pass a rotor instance and a boolean function to
// call decrease function of our passing rotor instance from the constructor.

#ifndef __HelicopterProject__RotorDecrease__
#define __HelicopterProject__RotorDecrease__

#include "Command.h"
#include "Rotor.h"

// inhertance public from Command class
class RotorDecrease : public Command {
public:
	RotorDecrease(Rotor *rotor);            // a consturctor passsing an instance of rotor
	bool execute();                         // a boolean function
	
private:                                    // one private member of rotor 
	Rotor *rotor;
};

#endif /* defined(__HelicopterProject__RotorDecrease__) */
