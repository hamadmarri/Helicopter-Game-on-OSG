//	See main.cpp file header for credits

// RotorPercentage class. The main purpose of this class is to set any value to the rotor percentage and update
// the percentage from that value.
// RotorPercentage class inherites from Command classs public.
//
//	created by Hamad Almarri
//	modified by Fares Alotaibi
//


#ifndef __HelicopterProject__RotorPercentage_h__
#define __HelicopterProject__RotorPercentage_h__

#include "Command.h"
#include "Rotor.h"


class RotorPercentage : public Command {
public:
	RotorPercentage(Rotor *rotor, float percentage);   // constructor passing two parameters float, and rotor
	bool execute();                                     // boolean function
	
private:                    // two private parameters 
	Rotor *rotor;
	float percentage;
};

#endif 
